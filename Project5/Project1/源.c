#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int main()
{
	int i, x;
	for (i = 100; i < 200; i++)
	{
		for (x = 2; x < i; x++)
		{
			if (i % x == 0)
				break;
		}
		if (x == i)
		{		printf("%d\n", i);
	}
	}
	return 0;
}
//int main()
//{
//	int i;
//	for (i = 1000; i < 2000; i++)
//	{
//		if (i % 4 == 0 && i % 100!=0 || i % 400==0)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 20, b = 40, i;
//	while (1)
//	{
//		i = b % a;
//		if (i == 0)
//		{
//			i = a;
//			break;
//		}
//		else
//			b = a; a = i;
//	}
//	printf("%d", i);
//	return 0;
//}