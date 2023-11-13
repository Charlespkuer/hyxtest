#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,as=1;
//输入矩阵阶数并进行基本判断
    printf("请输入矩阵A阶数n：\n");
    scanf("%d", &n);
    int mat[n][n] = {0};
    if(n<=0)
    {
        printf("输入错误！\n");
        system("pause");
        return 0;
    }
    else
    {
//构造矩阵A
        for(int i=0;i<n;i++)
        {
            mat[i][i]=1;
            for(int j=i+1;j<n;j++)
            {
                mat[i][j]=-1;
            }
            for(int k=0;k<i;k++)
            {
                mat[i][k]=0;
            }
        }

/*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
*/

//计算矩阵A行列数并判断是否为奇异矩阵
        for(int i=0;i<n;i++)
        {
            as*=mat[i][i];
        }
        printf("(a)\n矩阵A行列式为：%d\n", as);    
        if(as!=0)
        printf("由于矩阵A行列式不为0，故A不为奇异矩阵\n");
        else
        printf("由于矩阵A行列式为0，故A为奇异矩阵\n");

//可利用高斯法求解矩阵A的逆矩阵（手算过程，给出结果）
        int mat1[n][n]={0};
        for(int i=0;i<n;i++)
        {
            mat1[i][i]=1;
            for(int j=i+1;j<n;j++)
            {
                int temp=1;
                for(int l=0;l<j-i-1;l++)
                {
                    temp*=2;
                }
                mat1[i][j]=temp;
            }
            for(int k=0;k<i;k++)
            {
                mat1[i][k]=0;
            }
        }

//输出逆矩阵A^-1
        printf("(b)\n矩阵A的逆矩阵为：\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ", mat1[i][j]);
            }
            printf("\n");
        }

//简答第三问
        printf("(c)、(d)、(e)\n见pdf文档\n");


    }
    
    system("pause");
    return 0;
}