/**
* @brief 求实对称矩阵的特征值及特征向量的雅克比法 
* 利用雅格比(Jacobi)方法求实对称矩阵的全部特征值及特征向量 
**/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 3  //方阵的行数 列数
#define eps  10e-10//为要求的精度
#define N  100000//最大迭代次数

//函数预声明
void scanfMatrix(double a_ori[][3],double a[][3], int m, int n);//矩阵的输入
void printMatrix(double a[][3], int m, int n);//矩阵的打印
void iniVector(double a_Vec[][M], int m);//向量的初始化

//主函数
int main(void)
{
	double a_ori[M][M] = { { 6, -12, 6 }, { -21, -3, 24 }, { -12, -12, 51 } };//待求特征值和特征向量的矩阵;
    double a[M][M]= {{ 6, -12, 6 }, { -21, -3, 24 }, { -12, -12, 51 } };//备份矩阵 
    double a_Vec[M][M];//特征向量迭代向量
    double a_Eig[M];// //特征值迭代向量

	int i,j,time_in;
    
	//printf("输入%d*%d的矩阵A:\n",M, M);
	//scanfMatrix(a_ori,a, M, M);
    printf("待求特征值和特征向量的矩阵A:\n");
    printMatrix(a, M, M);
    printf("\n");
    iniVector(a_Vec, M);

    printf("\n");
	time_in=0;
    while (1) 
    { 
		int i,j,p,q,u,w,t,s,l; 
        double fm,cn,sn,omega,x,y,d; 
		
		//在a的非对角线上找到最大元素
		fm=fabs(a[0][1]);
		p=0;
		q=1;
		for (i = 0; i < M; i ++)			//行
		{
			for (j = 0; j < M; j ++)		//列
			{
				d = fabs(a[i][j]); 
 
				if((i!=j) && (d> fm )) 
				{ 
					fm=d; 
                    p=i; 
                    q=j; 
				} 
			}
		}
		
		if (fm<eps) 
        { 
            break; 
        } 

        time_in++;
		if(time_in>10000)
			break;

        x=-a[p][q]; 
        y=(a[q][q]-a[p][p])/2.0; 
        omega=x/sqrt(x*x+y*y); 
        if (y<0.0) 
        { 
            omega=-omega; 
        } 

        sn=1.0+sqrt(1.0-omega*omega); 
        sn=omega/sqrt(2.0*sn); 
        cn=sqrt(1.0-sn*sn); 
        fm=a[p][p]; 
        a[p][p]=fm*cn*cn+a[q][q]*sn*sn+a[p][q]*omega; 
        a[q][q]=fm*sn*sn+a[q][q]*cn*cn-a[p][q]*omega; 
        a[p][q]=0.0; 
        a[q][p]=0.0; 

        for (j=0; j<M; j++) 
        { 
            if ((j!=p)&&(j!=q)) 
            { 
 
                fm=a[p][j]; 
                a[p][j] = fm*cn+a[q][j]*sn; 
                a[q][j] =-fm*sn+a[q][j]*cn; 
            } 
        } 

        for (i=0; i<M; i++) 
        { 
            if ((i!=p)&&(i!=q)) 
            { 

                fm = a[i][p]; 
                a[i][p] = fm*cn+a[i][q]*sn; 
                a[i][q] = -fm*sn+a[i][q]*cn; 
            } 
        } 

		
		//计算特征向量
		for(
			i = 0; i < M; i ++) 
		{ 

			fm = a_Vec[i][p]; 
			a_Vec[i][p] = fm*cn+a_Vec[i][q]*sn; 
			a_Vec[i][q] = -fm*sn+a_Vec[i][q]*cn; 
		} 

    }
	if(time_in>10000)
	{
		printf("矩阵不收敛\n");
		return;
	}

	printf("特征值为:\n");
	for(i = 0; i < M; i ++) 
	{   
		a_Eig[i] = a[i][i]; 
		printf("%lf ",a_Eig[i]);
		
	} 
	printf("\n对角矩阵为:\n");
	printMatrix(a,M,M);

	printf("\n迭代了%d次\n",time_in);

    system("pause");
}

//函数具体执行
//矩阵的输入
void scanfMatrix(double a_ori[][3],double a[][3], int m, int n)
{
	int i,j;
    for (i = 0; i<m; i++)
    {
        for (j = 0; j<n; j++)
        {
            scanf("%f", &a_ori[i][j]);
			a[i][j]=a_ori[i][j];
        }
        printf("\n");
    }
}
//矩阵的打印
void printMatrix(double a[][M], int m, int n)
{
	int i,j;
    for (i = 0; i<m; i++)
    {
        for (j = 0; j<n; j++)
        {
            printf("%lf  ", a[i][j]);
        }
        printf("\n");
    }
}
//向量的初始化
void iniVector(double a_Vec[][M], int m)
{
	int i,j;
	for(i = 0; i < m; i ++) 
	{   
		for(j = 0; j < m; j ++) 
		{
			if(i != j)   
				a_Vec[i][j]=0.0f; 
			else
				a_Vec[i][j] = 1.0f; 
		} 
	} 
}
