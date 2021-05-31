#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 4

void my_search(int* s1, int* m, int* n)
{
	int i;
	for (i = 0; i <= N - 1; i++)
	{
		if (*m < s1[i])
			*m = s1[i];
		if (*n > s1[i])
			*n = s1[i];
	}
}

int main()
{
	int arr1[N], max, min;
	int i;
	printf("请输入%d个整数：", N);
	for (i = 0; i <= N - 1; i++)
		scanf("%d", &arr1[i]);
	max = min = arr1[0];
	my_search(arr1, &max, &min);
	printf("max=%d\nmin=%d", max, min);
	return 0;
}