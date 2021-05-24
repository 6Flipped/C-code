#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 20

int main()
{
	int m, n = 8,arr1[N],i;
	printf("请输入一个十进制的整数：");
	scanf("%d", &m);
	for (i = 0; m!= 0; i++)
	{
		arr1[i] = m % n;
		m = m / n;
	}
	n = i;
	for (i = n-1; i >= 0; i--)
	{
		printf("%d", arr1[i]);
	}
	return 0;
}
