#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#define N 5

void my_gets(char s1[N][20], int s2[N])//输入职工号和姓名。
{
	int i;
	for (i = 0; i <= N - 1; i++)
	{
		printf("请输入第%d个职工名称：", i+1);
		scanf("%s", s1[i]);
		printf("请输入第%d个职工号：",i+1);
		scanf("%d", &s2[i]);
	}
}

void my_sort(char s1[N][20], int s2[N])//按照职工号大小排序，姓名随之调整。
{
	int i, j, k; char a[N][20];
	for (i = 0; i < N - 1; i++)
	{
		k = i;
		for (j = i + 1; j <= N - 1; j++)
		{
			if (s2[k] > s2[j])
				k = j;
		}
		if (k != i)
		{
			j = s2[i]; s2[i] = s2[k]; s2[k] = j;
			strcpy(a[i], s1[i]);strcpy(s1[i], s1[k]);strcpy(s1[k], a[i]);
		}
	}

}

int my_search(int nums[], int number, int target) //折半查找。
{
	int left = 0;
	int right = number - 1;
	if (nums[left] == number)
		return left;
	while (left <= right) {
		int mid = (right + left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
	}
	return -1;
}


int main()
{
	char arr1[N][20]; int arr2[N];
	int i, x;
	my_gets(arr1, arr2);
	my_sort(arr1, arr2);
	for (i = 0; i <= N - 1; i++)
	{
		printf("%s ", arr1[i]);
		printf("%d\n", arr2[i]);
}
	printf("请输入要查找的职工号：");
	scanf("%d", &x);
	i=my_search(arr2,N,x);
	if (i == -1)
	{
		printf("对不起没有找到该职工");
	}
	else
		printf("找到了,他是%s", arr1[i]);
	return 0;
}
