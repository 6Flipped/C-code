#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int main()
{
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	int low=0, high=9, mid,a;
	printf("请输入要查找的数字:");
	scanf("%d", &a);
	while (low <=high)
	{
		mid = (high + low) / 2;
		if (arr1[mid] == a)
		{
			printf("找到了，下标为：%d", mid);
			break;
		}
		if (arr1[mid] > a)
		{
			high = mid -1;
		}
		if (arr1[mid] < a)
		{
			low = mid +1;
		}
	}
	if(low>high)
		printf("没找到。");
}
//int main()
//{
//	int i, j;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//			printf("%d×%d=%d\t", j, i, i * j);
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int arr1[10],i,max;
//	printf("请输入十个整数：");
//		for (i = 0; i < 10; i++)
//			scanf("%d", arr1 + i);
//		max = arr1[0];
//		for (i = 0; i < 10; i++)
//		{
//			if (arr1[i] > max)
//				max = arr1[i];
//		}
//		printf("max=%d", max);
//	return 0;
//}
//{
//	int i;
//	double n = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//			n = n - 1.0 / i;
//		else
//			n = n + 1.0 / i;
//	}
//	printf("%g", n);
//	return 0;
//}
//int main()
//{
//	int i,n=0;
//	for (i = 0; i < 100; i++)
//	{
//		if (i % 10 == 9 || i / 10 == 9)
//			n += 1;
//	}
//	printf("%d", n);
//	return 0;
//}