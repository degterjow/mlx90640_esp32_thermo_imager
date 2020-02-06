#ifndef MAIN_CONSOLE_CONSOLE_H_
#define MAIN_CONSOLE_CONSOLE_H_

typedef enum
{
	MsgInfo = 0,
	MsgWarning = 1,
	MsgError = 2
}
eConsoleMsgType;



// ��������� ������ ����� � ������ �������
void console_pause(uint32_t timeMs);
// ��������� ��������� ����� ������ � �������
void console_printf(eConsoleMsgType msgType, const char *args, ...);
// ��������� ������� ��������� � ������������ � ������� � ������������� esp32
void FatalError();
// ��������� ������� ��������� �� ������ � � ������������ � ������� � ������������� esp32
void FatalErrorMsg(const char *args, ...);


#endif /* MAIN_CONSOLE_CONSOLE_H_ */
