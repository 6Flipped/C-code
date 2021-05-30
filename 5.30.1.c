#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 3

int main()
{
	int arr1[N],*p;
	int i, j, k;
	printf("请输入%d个整数：\n", N);
	for (i = 0; i <= N - 1; i++)
		scanf("%d", &arr1[i]);
	p = arr1;
	for (i = 0; i < N - 1; i++)
	{
		k = i;
		for (j = i + 1; j < N; j++)//p+0,1,2   3 2 1 
		{
			if (*(p + k) > *(p + j))
				k = j;
		}
		j = *(p + k); *(p + k) = *(p + i); *(p + i) = j;
	}
	for (i = 0; i <= N - 1; i++)
		printf("%d\n", *(p + i));
	return 0;
}
