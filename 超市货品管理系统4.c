#define _CRT_SECURE_NO_WARNINGS  1
#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#define N 20

struct goods
{
	int num, sum, price; char name[20];
}goods[N], temp;
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

int  my_input(int* a)//��һ�β���û���⣬�ڶ��γ�������
{
	int i, j, k, n, m;
	printf("��ǰ��������%d�����\n", *a);
	printf("�����������ϼܵ���Ʒ�������:");
	scanf("%d", &n);
	for (i = *a; i < *a + n; i++)
	{
		printf("������%d�Ż�Ʒ����:", i + 1);
		scanf("%s", goods[i].name);
		printf("������%d�Ż�Ʒ���:", i + 1);
		scanf("%d", &goods[i].num);
		j = m = k = 0;
		while (j < 2)
		{
			if (i == 0)
				break;
			else
				for (k = i - 1; k >= 0; k--)
				{
					if (goods[i].num == goods[k].num)
					{
						printf("�ñ���Ѵ��ڣ�������%d�λ��ᣬ���������룺\n", 2 - j);
						printf("%d\n", m);
						scanf("%d", &goods[i].num);
						break;
					}
				}
			j++; m++;
		}
		for (k = i - 1; k >= 0; k--)
		{
			if (goods[i].num != goods[k].num && k == 0)
				m = 3;
		}
		if (m == 2)
			break;
		/*for (j = 1; j < 3; j++)
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
					break;
				}
			}
			if (k == 0 && goods[i].num != goods[k].num)
				break;
		}
		p = m;
		m = 0;
		if (p== 1)
		{
			break;
		}
	*/
		printf("������%d�Ż�Ʒ�ϼ�����:", i + 1);
		scanf("%d", &goods[i].sum);
		printf("������%d�Ż�Ʒ����:", i + 1);
		scanf("%d", &goods[i].price);
		printf("\n");
	}
	for (j = 0; j < i - 1; j++)
	{
		k = j;
		for (n = 0; n < i; n++)
		{
			if (goods[k].num > goods[n].num)
				k = n;
		}
		if (k != j)
			temp = goods[k];
		goods[k] = goods[j];
		goods[j] = temp;
	}
	return i;
}

int my_budan(int* a)
{
	int i, j;
	if (*a == 0)
	{
		printf("��ǰ�����ϻ�û�л�ƷŶ\n��ѡ����1�ϼܻ�Ʒ���ٽ��в�����\n");
		return 0;
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
	//FILE* p1 = fopen("text.txt", "a");
	while (n)
	{
		menu();
		printf("\t\t>>>��ѡ����Ҫʹ�õĹ������1--6:");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
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
	//fclose(p1);
	//p1 = NULL;
	return 0;
}