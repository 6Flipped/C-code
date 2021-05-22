#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#define N 20  

int main()
{int i, j, k,n;
	char arr1[N][30],arr2[N][30];
	printf("请输入字符串的个数：");
	scanf("%d", &n);
	for (i = 0; i <= n ; i++)
	{
		gets(arr1[i]);
	}
	for (i = 0; i < n ; i++)
	{
		k = i;
		for (j = i + 1; j <= n; j++)//寻找最小字符串下标
		{
			if (strcmp(arr1[i], arr1[j]) >= 0)
				k = j;
		}
		if (k != i)//字符型交换
		{
			strcpy(arr2[15], arr1[i]);
			strcpy(arr1[i], arr1[k]);
			strcpy(arr1[k], arr2[15]);
		}
	}
	for (i = 0; i <= n ; i++)
	{
		puts(arr1[i]);
	}
	return 0;
}
