#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#define N 4

int main()
{
	char arr1[N][20],*p[N],*p1=0;
	int i,j,k;
	printf("������%d���ַ�����\n",N);
	for (i = 0; i <= N - 1; i++)
	{
		scanf("%s",&arr1[i]); 
		p[i] = arr1[i];
	}
	for (i = 0; i < N -1; i++)
	{ 
		k = i;
		for (j = i + 1; j <= N - 1; j++)
		{
			if (strcmp(*(p+k), *(p+j)) < 0)
				k = j;
		}//�������ڴ˴�ʱ��������
			if (k != i)
			{
				p1 = p[i]; p[i] = p[k]; p[k] = p1;
			}		
	}
	for (i = 0; i <= N - 1; i++)
		printf("%s\n",*(p+i));
	return 0;
}
