#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int max(int m, int n)
{
	if (m > n)
		return m;
	else
		return n;
}
﻿﻿
; int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	a = max(a, b);
	printf("max=%d", a);
	return 0;
}