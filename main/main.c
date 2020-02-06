#include <stdio.h>
#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_spi_flash.h>
#include <esp_spiram.h>
#include "mlx90640/mlx90640_api.h"
#include "console/console.h"
#include "display/dispcolor.h"
#include "adc/adc.h"
#include "save/sd.h"
#include "settings.h"
#include "task_buttons.h"
#include "task_mlx.h"
#include "task_ui.h"
#include "main.h"


//==============================================================================
void app_main()
{
	// ������������� �������
    dispcolor_Init(dispWidth, dispHeight);
    dispcolor_SetBrightness(50);

    // ����� ����� ���������� � CPU
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    console_printf(MsgInfo, "ESP32 rev. %d (%d CPU cores, WiFi%s%s), ", chip_info.revision, chip_info.cores, (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "", (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
    console_printf(MsgInfo, " %d MB %s SPI FLASH\n", spi_flash_get_chip_size() / (1024 * 1024), (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
    console_printf(MsgInfo, " %d MB SPI PSRAM\n", esp_spiram_get_size() / (1024 * 1024));
    console_pause(300);

    // ������������� ���
    init_adc();
    uint32_t BatteryVoltage = getBatteryVoltage();
    console_printf(MsgInfo, " VBAT=%d mV\n", BatteryVoltage);
    console_pause(100);

    Frame = heap_caps_malloc(834 << 1, MALLOC_CAP_8BIT | MALLOC_CAP_INTERNAL);
    if (!Frame)
		FatalError("������ ��������� ��� ��� ������ ������ MLX\r\n");

	// ������ ��� ���������� ���������������, ��������� � ��������� �����������
    if (AllocThermoImageBuffers())
		FatalError("������ ��������� ��� ��� ����������������� �����������\r\n");

    if (AllocPaletteImageBuffer())
		FatalError("������ ��������� ��� ��� �������� �������\r\n");

    console_printf(MsgInfo, "SD init...\r\n");

    int initError = sd_CardInit();
    if (!initError)
    {
    	console_printf(MsgInfo, " SD found \r\n");

    	uint32_t FreeMb, TotalMb;
    	int8_t err = sd_GetFree(&FreeMb, &TotalMb);
    	if (!err)
        	console_printf(MsgInfo, "�������� %d �� �� %d ��\r\n", FreeMb, TotalMb);
    }
    else
    	console_printf(MsgWarning, " SD not found!\r\n");

	// ������������� Melexis mlx90640
    MLX90640_Init();

    console_printf(MsgInfo, "Read setup...\r\n");
    int err = settings_storage_init();
    settings_read_all();
    if (err)
    	console_printf(MsgWarning, " Error reading setup!\r\n");
    else
    	console_printf(MsgInfo, " Setup read successful\r\n");

    console_printf(MsgInfo, "Free RAM:\r\n");
    console_printf(MsgInfo, " Internal RAM: %d KB\r\n", heap_caps_get_free_size(MALLOC_CAP_INTERNAL) / 1024);
    console_printf(MsgInfo, " External RAM: %d KB\r\n", heap_caps_get_free_size(MALLOC_CAP_SPIRAM) / 1024);

    buttons_init();
    console_pause(200);

    console_printf(MsgInfo, "Init OK\r\n");
    console_pause(500);

    dispcolor_SetBrightness(LcdBrightness);

    xTaskCreatePinnedToCore(ui_task, "UI", 6000, NULL, 5, NULL, 0);
    xTaskCreatePinnedToCore(mlx_task, "MLX", 8000, NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(buttons_task, "BUTTONS", 1024, NULL, 6, NULL, 1);

    while (1)
    {
    	vTaskDelay(10000 / portTICK_RATE_MS);
    }
}
//==============================================================================
