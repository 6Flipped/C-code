#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

//int main()
//{
//int a = 10000;
//FILE* pf = fopen("test.txt", "wb");
//fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
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
        fputs("fopen example", pFile);//�����ַ������ļ���
        fclose(pFile);
    }
    return 0;
}