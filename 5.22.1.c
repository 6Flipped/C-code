#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 200
int main()
{
	char arr1[N],arr2[N][10];
	int i=0,num=0,j=0,m=0;
	gets(arr1);
	while (arr1[i] != '\0')//���㵥�ʸ�������д�׸���ĸ
	{
		if (i == 0)//���ַ����⴦��
		{
			if (arr1[i] == ' ')
			{	i++; continue;
		}
			if (arr1[i] != ' ')
			{
				if (arr1[i] > 'a' && arr1[i] < 'z')//����ĸ�ǿո�Сдת��д
					arr1[i] -= 32;
				num++; i++; continue;
			}
		}
		if (arr1[i] >= 'a' && arr1[i] <= 'z' || arr1[i] >= 'A' && arr1[i] <= 'Z')
		{
			if (arr1[i - 1] == ' ')//��ǰ����ĸǰһ��������ĸ��Ϊ�µ��ʿ�ʼ
			{	num++;
			{
				if (arr1[i] >= 'a' && arr1[i] <= 'z')//�µ�������ĸСдת��д
					arr1[i] -= 32; }
			}
		}
		i++;
	}
	for (i = 0; arr1[i] != '\0'; i++)//��ÿ�����ʷ���arr2[]�б���
	{
		if (arr1[i] != ' ')
		{
			arr2[j][m] = arr1[i];
			m++;
		}
		else
		{
			if (i == 0)//����ĸΪ�ո�ʱ�����κβ���
			{
				continue;
			}
			if (arr1[i - 1] != ' ')//��ǰλΪ�ո��ǰһλ���ǿո��ֶ����\0������ʶ
			{	arr2[j][m] = '\0';
			m = 0;
			j++;
		}
	}
}
	arr2[j][m] = '\0';//�˳�ѭ�����ֶ����\0������ʶ
	printf("��%d������\n", num);
	for(i=0;i<=num-1;i++)
	printf("%d.%s\n", i+1,arr2[i]);
	return 0;
}