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
}goods[N],temp, * p1;

struct sell 
{
	struct goods;
	char sale[20];
}; sell[N];

int main()
{
	int y=0,x, n = 1;
	p1 = goods;
	printf("��ǰ���ϼ���Ʒ������Ϣ���£�\n");
	load();
	while (n)
	{
		menu();
		printf("\t\t>>>��ѡ����Ҫʹ�õĹ������1--7:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			y = o;
			y = my_input(&y);//�»��ϼ�
			break;
		case 2:
			my_add(p1);//��Ʒ�������޸Ļ�Ʒ������
			save1(y);
			break;
		case 3:
			my_search(p1);//��Ʒ��Ϣ��ѯ
			break;
		case 4:
			my_del(p1);//ɾ������
			break;
		case 5:printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 6:
			num_sort(p1);
			break;
		case 7:
			load();
			break;
		case 8:
			n = 0;
			save1(y);
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
	printf("\t\t||                  7.���������Ϣ                  ||\n");
	printf("\t\t||                  8.�˳�                          ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||           ��ѡ������Ҫ�Ĺ��ܣ����س�������       ||\n");
	printf("\t\t======================================================\n");
}

int  my_input(int *a)//������Ʒ����
{
	int i,n,j;
	printf("��ǰ��������%d������.\n", o);
	printf("�����������ϼܵ���Ʒ�������:");
	scanf("%d", &n);
	for (i = *a; i < *a + n; i++)
	{
		printf("������%d�Ż�Ʒ����:", i + 1);
		scanf("%s", goods[i].name);
		printf("������%d�Ż�Ʒ���:", i + 1);
		scanf("%d", &goods[i].num);
		j=my_chachong(goods[i].num,i);
		if (j == -1)
		{
			printf("�ñ���Ѵ��ڣ���ȷ�Ϻ����룡����\n");
			break;
		}
		printf("������%d�Ż�Ʒ�ϼ�����:", i + 1);
		scanf("%d", &goods[i].sum);
		printf("������%d�Ż�Ʒ����:", i + 1);
		scanf("%d", &goods[i].price);
		printf("�ϼܳɹ�������\n");
		printf("\n");
	}
	num_sort(p1);
	save(i);
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
	int n, i;
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
	printf("��������Ҫ����������:>");
	scanf("%d", &n);
	goods[i].sum += n;
	printf("������û�Ʒ���Ϊ��%d\n", goods[i].sum);
	save2(o);
}

void save1(int a)
{
	FILE* p = fopen("text.txt", "rb+");
	int i = 0;
	rewind(p);
	if (p == NULL)
	{
		printf("Save:no this file");
		return;
	}
	for (i = 0; i < a; i++)
	{
		fwrite(&goods[i], sizeof(struct goods), 1, p);
	}

	fclose(p);
	p = NULL;
}

void save2(int a)
{
	FILE* p = fopen("text.txt", "wb+");
	int i = 0;
	if (p == NULL)
	{
		printf("Save:no this file");
		return;
	}
	for (i = 0; i < a; i++)
	{
		fwrite(&goods[i], sizeof(struct goods), 1, p);
	}

	fclose(p);
	p = NULL;
}

int my_search(struct goods* p)
{
	int n,i;
	printf("��ѡ���ѯ��ʽ�����Ʋ�ѯ�밴1����Ų�ѯ�밴2��");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		name_sort(p);
		printf("�Ѱ���������\n");
		i=name_search(p);
		return i;
	case 2:
		num_sort(p);/*
		printf("��Ʒ��Ϣ���£�\n");
		load();*/
		printf("�Ѱ���Ŵ�С��������\n");
		i=num_search(p);
		return i;
	default:
		printf("����������˳�");return 0;
	}
}

void name_sort(struct goods* p)
{
	int i, j, k;
	struct goods* p2;
	p2 = &temp;
	for (i = 0; i < o - 1; i++)
	{
		k = i;
		for (j = i + 1; j < o; j++)
		{
			if (strcmp(goods[k].name,goods[j].name)>0)
			{
				k = j; break;
			}
		}
		if (k != i)
		{
			*p2 = *(p + i); *(p + i) = *(p + k); *(p + k) = *p2;
		}
	}
	save1(o);
}
//
//int name_search(struct goods* p)//��������
//{
//	int i;
//	name_sort(p); load();
//	printf("�������ѯ��Ʒ����:");
//	scanf("%s", &temp.name);
//	for (i = 0; i < o; i++)
//	{
//		if (strcmp(goods[i].name, temp.name) == 0)
//		{
//			printf("�ҵ��ˣ�����\n");
//			break;
//		}
//	}
//	if (i != o)
//	{
//		printf("����\t���\t���\t����\n");
//		printf("%s\t%d\t%d\t%d\n", goods[i].name, goods[i].num, goods[i].sum, goods[i].price);
//		return i;
//	}
//	else
//		printf("û�ҵ���������\n");
//	return -1;
//}

int name_search(struct goods* p)
{
	int high, low, mid;
	char arr1[20];
	name_sort(p); load();
	printf("��������Ҫ��ѯ�Ļ�Ʒ���ƣ�");
	scanf("%s", arr1);
	low = mid = 0; high = o - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strcmp(goods[mid].name,arr1)==0)
		{
			printf("�ҵ��ˣ�����\n");
			break;
		}
		if (strcmp(goods[mid].name,arr1)>0)
			high = mid - 1;
		else
			low = mid + 1;
		if (strcmp(goods[low].name,arr1)==0)
			mid = low;
		if (strcmp(goods[high].name, arr1) == 0)
			mid = high;

	}
	if (high < low)
	{
		printf("û�ҵ�������\n");
		return -1;
	}
	else
	{
		printf("����\t���\t���\t����\n");
		printf("%s\t%d\t%d\t%d\n", goods[mid].name, goods[mid].num, goods[mid].sum, goods[mid].price);
	}
	return mid;
}

void num_sort(struct goods* p)
{
	int i, j, k;
	struct goods* p2;
	p2 = &temp;
	for (i = 0; i < o - 1; i++)
	{
		k = i;
		for (j = i + 1; j < o; j++)
		{
			if (goods[k].num > goods[j].num)
			{
				k = j; break;
			}
		}
		if (k != i)
		{
			*p2 = *(p + i); *(p + i) = *(p + k); *(p + k) = *p2;
		}
	}
	save1(o);
}

int num_search(struct goods* p)
{
	int high, low, mid;
	int a;
	num_sort(p); load();
	printf("��������Ҫ��ѯ�Ļ�Ʒ��ţ�");
	scanf("%d", &a);
	low = mid = 0; high = o - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (goods[mid].num == a)
		{
			printf("�ҵ��ˣ�����\n");
			break;
		}
		if (goods[mid].num > a)
			high = mid - 1;
		else
			low = mid + 1;
		if (goods[low].num == a)
			mid = low;
		if (goods[high].num == a)
			mid = high;

	}
	if (high < low)
	{	printf("û�ҵ�������\n");
	return -1;
}
	else
	{
		printf("����\t���\t���\t����\n");
		printf("%s\t%d\t%d\t%d\n", goods[mid].name, goods[mid].num, goods[mid].sum, goods[mid].price);
	}
	return mid;
}

void my_del(struct goods* p)
{
	int i,j,k;
	k=my_search(p);
	if (k == -1)
	{
		printf("���˳��ò�����\n");
		return;
	}
	printf("ȷ��ɾ���밴1,����������ȡ��������");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		for (j = k; j < o-1; j++)
		{
			goods[j] = goods[j + 1];
		}
		printf("�¼ܳɹ�������\n");
		printf("\n");
		o= o - 1;
		save2(o);
		break;
	default:
		printf("���Զ�ȡ��������\n");
		break;
	}
}