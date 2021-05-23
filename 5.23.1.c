#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N  20

int main()
{
	int n, i, j, arr1[N][N]={ 0 };
	printf("请输入要打印的杨辉三角的行数：");
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0||i==j)//首个和最后一位赋值1
				arr1[i][j] = 1;
			else//其他位置按规律计算
					arr1[i][j] = arr1[i - 1][j - 1] + arr1[i - 1][j];
		}
	}
	printf("常规形打印输出:\n");
	for (i = 0; i <= n-1 ; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	printf("金字塔形打印输出:\n");
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
