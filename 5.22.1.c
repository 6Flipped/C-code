#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#define N 200
int main()
{
	char arr1[N],arr2[N][10];
	int i=0,num=0,j=0,m=0;
	gets(arr1);
	while (arr1[i] != '\0')//计算单词个数并大写首个字母
	{
		if (i == 0)//首字符特殊处理
		{
			if (arr1[i] == ' ')
			{	i++; continue;
		}
			if (arr1[i] != ' ')
			{
				if (arr1[i] > 'a' && arr1[i] < 'z')//首字母非空格小写转大写
					arr1[i] -= 32;
				num++; i++; continue;
			}
		}
		if (arr1[i] >= 'a' && arr1[i] <= 'z' || arr1[i] >= 'A' && arr1[i] <= 'Z')
		{
			if (arr1[i - 1] == ' ')//当前是字母前一个不是字母则为新单词开始
			{	num++;
			{
				if (arr1[i] >= 'a' && arr1[i] <= 'z')//新单词首字母小写转大写
					arr1[i] -= 32; }
			}
		}
		i++;
	}
	for (i = 0; arr1[i] != '\0'; i++)//将每个单词放入arr2[]中保存
	{
		if (arr1[i] != ' ')
		{
			arr2[j][m] = arr1[i];
			m++;
		}
		else
		{
			if (i == 0)//首字母为空格时不做任何操作
			{
				continue;
			}
			if (arr1[i - 1] != ' ')//当前位为空格而前一位不是空格，手动添加\0结束标识
			{	arr2[j][m] = '\0';
			m = 0;
			j++;
		}
	}
}
	arr2[j][m] = '\0';//退出循环后手动添加\0结束标识
	printf("有%d个单词\n", num);
	for(i=0;i<=num-1;i++)
	printf("%d.%s\n", i+1,arr2[i]);
	return 0;
}