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
		}//�ҵ���СԪ�ص��±�
		if (k != i)
		{
			j= s[i]; s[i] = s[k]; s[k] = j;//�������Ԫ�غ���СԪ��
		}
	}

}

int main()
{
	int arr1[N];
	int i;
	printf("������%d��������", N);
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
