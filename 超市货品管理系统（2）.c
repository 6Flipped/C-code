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
int  my_input(int *a)
{
	int i,j,k,m=0, n;
	printf("��ǰ��������%d�����\n", *a);
	printf("�����������ϼܵ���Ʒ�������:");
	scanf("%d", &n);
	for (i =*a; i < *a+n; i++)
	{
		printf("������%d�Ż�Ʒ����:", i+1 );
		scanf("%s", goods[i].name);
		printf("������%d�Ż�Ʒ���:", i +1);
		scanf("%d", &goods[i].num);
		for (j = 1; j < 3; j++)
			{
			if (i == 0)
				break;
				for (k = i - 1; k >= 0; k--)
				{
					if (goods[i].num == goods[k].num)
					{
						printf("�ñ���Ѵ��ڣ�������%d�λ��ᣬ���������룺\n", 3 - j);
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
		printf("������%d�Ż�Ʒ�ϼ�����:", i +1);
		scanf("%d", &goods[i].sum);
		printf("������%d�Ż�Ʒ����:", i+1);
		scanf("%d", &goods[i].price);
		printf("\n");
	}
	return i;
}

void my_budan(int *a)
{
	int i,j;
	printf("��������Ҫ�����Ļ�Ʒ��ţ�");
	scanf("%d", &j);
	for (i = *a; i >= 0; i--)
	{
		if (goods[i].num == j)
			break;
	}
	printf("��ǰ�û���Ŀ��Ϊ��%d\n", goods[i].sum);
	printf("��������Ҫ������������");
	scanf("%d", &j);
	goods[i].sum = goods[i].sum + j;
	printf("������û�Ʒ����Ϊ��%d", goods[i].sum);
	printf("\n");
}

int main()
{

	int x,y=0, n = 1;
	while (n)
	{
		menu();
		printf("\t\t>>>��ѡ����Ҫʹ�õĹ������1--6:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			y=my_input(&y);//�»��ϼ�
			break;
		case 2:
			my_budan(&y);//��Ʒ�������޸Ļ�Ʒ������
			break;
		case 3:
			printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 4:
			printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 5:printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 6:
			printf("�ù��ܻ�δ�����ء�\n");
			break;
		case 7:n = 0;
			break;
		default:
			printf("\t\t-----------------ѡ�����������---------------------\n");
			break;
		}
	}
	printf("\n");
	printf("\t\t-----------------��л��ʹ�ñ�ϵͳ---------------------\n");
	printf("\t\t******************************************************\n");
}