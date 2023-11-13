#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n;
    int i,z,a,m=0;
    double x1=1,x2=1,y=0;

//    printf("请输入“a”（直接展开法）或“b”（递归法）或“c”（先利用2求e^x再计算倒数）确定计算e^-x的方法：\n");
//    scanf("%c", &n);
//    printf("请输入x的值：\n");
//    scanf("%d", &m);
//    if(n == 'a')

//输入
printf("开始请扣1\n");
scanf( "%d",&z);
printf("输入保留小数位数a，输入小于等于0的数以采用科学计数法\n");
scanf("%d",&a);
//开始计算
if(z==1&&a>=0)
{
for(m=0;m<=100;m+=10)
{
printf("x=%d时\n",m);
x1=1,x2=1,y=0;
    {
//第一种方法计算
        for(i=0;x1!=0;i++)
        {
            x1=1,x2=1;
            if(i==0)
            {
                x1=1;
                x2=1;
                y=0;
            }
            else
            {
            for(int j=1;j<=i;j++)
            {
                x1=x1*(-m);
                x2=x2*j;
            }
            }
            x1=x1/x2;
//            printf("x1=%.100lf\n", x1);
            y+=x1;
//            printf("y=%.*lf\n",a,y);
        }
        //if(y>1||y<0)
        //printf("a方法计算错误\n");
        //else
        if(a>0)
        printf("a方法得到e^-x=%.*lf\n",a, y);
        else
        printf("a方法得到e^-x=%e\n", y);
    }
//    else if(n == 'b')

//第二种方法计算
x1=1,x2=1,y=0;
    {
        for(i=0;x1!=0;i++)
        {
            if(i==0)
            {
                x1=1;
                x2=1;
                y=0;
            }
            else
            {
                x1=x1*(-1)*m/i;
            }
//            printf("x1=%.100lf\n", x1);
            y+=x1;
        }   
       // if(y>1||y<0)
        //printf("b方法计算错误\n");
       //else
       if(a>0)
        printf("b方法得到e^-x=%.*lf\n",a, y);
        else
        printf("b方法得到e^-x=%e\n", y);
    }
//    else if(n == 'c')

//第三种方法计算
x1=1,x2=1,y=0;
    {
        for(i=0;x1!=0;i++)
        {
            if(i==0)
            {
                x1=1;
                x2=1;
                y=0;
            }
            else
            {
                x1=x1*m/i;
            }
//            printf("x1=%.100lf\n", x1);
            y+=x1;
        }
        printf("c方法得到e^x=%.*lf\n",a, y);   
        y=1/y;
//        if(y>1||y<0)
//        printf("c方法计算错误\n");
//        else
        if(a>0)
        printf("c方法得到e^-x=%.*lf\n",a, y);
        else
        printf("c方法得到e^-x=%e\n", y);
    }
}
}
    else
    {
        printf("不算啦！\n");
    }
//    printf("e^-x=%.20lf\n", y);

    system("pause");
    return 0;
}