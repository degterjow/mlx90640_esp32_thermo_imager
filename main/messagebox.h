#ifndef MAIN_CONSOLE_MESSAGEBOX_H_
#define MAIN_CONSOLE_MESSAGEBOX_H_




// ��������� ������� ��������� �� ������ ������
void message_show(uint16_t width, uint8_t ItemFont, char *pTitle, char *pMessage, uint16_t lineColor, uint8_t darkBg, uint16_t delay_ms);
// ��������� ������� ���� � ���������� � ������� ����������� ���� ���������� ��������
void progress_show(uint16_t width, uint8_t ItemFont, char *pTitle, char *pMessage, uint16_t progressColor, uint16_t progressValue, uint16_t progressMax);
// ��������� ������� ���� � ����������
void progress_start_show(uint16_t width, uint8_t ItemFont, char *pTitle, char *pMessage, uint16_t progressColor, uint16_t progressValue, uint16_t progressMax);


#endif /* MAIN_CONSOLE_MESSAGEBOX_H_ */
