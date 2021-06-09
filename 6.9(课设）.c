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
	printf("当前已上架商品基本信息如下：\n");
	load();
	while (n)
	{
		menu();
		printf("\t\t>>>请选择您要使用的功能序号1--7:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			y = o;
			y = my_input(&y);//新货上架
			break;
		case 2:
			my_add(p1);//货品补单（修改货品数量）
			save1(y);
			break;
		case 3:
			my_search(p1);//货品信息查询
			break;
		case 4:
			my_del(p1);//删除数据
			break;
		case 5:printf("该功能还未开发呢。\n");
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
	printf("\t\t||                  7.浏览货架信息                  ||\n");
	printf("\t\t||                  8.退出                          ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||           请选择您需要的功能，按回车键结束       ||\n");
	printf("\t\t======================================================\n");
}

int  my_input(int *a)//输入商品数据
{
	int i,n,j;
	printf("当前货架上有%d个货物.\n", o);
	printf("请输入您将上架的商品种类个数:");
	scanf("%d", &n);
	for (i = *a; i < *a + n; i++)
	{
		printf("请输入%d号货品名称:", i + 1);
		scanf("%s", goods[i].name);
		printf("请输入%d号货品编号:", i + 1);
		scanf("%d", &goods[i].num);
		j=my_chachong(goods[i].num,i);
		if (j == -1)
		{
			printf("该编号已存在，请确认后输入！！！\n");
			break;
		}
		printf("请输入%d号货品上架数量:", i + 1);
		scanf("%d", &goods[i].sum);
		printf("请输入%d号货品单价:", i + 1);
		scanf("%d", &goods[i].price);
		printf("上架成功！！！\n");
		printf("\n");
	}
	num_sort(p1);
	save(i);
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
	int n, i;
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
	printf("请输入您要补单的数量:>");
	scanf("%d", &n);
	goods[i].sum += n;
	printf("补单后该货品库存为：%d\n", goods[i].sum);
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
	printf("请选择查询方式，名称查询请按1，编号查询请按2：");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		name_sort(p);
		printf("已按名称排序：\n");
		i=name_search(p);
		return i;
	case 2:
		num_sort(p);/*
		printf("货品信息如下：\n");
		load();*/
		printf("已按编号从小到大排序：\n");
		i=num_search(p);
		return i;
	default:
		printf("输入错误已退出");return 0;
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
//int name_search(struct goods* p)//遍历查找
//{
//	int i;
//	name_sort(p); load();
//	printf("请输入查询货品名称:");
//	scanf("%s", &temp.name);
//	for (i = 0; i < o; i++)
//	{
//		if (strcmp(goods[i].name, temp.name) == 0)
//		{
//			printf("找到了！！！\n");
//			break;
//		}
//	}
//	if (i != o)
//	{
//		printf("名称\t编号\t库存\t单价\n");
//		printf("%s\t%d\t%d\t%d\n", goods[i].name, goods[i].num, goods[i].sum, goods[i].price);
//		return i;
//	}
//	else
//		printf("没找到！！！！\n");
//	return -1;
//}

int name_search(struct goods* p)
{
	int high, low, mid;
	char arr1[20];
	name_sort(p); load();
	printf("请输入您要查询的货品名称：");
	scanf("%s", arr1);
	low = mid = 0; high = o - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strcmp(goods[mid].name,arr1)==0)
		{
			printf("找到了！！！\n");
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
		printf("没找到！！！\n");
		return -1;
	}
	else
	{
		printf("名称\t编号\t库存\t单价\n");
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
	printf("请输入您要查询的货品编号：");
	scanf("%d", &a);
	low = mid = 0; high = o - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (goods[mid].num == a)
		{
			printf("找到了！！！\n");
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
	{	printf("没找到！！！\n");
	return -1;
}
	else
	{
		printf("名称\t编号\t库存\t单价\n");
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
		printf("已退出该操作。\n");
		return;
	}
	printf("确认删除请按1,按任意数字取消操作：");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		for (j = k; j < o-1; j++)
		{
			goods[j] = goods[j + 1];
		}
		printf("下架成功！！！\n");
		printf("\n");
		o= o - 1;
		save2(o);
		break;
	default:
		printf("已自动取消操作。\n");
		break;
	}
}