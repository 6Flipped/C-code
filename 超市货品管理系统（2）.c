#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 20

struct goods
{
	int num, sum, price; char name[20];
}goods[N];
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
int  my_input(int *a)
{
	int i,j,k,m=0, n;
	printf("当前货架上有%d个货物：\n", *a);
	printf("请输入您将上架的商品种类个数:");
	scanf("%d", &n);
	for (i =*a; i < *a+n; i++)
	{
		printf("请输入%d号货品名称:", i+1 );
		scanf("%s", goods[i].name);
		printf("请输入%d号货品编号:", i +1);
		scanf("%d", &goods[i].num);
		for (j = 1; j < 3; j++)
			{
			if (i == 0)
				break;
				for (k = i - 1; k >= 0; k--)
				{
					if (goods[i].num == goods[k].num)
					{
						printf("该编号已存在，您还有%d次机会，请重新输入：\n", 3 - j);
						m += 1;
						scanf("%d", &goods[i].num);
					}
				}
				if (k == 0 && goods[i].num != goods[k].num)
					break;
			}
		if (m == 2)
		{
			break;
		}
		printf("请输入%d号货品上架数量:", i +1);
		scanf("%d", &goods[i].sum);
		printf("请输入%d号货品单价:", i+1);
		scanf("%d", &goods[i].price);
		printf("\n");
	}
	return i;
}

void my_budan(int *a)
{
	int i,j;
	printf("请输入您要补单的货品编号：");
	scanf("%d", &j);
	for (i = *a; i >= 0; i--)
	{
		if (goods[i].num == j)
			break;
	}
	printf("当前该货物的库存为：%d\n", goods[i].sum);
	printf("请输入您要补单的数量：");
	scanf("%d", &j);
	goods[i].sum = goods[i].sum + j;
	printf("补单后该货品数量为：%d", goods[i].sum);
	printf("\n");
}

int main()
{

	int x,y=0, n = 1;
	while (n)
	{
		menu();
		printf("\t\t>>>请选择您要使用的功能序号1--6:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			y=my_input(&y);//新货上架
			break;
		case 2:
			my_budan(&y);//货品补单（修改货品数量）
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
		case 7:n = 0;
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