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
		printf("�����֣�");
		scanf("%d", &i);
		if (i > ret)
			printf("�´��ˣ�\n");
		else if (i < ret)
			printf("��С�ˣ�\n");
		else
		{	printf("�¶��ˣ���\n");
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
		printf("��ѡ��");
		scanf("%d", &i);
		switch (i)
		{
		case 1:game(); break;
		case 0:printf("�˳��ɹ���"); break;
		default:printf("ѡ���������������.\n"); break;
		}
	} while (i);
	
	return 0;
}