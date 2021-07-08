#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int main()
{
	int arr[4][4] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	int i, j, x;
	int flag = 0;
	printf("请输入你要查找的数字：");
	scanf("%d", &x);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (arr[i][j] == x)
			{
				flag = 1;
				printf("找到了,在第%d行第%d列\n",i+1,j+1);
				break;
			}
			else if (arr[i][j] > x)
				break;
		}
		if (*arr[i] > x)
			break;
	}
	if (flag == 0)
		printf("没找到。\n");
	return 0;
}