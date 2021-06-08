#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"keshe.h"
#define N 2000
int o;//货架编号

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
	printf("当前已上架商品基本信息如下：\n");
	load();
	while (n)
	{
		menu();
		printf("\t\t>>>请选择您要使用的功能序号1--7:>");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			y = o;
			y = my_input(&y);//新货上架
			name_sort(p1);
			save(y);
			break;
		case 2:
			my_add(p1);//货品补单（修改货品数量）
			save(y);
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
		/*	save(&y);*/
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
	return 0;
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

int  my_input(int *a)//输入商品数据
{
	int i,n,j;
	printf("当前货架上有%d个货物.\n", o);
	printf("请输入您将上架的商品种类个数:>");
	scanf("%d", &n);
	for (i = *a; i < *a + n; i++)
	{
		printf("请输入%d号货品名称:>", i + 1);
		scanf("%s", goods[i].name);
		printf("请输入%d号货品编号:>", i + 1);
		scanf("%d", &goods[i].num);
		j=my_chachong(goods[i].num,i);
		if (j == -1)
		{
			printf("该编号已存在，请确认后输入！！！\n");
			break;
		}
		printf("请输入%d号货品上架数量:>", i + 1);
		scanf("%d", &goods[i].sum);
		printf("请输入%d号货品单价:>", i + 1);
		scanf("%d", &goods[i].price);
		printf("\n");
	}
	return i;
}

void save(int a)//数据保存到文件
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

void load()//从文件中读取数据
{
	int i = 0;
	 o=0;
	FILE* p=fopen("text.txt","rb");
	if (p== NULL)
	{
		printf("Load:no this file");
		return;
	}
	printf("货架号\t名称\t编号\t库存\t单价\n");
	while (fread(&goods[i], sizeof(struct goods), 1, p))
{
	printf("%d\t%s\t%d\t%d\t%d\n",o+1, goods[i].name, goods[i].num, goods[i].sum,goods[i].price);
	o++; i++;
}
	printf("\n");
	fclose(p);
	p = NULL;
}

int my_chachong(int a, int b)//查询编号是否存在
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
	printf("请输入要补单货品编号:>");
	scanf("%d", &n);
	for (i = 0; i < o; i++)
	{
		if ((p + i)->num == n)
		{
			printf("找到了，他是%s\n", (p + i)->name);
			break;
		}
	}
	if (i == o)
	{
		printf("没有此编号货品,请确认后重新输入。\n");
		return;
}
	p1 = &goods[i].sum;
	printf("请输入您要补单的数量:>");
	scanf("%d", &n);
	*p1 = *p1 + n;
	printf("补单后该货品库存为：%d\n", *p1);
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
