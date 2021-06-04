#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include"keshe.h"
#define N 20

struct goods
{
	int num, sum, price;
	char name[20];
}goods[N], temp,*p1;
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

void load(int* a)
{
	FILE* p = fopen("text.txt", "w");
	struct goods tmp = { 0 };
	p1 = &goods;
	int i = 0;
		if (p == NULL)
		{
			printf("%s\n", strerror(errno));
			return;
		}
		while (fread(&tmp, sizeof(struct goods), 1, p))
		{
			(p1+i)= tmp;
			p1++;
		}

		fclose(p);
		p = NULL;
}




void save(int* a)
{
	FILE* p = fopen("text.txt", "wb");
	if (p == NULL)
		printf("%s\n", strerror(errno));
	int i = 0;
	for (i = 0; i < *a; i++)
	{
		fwrite(&goods[i], sizeof(struct goods), 1, p);
	}
	fclose(p);
	p = NULL;
}

int  my_input(int* a)//��һ�β���û���⣬�ڶ��γ�������
{
	int i,n;
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
	return i;
}

void my_budan(int* a)
{
	int i, j;
	if (*a == 0)
	{
		printf("��ǰ�����ϻ�û�л�ƷŶ\n��ѡ����1�ϼܻ�Ʒ���ٽ��в�����\n");
		return;
	}
	printf("��������Ҫ�����Ļ�Ʒ��ţ�");
	scanf("%d", &j);
	for (i = *a; i >= 0; i--)
	{
		if (goods[i].num == j)
			break;
	}
	printf("��ǰ%d�Ż���Ŀ��Ϊ��%d\n", goods[i].num, goods[i].sum);
	printf("��������Ҫ������������");
	scanf("%d", &j);
	goods[i].sum = goods[i].sum + j;
	printf("������û�Ʒ����Ϊ��%d", goods[i].sum);
	printf("\n");
}

void my_search(int* a)
{
	int i, j, k, n, high, low, mid;
	char c[1][20];
	printf("��ѡ����Ҫ��ѯ�ķ�ʽ�����Ʋ�ѯ�밴1����Ų�ѯ�밴2��\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1://���Ʋ�ѯ
		for (i = 0; i < *a - 1; i++)
		{
			k = i;
			for (j = i + 1; j < *a; j++)
			{
				if (strcmp(goods[k].name, goods[j].name) > 0)
					k = j;
			}
			if (k != i)
			{
				temp = goods[k];
				goods[k] = goods[i];
				goods[i] = temp;
			}
		}
		printf("��������Ҫ��ѯ�Ļ�Ʒ���ƣ�");
		scanf("%s", c[0]);
		low = 0; high = *a - 1; mid = (low + high) / 2;

		while (low <= high)
		{
			mid = (low + high) / 2;
			if (strcmp(goods[mid].name, *c) == 0)
				break;
			else if (strcmp(goods[mid].name, *c) > 0)
				high = mid - 1;
			else
				low = mid + 1;
		}
		if (low >= high)
			printf("�Բ���û���ҵ����ֻ�Ʒ����ȷ�����������ʹ�øù��ܡ�\n");
		else
			printf("�ҵ��ˣ��û�Ʒ����Ϊ��%s\n���Ϊ��%d\n����Ϊ��%d\n��ǰ���Ϊ��%d\n", goods[mid].name, goods[mid].num, goods[mid].price, goods[mid].sum);
		break;
	case 2://��Ų�ѯ
		for (i = 0; i < *a - 1; i++)
		{
			k = i;
			for (j = i + 1; j < *a; j++)
			{
				if (goods[k].num > goods[j].num)
					k = j;
			}
			if (k != i)
			{
				temp = goods[k];
				goods[k] = goods[i];
				goods[i] = temp;
			}
		}
		printf("��������Ҫ��ѯ�Ļ�Ʒ��ţ�");
		scanf("%d", &n);
		low = 0; high = *a - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (goods[mid].num == n)
				break;
			else if (goods[mid].num > n)
				high = mid - 1;
			else
				low = mid + 1;
		}
		if (low >= high)
			printf("�Բ���û���ҵ����ֻ�Ʒ����ȷ�����������ʹ�øù��ܡ�\n");
		else
			printf("�ҵ��ˣ��û�Ʒ����Ϊ��%s\n���Ϊ��%d\n����Ϊ��%d\n��ǰ���Ϊ��%d\n", goods[mid].name, goods[mid].num, goods[mid].price, goods[mid].sum);
		break;
	default:
		printf("ѡ����������ԡ�\n");
		break;
	}
}

int main()
{

	int x, y = 0, n = 1;
	p1 = goods;
	while (n)
	{
		menu();
		printf("\t\t>>>��ѡ����Ҫʹ�õĹ������1--7:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			load(&y);
			y = my_input(&y);//�»��ϼ�
			break;
		case 2:
			my_budan(&y);//��Ʒ�������޸Ļ�Ʒ������
			break;
		case 3:
			my_search(&y);//��Ʒ��Ϣ��ѯ
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
			load(&y);
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