#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


#include"game.h"//������ʹ��game.hͷ�ļ�����Ķ���


void game()
{
	char mine[ROWS][COLS] = { 0 };//��ȡ���ú��׵���Ϣ������
	char show[ROWS][COLS] = { 0 };//��ȡչʾ���û�����Ϣ������
	Init_board(mine, ROWS, COLS, '0');//��ʼ��mine��
	Init_board(show, ROWS, COLS, '*');//��ʼ��show�̣�ȫ����*������ʱ�ٽ��������滻
	Set_mine(mine, ROW, COL, EASY_COUNT);//����
	Display_board(show, ROW, COL);//չʾ��չʾ�̡�
	Finf_mine(mine, show, ROWS, COLS);//��ʼɨ��
}




void test()
{
	srand(time(NULL));//���������
	int input = 0;//�����롱����

	do
	{
		menu();
		printf("������->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		}
	} while (input);

}






int main()
{
	test();
	return 0;
}