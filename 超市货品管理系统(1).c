#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#define N 100

int num[N][20], sum[N], price[N];
	char name[N][20];
void menu()
{
	printf("\t\t======================================================\n");
	printf("\t\t||             ��ӭ��ʹ�ó��л�Ʒ����ϵͳ           ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||          *           ���ܲ˵�            *       ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||                  1.�»��ϼ�                      ||\n");
	printf("\t\t||                  2.��Ʒ����                      ||\n");
	printf("\t\t||                  3.��Ʒ��ѯ                      ||\n");
	printf("\t\t||                  4.��Ʒ�¼�                      ||\n");
	printf("\t\t||                  5.��Ʒ����                      ||\n");
	printf("\t\t||                  6.ͳ�ƹ���                      ||\n");
	printf("\t\t||                  7.�˳�                          ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||           ��ѡ������Ҫ�Ĺ��ܣ����س�������       ||\n");
	printf("\t\t======================================================\n");
}

void my_input()//����ظ����⻹δ���
{
	int i, j=0,n;
	printf("������Ҫ�ϼܵ���Ʒ���������");
	scanf("%d", &n);
	for (i = 0; i <= n - 1; i++)
	{
		printf("�������%d����Ʒ�����ƣ�", i + 1);
		scanf("%s", name[i]);
		printf("�������%d����Ʒ��ţ�", i + 1);
		scanf("%d", num[i]);
		printf("�������%d����Ʒ�ϼܵ���Ŀ��", i+1);
		scanf("%d", &sum[i]);
		printf("�������%d����Ʒ���ۣ�", i+1);
		scanf("%d", &price[i]);
		printf("\n");
	}
}

void my_budan()//δ�ҵ���Ʒ����������ѭ��δ���
{
	int a = 0, i;
	printf("��������Ҫ������Ʒ��ţ�\n");
	scanf("%d", &a);
	for (i = 0; *num[i] != '\0'; i++)
	{
		if (a == *num[i])
		{
			a = i;
			break;
		}
	}
	if (a != i)
	{
		printf("������˼û�ҵ��˻�Ʒ��");
		printf("\n");
		return 0;
	}
	else
		printf("��������Ҫ���ĵ�����");
		scanf("%d", &i);
		*(sum + a) = *(sum + a) + i;
		printf("������û�Ʒ�Ŀ������Ϊ��%d", *(sum+a));
		printf("\n");
}

void tongji()
{
	printf("������Ҫͳ�ƵĻ�Ʒ���ƻ��ţ�\n");
	printf("\n");
}

int main()
{
	
	int x,n=1;
	while (n)
	{
		menu();
		printf("\t\t>>>��ѡ����Ҫʹ�õĹ������1--6:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			my_input();//�»��ϼ�
			break;
		case 2:
			my_budan();//��Ʒ�������޸Ļ�Ʒ������
			break;
		case 3:
			printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 4:
			printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 5:printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 6:
			printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 7:n=0;
			break;
		default:
			printf("\t\t-----------------ѡ�����������---------------------\n");
			break;
		}
	}
		printf("\n");
	printf("\t\t-----------------��л��ʹ�ñ�ϵͳ---------------------\n");
	printf("\t\t******************************************************\n");
}