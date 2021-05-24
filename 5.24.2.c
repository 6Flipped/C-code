#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int main()
{
	int m;
	for (m = 10; m <= 1000; m++)
	{
		if (m % 2 == 0)
			if (m % 3 == 0)
				if (m % 7 == 0)
					printf("%d\n", m);
	}
	return 0;
}
