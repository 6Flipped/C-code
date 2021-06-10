#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include"keshe.h"
#define N 2000
int o;//���ܱ�ţ�ʵ�ʸ�����

struct goods
{
	char name[20];
	char hot[5];
	int num;
	int sum;
	int price;
	int fsum;
	int time;
	int all_price;
	char sale[20];
}goods[N], temp, * p1;

int main()
{
	int y = 0, x, n = 1;
	p1 = goods;
	printf("��ǰ���ϼ���Ʒ������Ϣ���£�\n");
	load1();
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
		case 5:
			my_sell();
			break;
		case 6:
			load1();
			break;
		case 7:
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
	printf("\t\t||                  5.��Ʒ����                      ||\n");
	printf("\t\t||                  6.ͳ�ƹ���                      ||\n");
	printf("\t\t||                  7.�˳�                          ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||           ��ѡ������Ҫ�Ĺ��ܣ����س�������       ||\n");
	printf("\t\t======================================================\n");
}

int  my_input(int* a)//������Ʒ����
{
	int i, n, j;
	printf("��ǰ��������%d������.\n", o);
	printf("�����������ϼܵ���Ʒ�������:");
	scanf("%d", &n);
	for (i = *a; i < *a + n; i++)
	{
		printf("������%d�Ż�Ʒ����:", i + 1);
		scanf("%s", goods[i].name);
		printf("������%d�Ż�Ʒ���:", i + 1);
		scanf("%d", &goods[i].num);
		j = my_chachong(goods[i].num, i);
		if (j == -1)
		{
			printf("�ñ���Ѵ��ڣ���ȷ�Ϻ����룡����\n");
			break;
		}
		printf("������%d�Ż�Ʒ�ϼ�����:", i + 1);
		scanf("%d", &goods[i].sum);
		printf("������%d�Ż�Ʒ����:", i + 1);
		scanf("%d", &goods[i].price);
			strcpy(goods[i].hot, "YES.");
		printf("�ϼܳɹ�������\n");
		printf("\n");
	}
	num_sort(p1);
	save(i);
	save1(i);
	return i;
}

void save(int a)//���ݱ��浽�ļ�
{
	FILE* p = fopen("text.txt", "ab+");
	int i = 0;
	if (p == NULL)
	{
		printf("Save:no this file\n");
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
	o = 0;
	FILE* p = fopen("text.txt", "rb");
	if (p == NULL)
	{
		printf("Load:no this file\n");
		return;
	}
	printf("���ܺ�\t����\t���\t���\t����\t������\n");
	while (fread(&goods[i], sizeof(struct goods), 1, p))
	{

		printf("%d\t%s\t%d\t%d\t%d\t%s\n", o + 1, goods[i].name, goods[i].num, goods[i].sum, goods[i].price,goods[i].hot);
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
	printf("������Ҫ������Ʒ���:");
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
	printf("��������Ҫ����������:");
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
		printf("Save:no this file\n");
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
		printf("Save:no this file\n");
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
	int n, i;
	printf("��ѡ���Ʒ��ѯ��ʽ�����Ʋ�ѯ�밴1����Ų�ѯ�밴2��");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		name_sort(p);
		printf("�Ѱ���������\n");
		i = name_search(p);
		return i;
	case 2:
		num_sort(p);/*
		printf("��Ʒ��Ϣ���£�\n");
		load();*/
		printf("�Ѱ���Ŵ�С��������\n");
		i = num_search(p);
		return i;
	default:
		printf("����������˳���\n"); return -1;
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
			if (strcmp(goods[k].name, goods[j].name) > 0)
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
		if (strcmp(goods[mid].name, arr1) == 0)
		{
			printf("�ҵ��ˣ�����\n");
			break;
		}
		if (strcmp(goods[mid].name, arr1) > 0)
			high = mid - 1;
		else
			low = mid + 1;
		if (strcmp(goods[low].name, arr1) == 0)
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
		printf("����\t���\t���\t����\t������\n");
		printf("%s\t%d\t%d\t%d\t%s\n", goods[mid].name, goods[mid].num, goods[mid].sum, goods[mid].price, goods[mid].hot);
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
	{
		printf("û�ҵ�������\n");
		return -1;
	}
	else
	{
		printf("����\t���\t���\t����\t������\n");
		printf("%s\t%d\t%d\t%d\t%s\n", goods[mid].name, goods[mid].num, goods[mid].sum, goods[mid].price,goods[mid].hot);
	}
	return mid;
}

void my_del(struct goods* p)
{
	int i, j, k;
	k = my_search(p);
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
		for (j = k; j < o - 1; j++)
		{
			goods[j] = goods[j + 1];
		}
		printf("�¼ܳɹ�������\n");
		printf("\n");
		o = o - 1;
		save2(o);
		break;
	default:
		printf("���Զ�ȡ��������\n");
		break;
	}
}

void my_sell()
{
	int n, i;;
	n=my_search(p1);
	if (n == -1)
		return;
	printf("ȷ���޸����Ѽ�¼�밴1��ȡ���ò����밴�������");
	scanf("%d", &i);
	if (i == 1)
	{
		printf("������Ҫ�����������");
		scanf("%d", &goods[n].fsum);
		if (goods[n].fsum > goods[n].sum)
		{
			printf("�ѳ��������������ȷ�Ϻ��������롣\n");
			return;
		}
		else
			goods[n].sum -= goods[n].fsum;
		goods[n].all_price = goods[n].fsum * goods[n].price;
		printf("�����빺���ʱ��(��ʱ���ɣ�:");
		scanf("%d", &goods[n].time);
		printf("�������ۻ��˵����ƣ�");
		scanf("%s", goods[n].sale);
		save1(o);
		printf("�޸ĳɹ���\n");
	}
	else
		printf("���˳���\n");
		return;
}

void load1()//���ļ��ж�ȡ����
{
	int i = 0;
	o = 0;
	FILE* p = fopen("text.txt", "rb");
	if (p == NULL)
	{
		printf("Load1:no this file\n");
		return;
	}
	printf("���ܺ�\t����\t���\t���\t����\t����\tӯ��\tʱ��\t������\t�ۻ�Ա\n");
	while (fread(&goods[i], sizeof(struct goods), 1, p))
	{
		if (goods[i].fsum >= 3)
			strcpy(goods[i].hot, "YES.");
		else
			strcpy(goods[i].hot, "NO.");
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\n", o + 1, goods[i].name, goods[i].num, goods[i].sum, goods[i].price,goods[i].fsum,goods[i].all_price, goods[i].time, goods[i].hot, goods[i].sale);
		o++; i++;
	}
	printf("\n");
	fclose(p);
	p = NULL;
}
