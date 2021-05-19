#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N  5

void sort(int s[], int n)
{
	int i, j, k;
	for (i = 0; i <=n - 1; i++)
	{
		k = i;
		for (j = i + 1; j <= n - 1; j++)
		{
			if (s[k] > s[j])
				k = j;
		}//找到最小元素的下标
		if (k != i)
		{
			j= s[i]; s[i] = s[k]; s[k] = j;//交换最大元素和最小元素
		}
	}

}

int main()
{
	int arr1[N];
	int i;
	printf("请输入%d个整数：", N);
	for (i = 0; i <= N - 1; i++)
	{
		scanf("%d", &arr1[i]);
	}
	sort(arr1,N); 
	for (i = 0; i <= N - 1; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}
