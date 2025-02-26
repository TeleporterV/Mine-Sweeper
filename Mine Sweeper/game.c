#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//菜单界面，让玩家知道输入什么可以进入游戏，输入什么退出游戏
void menu()
{
	printf("***********************\n");
	printf("*******  1.play  ******\n");
	printf("*******  0.exit  ******\n");
	printf("***********************\n");
}

//初始化函数
void Init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;//还不知道set是什么
		}
	}
}

//展示函数,这能把雷盘打印出来
void Display_board(char board[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}


//埋雷函数:引入两个随机数作为行和列的数
//若此位置上的是0，就埋进去一个，埋一个指示数就减少一个，一共10个
void Set_mine(char mine[ROWS][COLS],int row,int col,int count)//count是我们想埋雷的数量
{
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//扫雷函数
void Finf_mine(char mine[ROWS][COLS],char show[ROWS][COLS],int rows,int cols)
{
	int x = 0;
	int y = 0;
	int win = 0;//目前不知道win干嘛的

	while(win < (rows - 2) * (cols - 2) - EASY_COUNT)
	//while后面的括号的意义：就是当我们扫完全部的雷后就跳出循环并通过后面的if条件进行判断是否将雷完全扫完，如果扫完就输出扫雷成功。
	{
		printf(" 请输入你要排查的目标坐标\n");
		scanf("%d %d", &x, &y);

		if (x > ROW || x<0 || y>COL || y < 0)
		{
			printf("输入错误，请重新输入\n");
		}
		else
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				Display_board(mine, ROW, COL);//你被炸死后展示全盘，告诉你雷都在哪
				break;
			}
			else
			{
				show[x][y] = count_num(mine, x, y) + '0';
				Display_board(show, ROW, COL);
				win++;//找到一个雷win就加一个，win不到10就继续让你找（循环），当win==10 时就说明你找完了，就可以结束了
			}
		}
	}
	if (win == (rows - 2) * (cols - 2) - EASY_COUNT)
	{
		printf("排雷成功\n");
	}
}

static int count_num(char mine[ROWS][COLS], int x, int y)//这是计算该点周围还有几个雷的函数
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x + 1][y] +
	mine[x + 1][y - 1] + mine[x + 1][y + 1] + mine[x - 1][y + 1] + 
	mine[x][y + 1] + mine[x][y - 1] - 8 * '0';
	
	//至于为什么需要减去字符0呢？
	//因为我们在开辟雷盘时定义的数据类型是字符型，
	//此处通过计算得到的数据是整型，
	//减去‘0’之后得到的数据即为字符型真正对应的整型，
	//后面存入要展示的雷盘时加上‘0’，
	//也是为了将其由整型转换为字符型，方便存入雷盘中。
}