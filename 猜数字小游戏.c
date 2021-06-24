#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void game()
{
	int ret = rand()%100+1;
	int i = 0;
	while (1)
	{
		printf("猜数字：");
		scanf("%d", &i);
		if (i > ret)
			printf("猜大了！\n");
		else if (i < ret)
			printf("猜小了！\n");
		else
		{	printf("猜对了！！\n");
		break;
	}
	}

	}


void menu()
{
	printf("***************************\n");
	printf("*******  1.Play  **********\n");
	printf("*******  0.Exit  **********\n");
	printf("***************************\n");
}
int main()
{
	int i=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &i);
		switch (i)
		{
		case 1:game(); break;
		case 0:printf("退出成功！"); break;
		default:printf("选择错误，请重新输入.\n"); break;
		}
	} while (i);
	
	return 0;
}