#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N  20

int main()
{
	int n, i, j, arr1[N][N]={ 0 };
	printf("������Ҫ��ӡ��������ǵ�������");
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0||i==j)//�׸������һλ��ֵ1
				arr1[i][j] = 1;
			else//����λ�ð����ɼ���
					arr1[i][j] = arr1[i - 1][j - 1] + arr1[i - 1][j];
		}
	}
	printf("�����δ�ӡ���:\n");
	for (i = 0; i <= n-1 ; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	printf("�������δ�ӡ���:\n");
	for (i = 0; i <= n - 1; i++)
	{
		for (j = 0; j < n - i; j++)
			printf(" ");
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	return 0;
}
