#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 20

int main()
{
    int arr1[N], sum = 0, n = 7, a = 0, i;
    double ave;
    printf("������%d������:", n);
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr1[i]);
        sum = sum + arr1[i];
    }
    ave = sum / n;
    for (i = 0; i <= n - 1; i++)
    {
        if (arr1[i] > ave)
            a++;
    }
    printf("ƽ����Ϊ��%g\n��%d��������ƽ����",ave,a);
    return 0;
}
