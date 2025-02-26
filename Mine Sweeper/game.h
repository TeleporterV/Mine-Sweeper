#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9//雷盘内部能点的区域横竖长度为9
#define COL 9
#define ROWS ROW+2//雷盘一共横竖长度为11
#define COLS COL+2

#define EASY_COUNT 10


void menu();
void game();
void Init_board(char board[ROWS][COLS], int rows, int cols, char ch);
void Display_board(char board[ROWS][COLS], int row, int col);
void Set_mine(char mine[ROWS][COLS], int row, int col, int count);
void Finf_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols);
