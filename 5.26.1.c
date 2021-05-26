#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 20

int my_search(float s1[], int n)
{
	int i, j, k;
	float a;
	k = 0;
	for (i = 0, j = i + 1; j <= n - 1; j++)
	{
		a = s1[j];
		if (a < 0)
			a = -a;
		if (s1[i] > a)
			k = j;
	}
	if (k != 0)
		return k;
	else
		return 0;
}

int main()
{
	float arr1[N],a;
	int i,k,n;
	printf("请输入要输入的数据数量：\n");
	scanf("%d", &n);
	printf("请输入%d个数：\n",n);
	for (i = 0; i <= n-1; i++)
		scanf("%f", &arr1[i]);
	k=my_search(arr1,n);
	a = arr1[k]; arr1[k] = arr1[n - 1]; arr1[n - 1] = a;
	for (i = 0; i <= n - 1; i++)
		printf("%g ", arr1[i]);
	return 0;
}