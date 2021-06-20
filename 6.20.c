#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int main()
{

	return 0;
}
//{
//	int i, n,  max, min;
//	float sum=0,ave;
//	printf("请输入数字已-1结束。");
//	for (i = 1; i < 100; i++)
//	{
//		scanf("%d", &n);
//		if (i == 1)
//		{
//			max = min = n;
//		}
//		if (n == -1)
//			break;
//		else
//		{
//			sum = sum + n;
//			ave = sum / i;
//			if (max < n)
//				max = n;
//			if (min > n)
//				min = n;
//		}
//	}
//	printf("max=%d,min=%d,ave=%g", max, min, ave);
//	return 0;
//}
//{
//	int i, j;
//	printf("2\n");
//	for (i = 3; i <= 200; i++)
//	{
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (j > sqrt(i))
//			printf("%d\n",i);
//	}
//	return 0;
//}
//{
//	double f, f1, x;
//	x = 1.5;
//	f = 2 * x * x * x - 4 * x * x + 3 * x - 6;
//	f1 = 6 * x * x - 8 * x + 3;
//	while (f>1e-6&&f<1e-5)
//	{
//		x = x - f / f1;
//	}
//	printf("%g", x);
//	return 0;
//}
//{
//	int a, b, c, i;
//	for (i = 100; i < 1000; i++)
//	{
//		a = i % 10;
//		b = i / 10 % 10;
//		c = i / 100;
//		if (a * a* a + b * b * b + c * c * c == i)
//			printf("%d\n", i); 
//	}
//
//	return 0;
//}
//{
//	int i;
//	printf("请输入一个整数：");
//	scanf("%d", &i);
//	if (i % 2 == 0)
//		printf("even");
//	else
//		printf("odd");
//	return 0;
//}
//{
//	int a, b, c, x;
//	printf("请输入一个三位数：");
//	scanf("%d", &x);
//	a = x % 10;
//	b = x / 10 % 10;
//	c = x / 100;
//	printf("sum=%d\nji=%d", a + b + c, a * b * c);
//	return 0;
//}
//{
//	double h, r, c, s,v;
//	printf("请输入r，h：");
//	scanf("%lf%lf", &h, &r);
//	c = 2 * pie * r;
//	s = c * h + 2 * pie * r * r;
//	v = pie * r * r * h;
//	printf("c=%.3f\ns=%.3f\nv=%.3f",c,s,v);
//	return 0;
//}
//{
//	int mmax(int x, int y);
//	int a, b, c;
//	printf("please enter two integer numbers:");
//	scanf("%d,%d", &a, &b);
//	c = max(a, b);
//	printf("max is %d\n", c);
//	system("pause");
//	return 0;
//}
//int mmax(int x, int y)
//{
//	int z;
//	z = x > y ? x : y;
//	return z;
//}