#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"keshe.h"
#define N 20

int i,n,y;
struct goods 
{
	char name[20];
	int num;
	int sum;
	int price;
}goods[N],*p1;

int main()
{
	int x, n = 1;
	printf("y=%d\n", y);
	p1 = goods;
	while (n)
	{
		menu();
		printf("\t\t>>>��ѡ����Ҫʹ�õĹ������1--7:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
		   y= my_input(&y);//�»��ϼ�
			break;
		case 2:
			/*my_budan(p1);*///��Ʒ�������޸Ļ�Ʒ������
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
			save(&y);
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
	//fclose(p1);
	//p1 = NULL;
	return 0;
}

void load()//cong�ļ��ж�ȡ����
{
	int i;
	FILE* p = fopen("text.txt", "rb");
	if (p == NULL)
	{
		printf("Load:cannot open this file\n");
		exit(0);
	}
	printf("y=%d\n", y);
	printf( "���ܺ�\t����\t���\t���\t����\t\n");
	for (i =0; i <y; i++)
	{
		/*fread(p1 + i, sizeof(struct goods), 1, p);
		printf("%d\t%s\t%d\t%d\t%d\t\n",i+1, (p1+i)->name, (p1+i)->num, (p1+i)->sum, (p1+i)->price); */
		fscanf(p, "%s%d%d%d", (p1 + i)->name, &(p1 + i)->num, &(p1 + i)->sum, &(p1 + i)->price);
		printf("%d\t%s\t%d\t%d\t%d\t\n", i + 1, (p1 + i)->name, (p1 + i)->num, (p1 + i)->sum, (p1 + i)->price);
	}
	fclose(p);
	p = NULL;
	return;
}

void save(int *a)//���ļ���д������
{
	int i;
	FILE* p = fopen("text.txt", "wb");
	if (p == NULL)
	{
		printf("save:cannot open this file\n");
		exit(0);
	}
	for (i =*a; i < *a+n; i++)
	{
		fprintf(p, "%s%d%d%d", (p1 + i)->name, (p1 + i)->num, (p1 + i)->sum, (p1 + i)->price);
		printf("i=%d\n", i);
	}
	fclose(p);
	p = NULL;
}

int  my_input(int* a)//��һ�β���û���⣬�ڶ��γ�������
{
	printf("��ǰ��������%d�����\n", *a);
	printf("�����������ϼܵ���Ʒ�������:");
	scanf("%d", &n);
	for (i = *a; i < *a + n; i++)
	{
		printf("������%d�Ż�Ʒ����:", i + 1);
		scanf("%s", goods[i].name);
		printf("������%d�Ż�Ʒ���:", i + 1);
		scanf("%d", &goods[i].num);
		printf("������%d�Ż�Ʒ�ϼ�����:", i + 1);
		scanf("%d", &goods[i].sum);
		printf("������%d�Ż�Ʒ����:", i + 1);
		scanf("%d", &goods[i].price);
		printf("\n");
	}
	save(&i);
	return i;
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
//
//int  my_input(int* a)//��һ�β���û���⣬�ڶ��γ�������
//{
//	int i, n;
//	printf("��ǰ��������%d�����\n", *a);
//	printf("�����������ϼܵ���Ʒ�������:");
//	scanf("%d", &n);
//	for (i = *a; i < *a + n; i++)
//	{
//		printf("������%d�Ż�Ʒ����:", i + 1);
//		scanf("%s", goods[i].name);
//		printf("������%d�Ż�Ʒ���:", i + 1);
//		scanf("%d", &goods[i].num);
//		printf("������%d�Ż�Ʒ�ϼ�����:", i + 1);
//		scanf("%d", &goods[i].sum);
//		printf("������%d�Ż�Ʒ����:", i + 1);
//		scanf("%d", &goods[i].price);
//		printf("\n");
//	}
//	return i;
////}
//
//void my_budan(int* a)
//{
//	int i, j;
//	if (*a == 0)
//	{
//		printf("��ǰ�����ϻ�û�л�ƷŶ\n��ѡ����1�ϼܻ�Ʒ���ٽ��в�����\n");
//		return;
//	}
//	printf("��������Ҫ�����Ļ�Ʒ��ţ�");
//	scanf("%d", &j);
//	for (i = *a; i >= 0; i--)
//	{
//		if (goods[i].num == j)
//			break;
//	}
//	printf("��ǰ%d�Ż���Ŀ��Ϊ��%d\n", goods[i].num, goods[i].sum);
//	printf("��������Ҫ������������");
//	scanf("%d", &j);
//	goods[i].sum = goods[i].sum + j;
//	printf("������û�Ʒ����Ϊ��%d", goods[i].sum);
//	printf("\n");
//}

//void my_search(int* a)
//{
//	int i, j, k, n, high, low, mid;
//	char c[1][20];
//	printf("��ѡ����Ҫ��ѯ�ķ�ʽ�����Ʋ�ѯ�밴1����Ų�ѯ�밴2��\n");
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1://���Ʋ�ѯ
//		for (i = 0; i < *a - 1; i++)
//		{
//			k = i;
//			for (j = i + 1; j < *a; j++)
//			{
//				if (strcmp(goods[k].name, goods[j].name) > 0)
//					k = j;
//			}
//			if (k != i)
//			{
//				temp = goods[k];
//				goods[k] = goods[i];
//				goods[i] = temp;
//			}
//		}
//		printf("��������Ҫ��ѯ�Ļ�Ʒ���ƣ�");
//		scanf("%s", c[0]);
//		low = 0; high = *a - 1; mid = (low + high) / 2;
//
//		while (low <= high)
//		{
//			mid = (low + high) / 2;
//			if (strcmp(goods[mid].name, *c) == 0)
//				break;
//			else if (strcmp(goods[mid].name, *c) > 0)
//				high = mid - 1;
//			else
//				low = mid + 1;
//		}
//		if (low >= high)
//			printf("�Բ���û���ҵ����ֻ�Ʒ����ȷ�����������ʹ�øù��ܡ�\n");
//		else
//			printf("�ҵ��ˣ��û�Ʒ����Ϊ��%s\n���Ϊ��%d\n����Ϊ��%d\n��ǰ���Ϊ��%d\n", goods[mid].name, goods[mid].num, goods[mid].price, goods[mid].sum);
//		break;
//	case 2://��Ų�ѯ
//		for (i = 0; i < *a - 1; i++)
//		{
//			k = i;
//			for (j = i + 1; j < *a; j++)
//			{
//				if (goods[k].num > goods[j].num)
//					k = j;
//			}
//			if (k != i)
//			{
//				temp = goods[k];
//				goods[k] = goods[i];
//				goods[i] = temp;
//			}
//		}
//		printf("��������Ҫ��ѯ�Ļ�Ʒ��ţ�");
//		scanf("%d", &n);
//		low = 0; high = *a - 1;
//		while (low <= high)
//		{
//			mid = (low + high) / 2;
//			if (goods[mid].num == n)
//				break;
//			else if (goods[mid].num > n)
//				high = mid - 1;
//			else
//				low = mid + 1;
//		}
//		if (low >= high)
//			printf("�Բ���û���ҵ����ֻ�Ʒ����ȷ�����������ʹ�øù��ܡ�\n");
//		else
//			printf("�ҵ��ˣ��û�Ʒ����Ϊ��%s\n���Ϊ��%d\n����Ϊ��%d\n��ǰ���Ϊ��%d\n", goods[mid].name, goods[mid].num, goods[mid].price, goods[mid].sum);
//		break;
//	default:
//		printf("ѡ����������ԡ�\n");
//		break;
//	}
//}
