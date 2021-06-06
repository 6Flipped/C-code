#define _CRT_SECURE_NO_WARNINGS  1
#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"keshe.h"
#define N 20

int i, n, y;
struct goods
{
	char name[20];
	int num;
	int sum;
	int price;
}goods[N], * p1;

int main()
{
	int x, n = 1;
	printf("y=%d\n", y);
	p1 = goods;
	while (n)
	{
		menu();
		printf("\t\t>>>请选择您要使用的功能序号1--7:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			y = my_input(&y);//新货上架
			break;
		case 2:
			/*my_budan(p1);*///货品补单（修改货品数量）
			break;
		case 3:
			/*my_search(p1);*///货品信息查询
			break;
		case 4:
			printf("该功能还未开发呢。\n");
			break;
		case 5:printf("该功能还未开发呢。\n");
			break;
		case 6:
			printf("该功能还未开发呢。\n");
			break;
		case 7:
			load();
			break;
		case 8:
			save(&y);
			n = 0;
			break;
		default:
			printf("\t\t-----------------选择错误，请重试---------------------\n"); n = 0;
			break;
		}
	}
	printf("\n");
	printf("\t\t-----------------感谢您使用本系统---------------------\n");
	printf("\t\t******************************************************\n");
	//fclose(p1);
	//p1 = NULL;
	return 0;
}

void load()//cong文件中读取内容
{
	int i;
	FILE* p = fopen("text.txt", "rb");
	if (p == NULL)
	{
		printf("Load:cannot open this file\n");
		exit(0);
	}
	printf("y=%d\n", y);
	printf("货架号\t名称\t编号\t库存\t单价\t\n");
	for (i = 0; i < y; i++)
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

void save(int* a)//向文件中写入内容
{
	int i;
	FILE* p = fopen("text.txt", "wb");
	if (p == NULL)
	{
		printf("save:cannot open this file\n");
		exit(0);
	}
	for (i = *a; i < *a + n; i++)
	{
		fprintf(p, "%s%d%d%d", (p1 + i)->name, (p1 + i)->num, (p1 + i)->sum, (p1 + i)->price);
		printf("i=%d\n", i);
	}
	fclose(p);
	p = NULL;
}

int  my_input(int* a)//第一次查重没问题，第二次出现问题
{
	printf("当前货架上有%d个货物：\n", *a);
	printf("请输入您将上架的商品种类个数:");
	scanf("%d", &n);
	for (i = *a; i < *a + n; i++)
	{
		printf("请输入%d号货品名称:", i + 1);
		scanf("%s", goods[i].name);
		printf("请输入%d号货品编号:", i + 1);
		scanf("%d", &goods[i].num);
		printf("请输入%d号货品上架数量:", i + 1);
		scanf("%d", &goods[i].sum);
		printf("请输入%d号货品单价:", i + 1);
		scanf("%d", &goods[i].price);
		printf("\n");
	}
	save(&i);
	return i;
}

void menu()
{
	printf("\t\t======================================================\n");
	printf("\t\t||             欢迎您使用超市货品管理系统           ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||          *           功能菜单            *       ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||                  1.新货上架                      ||\n");
	printf("\t\t||                  2.货品补单                      ||\n");
	printf("\t\t||                  3.货品查询                      ||\n");
	printf("\t\t||                  4.货品下架                      ||\n");
	printf("\t\t||                  5.销售记录                      ||\n");
	printf("\t\t||                  6.统计功能                      ||\n");
	printf("\t\t||                  7.查询货架信息                  ||\n");
	printf("\t\t||                  8.退出                          ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||           请选择您需要的功能，按回车键结束       ||\n");
	printf("\t\t======================================================\n");
}
//
//int  my_input(int* a)//第一次查重没问题，第二次出现问题
//{
//	int i, n;
//	printf("当前货架上有%d个货物：\n", *a);
//	printf("请输入您将上架的商品种类个数:");
//	scanf("%d", &n);
//	for (i = *a; i < *a + n; i++)
//	{
//		printf("请输入%d号货品名称:", i + 1);
//		scanf("%s", goods[i].name);
//		printf("请输入%d号货品编号:", i + 1);
//		scanf("%d", &goods[i].num);
//		printf("请输入%d号货品上架数量:", i + 1);
//		scanf("%d", &goods[i].sum);
//		printf("请输入%d号货品单价:", i + 1);
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
//		printf("当前货架上还没有货品哦\n请选择功能1上架货品后再进行补单。\n");
//		return;
//	}
//	printf("请输入您要补单的货品编号：");
//	scanf("%d", &j);
//	for (i = *a; i >= 0; i--)
//	{
//		if (goods[i].num == j)
//			break;
//	}
//	printf("当前%d号货物的库存为：%d\n", goods[i].num, goods[i].sum);
//	printf("请输入您要补单的数量：");
//	scanf("%d", &j);
//	goods[i].sum = goods[i].sum + j;
//	printf("补单后该货品数量为：%d", goods[i].sum);
//	printf("\n");
//}

//void my_search(int* a)
//{
//	int i, j, k, n, high, low, mid;
//	char c[1][20];
//	printf("请选择你要查询的方式，名称查询请按1，编号查询请按2。\n");
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1://名称查询
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
//		printf("请输入您要查询的货品名称：");
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
//			printf("对不起，没查找到这种货品，请确认无误后重新使用该功能。\n");
//		else
//			printf("找到了，该货品名称为：%s\n编号为：%d\n单价为：%d\n当前库存为：%d\n", goods[mid].name, goods[mid].num, goods[mid].price, goods[mid].sum);
//		break;
//	case 2://编号查询
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
//		printf("请输入您要查询的货品编号：");
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
//			printf("对不起，没查找到这种货品，请确认无误后重新使用该功能。\n");
//		else
//			printf("找到了，该货品名称为：%s\n编号为：%d\n单价为：%d\n当前库存为：%d\n", goods[mid].name, goods[mid].num, goods[mid].price, goods[mid].sum);
//		break;
//	default:
//		printf("选择错误，请重试。\n");
//		break;
//	}
//}
