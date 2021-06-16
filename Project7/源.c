#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>

int main()
{
	printf("%d", sizeof(long int));
	/*
	int n;
	double a, b, c;
	scanf("%d%lf%lf%lf", &n, &a, &b, &c);
	printf("The each subject score of  No.%d is %g,%g,%g.",n,a,b,c);*/
	return 0;
}

//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	printf("score1=%d score2=%d score3=%d", a, b, c);
//	return 0;
//}

//int main()
//{
//	int ret;
//	ret = printf("Hello world!");
//	printf("\n");
//	printf("%d", ret);
//	return 0;
//}

//int main()
//{
//    printf("%15d", 0xABCDEF);
//    return 0;
//}

//int main()
//{
//    printf("%#0o %#0X", 1234, 1234);
//    return 0;
//}


//int main()
//{
//	int a, b, c, d, x;
//	printf("请输入一个整数：");
//	scanf("%d", &x);
//	if (x > 0 && x < 999)
//	{
//		a = x % 10;//个位数
//		b = x / 10 % 10;//十位数
//		c = x / 100;//百位数
//		if (a * a * a + b * b * b + c * c * c == x)
//		{
//			printf("narcissistic");
//			return 0;
//		}
//	}
//	if (x > 999 && x < 9999)
//	{
//		a = x % 10;//个位数
//		b = x / 10 % 10;//十位数
//		c = x / 100 % 10;//百位数
//		d = x / 1000;//千位数
//		if (a * a * a * a + b * b * b * b + c * c * c * c + d * d * d * d == x)
//		{
//			printf("rose");
//			return 0;
//		}
//	}
//	printf("neither");
//	return 0;
//}
//
//a, b, c = list(map(int, input().split()))
//r1 = max(a, b, c)
//r3 = min(a, b, c)
//if a <= r1 and a >= r3:
//r2=a
//if b<r1 and b>=r3:
//	r2=b
//	if c<r1 and c>r3:
//		r2=c
//		print(r1,r2,r3)