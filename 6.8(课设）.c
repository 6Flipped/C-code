#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"keshe.h"
#define N 2000
int o;//���ܱ��

struct goods
{
	char name[20];
	int num;
	int sum;
	int price;
}goods[N], * p1;

int main()
{
	int y=0,x, n = 1;
	p1 = goods;
	printf("��ǰ���ϼ���Ʒ������Ϣ���£�\n");
	load();
	while (n)
	{
		menu();
		printf("\t\t>>>��ѡ����Ҫʹ�õĹ������1--7:>");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			y = o;
			y = my_input(&y);//�»��ϼ�
			name_sort(p1);
			save(y);
			break;
		case 2:
			my_add(p1);//��Ʒ�������޸Ļ�Ʒ������
			save(y);
			break;
		case 3:
			/*my_search(p1);*///��Ʒ��Ϣ��ѯ
			break;
		case 4:
			printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 5:printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 6:
			printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 7:
			load();
			break;
		case 8:
		/*	save(&y);*/
			n = 0;
			break;
		default:
			printf("\t\t-----------------ѡ�����������---------------------\n"); n = 0;
			break;
		}
	}
	printf("\n");
	printf("\t\t-----------------��л��ʹ�ñ�ϵͳ---------------------\n");
	printf("\t\t******************************************************\n");
	return 0;
}

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
	printf("\t\t||                  5.���ۼ�¼                      ||\n");
	printf("\t\t||                  6.ͳ�ƹ���                      ||\n");
	printf("\t\t||                  7.��ѯ������Ϣ                  ||\n");
	printf("\t\t||                  8.�˳�                          ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||           ��ѡ������Ҫ�Ĺ��ܣ����س�������       ||\n");
	printf("\t\t======================================================\n");
}

int  my_input(int *a)//������Ʒ����
{
	int i,n,j;
	printf("��ǰ��������%d������.\n", o);
	printf("�����������ϼܵ���Ʒ�������:>");
	scanf("%d", &n);
	for (i = *a; i < *a + n; i++)
	{
		printf("������%d�Ż�Ʒ����:>", i + 1);
		scanf("%s", goods[i].name);
		printf("������%d�Ż�Ʒ���:>", i + 1);
		scanf("%d", &goods[i].num);
		j=my_chachong(goods[i].num,i);
		if (j == -1)
		{
			printf("�ñ���Ѵ��ڣ���ȷ�Ϻ����룡����\n");
			break;
		}
		printf("������%d�Ż�Ʒ�ϼ�����:>", i + 1);
		scanf("%d", &goods[i].sum);
		printf("������%d�Ż�Ʒ����:>", i + 1);
		scanf("%d", &goods[i].price);
		printf("\n");
	}
	return i;
}

void save(int a)//���ݱ��浽�ļ�
{
	FILE* p = fopen("text.txt", "ab+");
	int i=0;
	if (p == NULL)
	{
		printf("Save:no this file");
		return;
	}
	for (i = o; i < a; i++)
	{
		fwrite(&goods[i], sizeof(struct goods), 1, p);
	}
	
	fclose(p);
	p = NULL;
}

void load()//���ļ��ж�ȡ����
{
	int i = 0;
	 o=0;
	FILE* p=fopen("text.txt","rb");
	if (p== NULL)
	{
		printf("Load:no this file");
		return;
	}
	printf("���ܺ�\t����\t���\t���\t����\n");
	while (fread(&goods[i], sizeof(struct goods), 1, p))
{
	printf("%d\t%s\t%d\t%d\t%d\n",o+1, goods[i].name, goods[i].num, goods[i].sum,goods[i].price);
	o++; i++;
}
	printf("\n");
	fclose(p);
	p = NULL;
}

int my_chachong(int a, int b)//��ѯ����Ƿ����
{
	int i;
	for (i = 0; i < b; i++)
	{
		if (goods[i].num == a)
			return -1;
}
	return 0;
}

void my_add(struct goods* p)
{
	int n, i, * p1;
	printf("������Ҫ������Ʒ���:>");
	scanf("%d", &n);
	for (i = 0; i < o; i++)
	{
		if ((p + i)->num == n)
		{
			printf("�ҵ��ˣ�����%s\n", (p + i)->name);
			break;
		}
	}
	if (i == o)
	{
		printf("û�д˱�Ż�Ʒ,��ȷ�Ϻ��������롣\n");
		return;
}
	p1 = &goods[i].sum;
	printf("��������Ҫ����������:>");
	scanf("%d", &n);
	*p1 = *p1 + n;
	printf("������û�Ʒ���Ϊ��%d\n", *p1);
}

void name_sort(struct goods* p)
{
	int i, j, k;
	for (i = 0; i < o-1; i++)
	{
		k = i;
		for (j = i + 1; j < o; j++)
		{
			if (strcmp((p + k)->name, (p + j)->name) > 0)
			k = j;
		}
		*(p + i+1) = *(p + k); *(p + k) = *(p + i); *(p + i) = *(p + i + 1);
	}
}
