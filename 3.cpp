#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include <iostream>


int GEM(int m,int a)
{
    double x[m]={0};
    double H[m][m+1]={0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            H[i][j]=1.0/(i+j+1);
        }
    }
    for(int i=0;i<m;i++)
    {
        H[i][m]=1;
    }//构造增广矩阵H

    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            for(int k=m;k>=i;k--)
            {
                H[j][k]=H[j][k]-H[i][k]*H[j][i]/H[i][i];
            }
        }
    }//完成高斯消元

    for(int i=m-1;i>=0;i--)
    {
        for(int j=m-1;j>i;j--)
        {
            H[i][m]=H[i][m]-H[i][j]*x[j];
        }
        x[i]=H[i][m]/H[i][i];
    }//回代求解

    printf("x={ ");
    for(int i=0;i<m;i++)
    if(a>0)
    printf("%.*lf ",a,x[i]);
    else
    printf("%e ",x[i]);
    printf("}\n");
    return 0;
}

int Choleskey(int m,int a)
{
    double x[m]={0},temp,b[m]={0},y[m]={0};
    double H[m][m]={0},C[m][m]={0},C1[m][m]={0};

    for(int i=0;i<m;i++)
    b[i]=1.0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            H[i][j]=1.0/(i+j+1);
        }
    }//构造矩阵H
    C[0][0]=sqrt(H[0][0]);
    for(int i=1;i<m;i++)
    {
        temp=0;
        for(int j=0;j<i;j++)
        {
            C[j][i]=0;
            C[i][j]=H[i][j];
            for(int k=0;k<j;k++)
            {
                C[i][j]-=C[i][k]*C[j][k];
            }
            C[i][j]/=C[j][j];
        }
        for(int j=0;j<i;j++)
        {
            temp+=C[i][j]*C[i][j];
        }
        C[i][i]=sqrt(H[i][i]-temp);
    }//完成Choleskey分解


//解方程Cy=b
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<i;j++)
        {
            b[i]-=C[i][j]*y[j];
        }
        y[i]=b[i]/C[i][i];
    }



//构造C^T矩阵C1
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            C1[i][j]=C[j][i];
        }
    }

//解方程C^Tx=y
    for(int i=m-1;i>=0;i--)
    {
        for(int j=m-1;j>i;j--)
        {
            y[i]-=C1[i][j]*x[j];
        }
        x[i]=y[i]/C1[i][i];
    }

    printf("x={ ");
    for(int i=0;i<m;i++)
    if(a>0)
    printf("%.*lf ",a,x[i]);
    else
    printf("%e ",x[i]);
    printf("}\n\n");
    return 0;
}


int main()
{
    int i,j,n,a,a1;
    double H1=0,H2=0,H;
    printf("(a)、(b)问详见pdf文档\n");
    printf("(c)\n输入1-10之间的整数n以计算H_n，输入其它数以跳过此问\n");
    scanf("%d",&n);
    if(n<1||n>10)
    {
        printf("跳过计算！\n");
    }
    else
    {
        printf("输入保留小数位数a，输入小于等于0的数以采用科学计数法\n");
        scanf("%d",&a1);
        if(n==1)
        {
            H=1.0;
        }
        else
        {
        for(i=2;i<n;i++)
        {
            H1+=(n-i)*log(i);
//            printf("%lf\n",H1);
        }
        for(i=2;i<2*n;i++)
        {
            H2+=(2*n-i)*log(i);
//            printf("%lf\n",H2);
        }
        H1=4*H1;
        H=exp(H1)*exp(-H2);
        }
        if(a>0)
        printf("H_%d=%.*lf\n",n,a1,H);
        else
        printf("H_%d=%e\n",n,H);
    }
    printf("(d)\n");
    printf("输入保留小数位数a，输入小于等于0的数以采用科学计数法\n");
    scanf("%d",&a);
    int m;
    //printf("输入要计算的最大阶数\n");
    //scanf("%d",&m);
    for(n=1;n<=10;n++)
    {
        printf("n=%d时\n",n);
        printf("使用GEM算法得到解为\n");
        GEM(n,a);
        printf("使用Choleskey算法得到解\n");
        Choleskey(n,a);
    }

    system("pause");
    return 0;
}