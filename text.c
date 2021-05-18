#include<stdio.h>
#define N 20
void strcat(char a[], char b[])
{
	int i=0, j;
	while (a[i] != '\0')
	{
		i++;
	}
	for (j = 0;; j++, i++)
	{
		a[i] = b[j];
		if (b[j] == '\0')
		break;
	}
	a[i] = '\0';
}
int main()
{
	char s1[N], s2[N];
	gets(s1); gets(s2);
	strcat(s1,s2);
	puts(s1);
}