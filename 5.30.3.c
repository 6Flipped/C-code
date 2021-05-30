#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 5

void my_input(int* p1)
{
	int i;
	for (i = 0; i <= N - 1; i++)
		scanf("%d", p1 + i);
}

void my_sort(int* p2)
{
	int i, j, m,n;
	m = n = 0;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)//5 4 3 2 1
		{
			if (*(p2 + m) > *(p2 + j))
			m = j;
		}
	}	
	if (m != i)
		j = *(p2 + 0); *(p2 + 0) = *(p2 + m); *(p2 + m) = j;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)//5 4 3 2 1
		{
			if (*(p2 + n) < *(p2 + j))
				n = j;
		}
	}
	if (n!= i)
		j = *(p2 + N-1); *(p2 + N-1) = *(p2 + n); *(p2 + n) = j;
}

void my_output(int* p3)
{
	int i;
	printf("调整后结果为：\n");
	for (i = 0; i <= N - 1; i++)
		printf("%d\n", *(p3 + i));
}

int main()
{
	int arr1[N];
	printf("请输入%d个整数：\n", N);
	my_input(arr1);
	my_sort(arr1);
	my_output(arr1);
	return 0;
}