#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

//     my_search(arr1, n - 1);
void my_search(float(*p)[4], int m)
//*p[4]��ʾָ�����飬�������麬��*p[0]-*p[3]4��ָ�룬��˴���*p)[4]�������
{
	int i;
	printf("No.%d\n", m+1);
	for (i = 0; i <4; i++)
	{
		printf("%g\n", *(*(p+m)+i));
		//�˴�p����arr1����p+m=arr1+m,*(p+m)=arr1[m],*(*(p+m)+i)=*(arr1[m]+i)=arr1[m][i]��
	}
}

void my_ave(float *s1,int a)
//s1����arr1[0],*(s1+i)ʵ��Ϊ*��arr1[0]+i)��Ϊarr1[0][i]��
{
	float sum = 0, ave;
	int i;
	for (i = 0; i < a; i++)
		sum = sum + (*(s1 + i));
	ave = sum / a;
	printf("ȫ���ܷ�Ϊ��%g��ƽ����Ϊ��%g\n",sum,ave);
}

int main()
{
	float arr1[3][4] = { {65,67,79,60},{80,87,90,81},{90,99,100,98} };
	int n;
	my_ave(*arr1,12);//*arr1ʵ��Ϊarr1[0]
		printf("������Ҫ��ѯ�ڼ�λͬѧ�ɼ���");
		scanf("%d", &n);
	my_search(arr1,n-1);
	return 0;
}
