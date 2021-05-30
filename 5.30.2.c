#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#define N 3

int main()
{
	char  s1[N][20], * p[N], * p1=0;
	int i, j, k;
	printf("ÇëÊäÈë%d¸ö×Ö·û´®£º", N);
	for (i = 0; i <= N - 1; i++)
	{
		scanf("%s",s1[i]);p[i] = s1[i];
	}
	for (i = 0; i < N - 1; i++)
	{
		k = i;
		for (j = i + 1; j < N; j++)
		{
			if (strcmp(p[k], p[j]) > 0)
				k = j;
		}
		p1 = p[k]; p[k] = p[i]; p[i] = p1;
	}
	for (i = 0; i <= N - 1; i++)
		printf("%s\n", *(p + i));
	return 0;
}