#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#define N 100

int num[N][20], sum[N], price[N];
	char name[N][20];
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
	printf("\t\t||                  5.货品销售                      ||\n");
	printf("\t\t||                  6.统计功能                      ||\n");
	printf("\t\t||                  7.退出                          ||\n");
	printf("\t\t||          *********************************       ||\n");
	printf("\t\t||           请选择您需要的功能，按回车键结束       ||\n");
	printf("\t\t======================================================\n");
}

void my_input()//编号重复问题还未解决
{
	int i, j=0,n;
	printf("请输入要上架的商品种类个数：");
	scanf("%d", &n);
	for (i = 0; i <= n - 1; i++)
	{
		printf("请输入第%d个商品的名称：", i + 1);
		scanf("%s", name[i]);
		printf("请输入第%d个商品编号：", i + 1);
		scanf("%d", num[i]);
		printf("请输入第%d个商品上架的数目：", i+1);
		scanf("%d", &sum[i]);
		printf("请输入第%d个商品单价：", i+1);
		scanf("%d", &price[i]);
		printf("\n");
	}
}

void my_budan()//未找到货品后重新输入循环未完成
{
	int a = 0, i;
	printf("请输入您要补单货品编号：\n");
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
		printf("不好意思没找到此货品。");
		printf("\n");
		return 0;
	}
	else
		printf("请输入您要补的单数：");
		scanf("%d", &i);
		*(sum + a) = *(sum + a) + i;
		printf("补单后该货品的库存总量为：%d", *(sum+a));
		printf("\n");
}

void tongji()
{
	printf("请输入要统计的货品名称或编号：\n");
	printf("\n");
}

int main()
{
	
	int x,n=1;
	while (n)
	{
		menu();
		printf("\t\t>>>请选择您要使用的功能序号1--6:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			my_input();//新货上架
			break;
		case 2:
			my_budan();//货品补单（修改货品数量）
			break;
		case 3:
			printf("该功能还未开发呢。\n");
			break;
		case 4:
			printf("该功能还未开发呢。\n");
			break;
		case 5:printf("该功能还未开发呢。\n");
			break;
		case 6:
			printf("该功能还未开发呢。\n");
			break;
		case 7:n=0;
			break;
		default:
			printf("\t\t-----------------选择错误，请重试---------------------\n");
			break;
		}
	}
		printf("\n");
	printf("\t\t-----------------感谢您使用本系统---------------------\n");
	printf("\t\t******************************************************\n");
}