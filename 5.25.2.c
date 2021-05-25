#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

//     my_search(arr1, n - 1);
void my_search(float(*p)[4], int m)
//*p[4]表示指针数组，即该数组含有*p[0]-*p[3]4个指针，与此处（*p)[4]差别甚大。
{
	int i;
	printf("No.%d\n", m+1);
	for (i = 0; i <4; i++)
	{
		printf("%g\n", *(*(p+m)+i));
		//此处p接收arr1，即p+m=arr1+m,*(p+m)=arr1[m],*(*(p+m)+i)=*(arr1[m]+i)=arr1[m][i]。
	}
}

void my_ave(float *s1,int a)
//s1接收arr1[0],*(s1+i)实则为*（arr1[0]+i)即为arr1[0][i]。
{
	float sum = 0, ave;
	int i;
	for (i = 0; i < a; i++)
		sum = sum + (*(s1 + i));
	ave = sum / a;
	printf("全体总分为：%g，平均分为：%g\n",sum,ave);
}

int main()
{
	float arr1[3][4] = { {65,67,79,60},{80,87,90,81},{90,99,100,98} };
	int n;
	my_ave(*arr1,12);//*arr1实则为arr1[0]
		printf("请输入要查询第几位同学成绩：");
		scanf("%d", &n);
	my_search(arr1,n-1);
	return 0;
}
