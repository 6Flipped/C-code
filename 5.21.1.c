#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 200
int main()
{
	char arr1[N];
	int i = 0, num= 0;
	gets(arr1);
	while (1)
	{
		if (arr1[i] == '\0')
			break;
		else
			num++;
		i++;
	}
	printf("×Ö·û´®³¤¶ÈÎª£º%d", num);
	return 0;
}
