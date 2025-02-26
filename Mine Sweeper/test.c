#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


#include"game.h"//声明能使用game.h头文件里面的东西


void game()
{
	char mine[ROWS][COLS] = { 0 };//存取放置好雷的信息的雷盘
	char show[ROWS][COLS] = { 0 };//存取展示给用户的信息的雷盘
	Init_board(mine, ROWS, COLS, '0');//初始换mine盘
	Init_board(show, ROWS, COLS, '*');//初始化show盘，全盖上*，查找时再进行数字替换
	Set_mine(mine, ROW, COL, EASY_COUNT);//埋雷
	Display_board(show, ROW, COL);//展示“展示盘”
	Finf_mine(mine, show, ROWS, COLS);//开始扫雷
}




void test()
{
	srand(time(NULL));//随机数种子
	int input = 0;//“输入”变量

	do
	{
		menu();
		printf("请输入->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		}
	} while (input);

}






int main()
{
	test();
	return 0;
}