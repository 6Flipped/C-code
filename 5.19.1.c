/**
* @brief ��ʵ�Գƾ��������ֵ�������������ſ˱ȷ� 
* �����Ÿ��(Jacobi)������ʵ�Գƾ����ȫ������ֵ���������� 
**/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 3  //��������� ����
#define eps  10e-10//ΪҪ��ľ���
#define N  100000//����������

//����Ԥ����
void scanfMatrix(double a_ori[][3],double a[][3], int m, int n);//���������
void printMatrix(double a[][3], int m, int n);//����Ĵ�ӡ
void iniVector(double a_Vec[][M], int m);//�����ĳ�ʼ��

//������
int main(void)
{
	double a_ori[M][M] = { { 6, -12, 6 }, { -21, -3, 24 }, { -12, -12, 51 } };//��������ֵ�����������ľ���;
    double a[M][M]= {{ 6, -12, 6 }, { -21, -3, 24 }, { -12, -12, 51 } };//���ݾ��� 
    double a_Vec[M][M];//����������������
    double a_Eig[M];// //����ֵ��������

	int i,j,time_in;
    
	//printf("����%d*%d�ľ���A:\n",M, M);
	//scanfMatrix(a_ori,a, M, M);
    printf("��������ֵ�����������ľ���A:\n");
    printMatrix(a, M, M);
    printf("\n");
    iniVector(a_Vec, M);

    printf("\n");
	time_in=0;
    while (1) 
    { 
		int i,j,p,q,u,w,t,s,l; 
        double fm,cn,sn,omega,x,y,d; 
		
		//��a�ķǶԽ������ҵ����Ԫ��
		fm=fabs(a[0][1]);
		p=0;
		q=1;
		for (i = 0; i < M; i ++)			//��
		{
			for (j = 0; j < M; j ++)		//��
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

		
		//������������
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
		printf("��������\n");
		return;
	}

	printf("����ֵΪ:\n");
	for(i = 0; i < M; i ++) 
	{   
		a_Eig[i] = a[i][i]; 
		printf("%lf ",a_Eig[i]);
		
	} 
	printf("\n�ԽǾ���Ϊ:\n");
	printMatrix(a,M,M);

	printf("\n������%d��\n",time_in);

    system("pause");
}

//��������ִ��
//���������
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
//����Ĵ�ӡ
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
//�����ĳ�ʼ��
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
