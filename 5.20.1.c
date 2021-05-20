#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

void swap(int * p1, int * p2)
{
	int i;
		i = *p1;
		*p1 = *p2;
		*p2 = i;
}

int main()
{
	int a, b;
	int *max, *min;
	max = &a; min = &b;
	printf("«Î ‰»Îa£¨b£∫");
	scanf("%d %d", &a, &b);
	if(a<b)swap(max, min);
	printf("max=%d,min=%d", a, b);
	return  0;
}
