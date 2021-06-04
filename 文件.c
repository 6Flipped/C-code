#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

//int main()
//{
//int a = 10000;
//FILE* pf = fopen("test.txt", "wb");
//fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
//fclose(pf);
//pf = NULL;
//return 0;
//}

int main()
{
    FILE* pFile;
    pFile = fopen("myfile.txt", "w");
    if (pFile != NULL)
    {
        fputs("fopen example", pFile);//输入字符串到文件中
        fclose(pFile);
    }
    return 0;
}