#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int isprime(int x)
{
	int i;
	if (x <= 2)
		return 1;
	for (i = 2; i <x; i++)
	{
		if (x % i == 0)
			return 0;
	}
	if (i == x)
		return 1;
}

int main()
{
	int m, n,k,sum=0;
	printf("��������������1��������");
	scanf("%d %d", &m, &n);
	if (n > m)
	{
		 k = m; m = n;n = k;
	}
	for (n; n <= m; n++)
	{
		if ((isprime(n)) == 1)
			sum += n;
	}
	printf("���������������Ϊ��%d",sum);
	return 0;
}
