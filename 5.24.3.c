#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int main()
{
	int m, n, i,num1,num2;
	printf("����������������");
	scanf("%d %d", &m, &n);
	if (n > m)
	{
		i = m; m = n; n = i;
	}
	num1 = m; num2 = n;
	while (i != 0)
	{
		i = num1% num2;
		num1= num2;
		num2 = num1;
	}
	printf("���Լ��Ϊ��%d\n��С������Ϊ��%d", num2,m*n/num2);
	return 0;
}
