#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//�˵����棬�����֪������ʲô���Խ�����Ϸ������ʲô�˳���Ϸ
void menu()
{
	printf("***********************\n");
	printf("*******  1.play  ******\n");
	printf("*******  0.exit  ******\n");
	printf("***********************\n");
}

//��ʼ������
void Init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;//����֪��set��ʲô
		}
	}
}

//չʾ����,���ܰ����̴�ӡ����
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


//���׺���:���������������Ϊ�к��е���
//����λ���ϵ���0�������ȥһ������һ��ָʾ���ͼ���һ����һ��10��
void Set_mine(char mine[ROWS][COLS],int row,int col,int count)//count�����������׵�����
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

//ɨ�׺���
void Finf_mine(char mine[ROWS][COLS],char show[ROWS][COLS],int rows,int cols)
{
	int x = 0;
	int y = 0;
	int win = 0;//Ŀǰ��֪��win�����

	while(win < (rows - 2) * (cols - 2) - EASY_COUNT)
	//while��������ŵ����壺���ǵ�����ɨ��ȫ�����׺������ѭ����ͨ�������if���������ж��Ƿ�����ȫɨ�꣬���ɨ������ɨ�׳ɹ���
	{
		printf(" ��������Ҫ�Ų��Ŀ������\n");
		scanf("%d %d", &x, &y);

		if (x > ROW || x<0 || y>COL || y < 0)
		{
			printf("�����������������\n");
		}
		else
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը����\n");
				Display_board(mine, ROW, COL);//�㱻ը����չʾȫ�̣��������׶�����
				break;
			}
			else
			{
				show[x][y] = count_num(mine, x, y) + '0';
				Display_board(show, ROW, COL);
				win++;//�ҵ�һ����win�ͼ�һ����win����10�ͼ��������ң�ѭ��������win==10 ʱ��˵���������ˣ��Ϳ��Խ�����
			}
		}
	}
	if (win == (rows - 2) * (cols - 2) - EASY_COUNT)
	{
		printf("���׳ɹ�\n");
	}
}

static int count_num(char mine[ROWS][COLS], int x, int y)//���Ǽ���õ���Χ���м����׵ĺ���
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x + 1][y] +
	mine[x + 1][y - 1] + mine[x + 1][y + 1] + mine[x - 1][y + 1] + 
	mine[x][y + 1] + mine[x][y - 1] - 8 * '0';
	
	//����Ϊʲô��Ҫ��ȥ�ַ�0�أ�
	//��Ϊ�����ڿ�������ʱ����������������ַ��ͣ�
	//�˴�ͨ������õ������������ͣ�
	//��ȥ��0��֮��õ������ݼ�Ϊ�ַ���������Ӧ�����ͣ�
	//�������Ҫչʾ������ʱ���ϡ�0����
	//Ҳ��Ϊ�˽���������ת��Ϊ�ַ��ͣ�������������С�
}