#ifndef MAIN_ILI9341_H_
#define MAIN_ILI9341_H_

#include "driver/spi_master.h"


#define ILI9341_DIRECT_MODE		0	// ����� ������� ��������� � ������� (��� ������ �����)
#define ILI9341_BUFFER_MODE		1	// ����� �������� ��������� � ����� ����� ��� ����������� �������� � �������

#define ILI9341_MODE			ILI9341_BUFFER_MODE


//#define TTGO_V12	// ������� ����� TTGO v1.2
#define TTGO_V13	// ������� ����� TTGO v1.3

#ifdef TTGO_V12
#define PIN_MISO 	12
#define PIN_MOSI 	23//25 //23
#define PIN_CLK  	18//19 //18
#define PIN_CS   	27
#define PIN_DC   	26
#define PIN_RST  	5
//#define PIN_BL		4	// ���������� ����������
#endif

#ifdef TTGO_V13
#define PIN_MISO 	12
#define PIN_MOSI 	23
#define PIN_CLK  	18
#define PIN_CS   	27
#define PIN_DC   	26//32
#define PIN_RST  	5
#define PIN_BL		4	// ���������� ����������
#endif


#define ILI9341_TFTWIDTH   240      ///< ILI9341 max TFT width
#define ILI9341_TFTHEIGHT  320      ///< ILI9341 max TFT height

// ��������� ������������� �������
void ili9341_init(uint16_t width, uint16_t height);
// ��������� ���������� ����������
void ili9341_SetBL(uint8_t value);
// ��������� ���������� 1 ������� �������
void ili9341_DrawPixel(int16_t x, int16_t y, uint16_t color);
// ��������� ���������� ���� �������
uint16_t ili9341_GetPixel(int16_t x, int16_t y);
// ��������� ���������� �������������� ������ color
void ili9341_FillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

#if (ILI9341_MODE == ILI9341_BUFFER_MODE)
// ��������� ��������� ������� �� ������ �����
void ili9341_update(void);
// ��������� �������� ����� ����� � ����� pBuff
void ili9341_getScreenData(uint16_t *pBuff);
#endif

#endif /* MAIN_ILI9341_H_ */
