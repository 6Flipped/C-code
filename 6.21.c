#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#define N 50

int main()
{
	char s1[N],s2[N][20];
	int i;
	printf("������һ���ַ�����");
	gets(s1);
	for (i = 0; i < N; i++)
	{
		if(s1[i]!=" "&&i==0)
	}
	return 0;
}
//{
//	char s1[N];
//	int i,n=0;
//	printf("������һ���ַ�����");
//	gets(s1);//scanf�Կո�Ϊ������־������scanf����ʱ�ո�����ַ�����
//	for (i = 0; i < N; i++)
//	{
//		if (s1[i]!='\0')//�ַ�������ʹ��strcmp�����������ַ���ʹ��=��ֱ�ӱȽ�
//			//��Ҫע����ǣ�strcmp������ʵ���������ַ���ָ�롣
//			n++;
//		else
//			break;
//	}
//	printf("%d", n);
//	return 0;
//}
//{
//	int N = 10;
//	int arr1[10] = { 1,2,3,4,5,6,8,8,9,10 };
//	int x,low,high,mid,i;
//	printf("��������Ҫ��ӵ�����");
//	scanf("%d", &x);
//	low = mid = 0; high = 9;
//	while (low <= high)
//	{
//		mid = (high + mid) / 2;
//		if (arr1[mid]<x&&arr1[mid+1]>x||arr1[mid] == x)
//			break;
//		if (arr1[mid] > x)
//			high = mid - 1;
//		if (arr1[mid] < x)
//			low = mid + 1;
//	}
//	if (low > high)
//		printf("û�ҵ�");
//	else
//		N = N + 1;
//		for (i= N-1; i>= mid; i--)
//		{
//			arr1[i] = arr1[i - 1];
//		}
//	arr1[mid] = x;
//	for (x = 0; x < N; x++)
//		printf("%d\n", arr1[x]);
//	return 0;
//}
//{
//	int arr1[N] = { 1,2,3,4,5,6,7,8,9,10 };
//	int x;
//	int low, high, mid;
//	printf("��������Ҫɾ��������");
//	scanf("%d", &x);
//	low =mid= 0; high = 9;
//	while (low <= high)
//	{
//		mid = (high + mid) / 2;
//		if (arr1[mid] == x)
//			break;
//		if (arr1[mid] > x)
//			high = mid - 1;
//		if (arr1[mid] < x)
//			low = mid + 1;
//	}
//	if (low > high)
//		printf("û�ҵ�");
//	else
//	for (x = mid; x < N; x++)
//		arr1[x] = arr1[x + 1];
//	for (x = 0; x < N-1; x++)
//		printf("%d\n", arr1[x]);
//	return 0;
//}
