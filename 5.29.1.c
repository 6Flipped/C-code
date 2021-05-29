#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 10

void my_search(int* p1, int* max, int* min)
{
	int i,m,n;
	m = n = 0;
	for (i = 0; i<=N-1; i++)
	{
			if (*(p1 + m) > *(p1 + i))
				m = i;
			if (*(p1 +n) < *(p1 +i))
				n = i;
	}
	if (m != i)
		*min = *(p1 + m);
	if (n != i)
		*max = *(p1 + n);
}

int main()
{
	int arr1[N], i;
	int m, n;
	printf("请输入%d个整数：",N);
	for (i = 0; i <= N - 1; i++)
		scanf("%d", &arr1[i]);
	m = n = arr1[0];
	my_search(arr1,&m,&n);
	printf("max=%d\nmin=%d", m, n);
	return 0;
}
