#ifndef MAIN_SAVE_SAVE_H_
#define MAIN_SAVE_SAVE_H_



// ������� ���������� ������� ����������� �� ����� SD
// (������ CSV, ����������� �������� - �������)
int save_ImageCSV(void);
// ������� ���������� �������� ����� ������� �� ����� SD
// (16 ������ ������ BMP, ���������� �������� ��� ������ 15)
int save_ImageBMP_15bit(void);
// ������� ���������� �������� ����� ������� �� ����� SD
// (24 (32) ������ ������ BMP, ���������� �������� ��� ������ 16)
int save_ImageBMP_24bit(void);

#endif /* MAIN_SAVE_SAVE_H_ */
