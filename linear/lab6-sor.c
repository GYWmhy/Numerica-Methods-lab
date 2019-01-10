#include<stdio.h>
#include<math.h>
double MAX(double *x1,double *x2)
{
	double temp;
    int i;
    temp=fabs(x1[0]-x2[0]);
    for(i=1;i<9;i++)
    {
          if(temp<fabs(x1[i]-x2[i]))
           temp=fabs(x1[i]-x2[i]);
    }
    return temp;
}
void gauss(double A[][9],double *Y,double *&x)
{
    int i,j,n=0;
    double b[9][9],g[9],x1[9],x2[9],s;
    for(i=0;i<9;i++)
    {
        x1[i]=0;
        x2[i]=1;
        g[i]=Y[i]/A[i][i];
        for(j=0;j<9;j++)
            b[i][j]=-A[i][j]/A[i][i];
        b[i][i]=0;
    }
	while (MAX(x1,x2)>10e-8)
    {
        for(i=0;i<9;i++)
            x1[i]=x2[i];
        for(i=0;i<9;i++)
        {
            s=g[i];
            for(j=0;j<9;j++)
            {
                s+=b[i][j]*x2[j];
            }
            x2[i]=s;
        }
		n++;
    }
    for(i=0;i<9;i++)
       {
           x[i]=x2[i];
       }
}
void SOR(double A[][9],double *Y,int &n,double w,double &t,double *x)
{
    int i,j;
    double b[9][9],g[9],x1[9],x2[9],s;
    for(i=0;i<9;i++)
    {
        x1[i]=0;
        x2[i]=1;
        g[i]=Y[i]/A[i][i];
        for(j=0;j<9;j++)
            b[i][j]=-A[i][j]/A[i][i];
        b[i][i]=0;
    }
    while (MAX(x1,x2)>10e-8)
    {
        for(i=0;i<9;i++)
            x1[i]=x2[i];
        for(i=0;i<9;i++)
        {
            s=g[i];
            for(j=0;j<9;j++)
            {
                s+=b[i][j]*x2[j];
            }
            x2[i]=w*s+(1-w)*x1[i];
        }
		n++;
    }
   for(i=0;i<9;i++)
      {
          t+=fabs(x[i]-x2[i]);
    }
    printf("松弛因子为 %lf迭代次数为 %d 误差为%16.14e\n",w,n,t);
}
int main()
{
    double a[9][9]={ {31,-13,0,0,0,-10,0,0,0},
           {-13,35,-9,0,-11,0,0,0,0},
           {0,-9,31,-10,0,0,0,0,0},
           {0,0,-10,79,-30,0,0,0,-9},
           {0,0,0,-30,57,-7,0,-5,0},
           {0,0,0,0,-7,47,-30,0,0},
           {0,0,0,0,0,-30,41,0,0},
           {0,0,0,0,-5,0,0,27,-2},
           {0,0,0,-9,0,0,0,-2,29}},
           b[9]={-15,27,-23,0,-20,12,-7,7,10},x[9]={0},*p=x;
	int i, j;
    gauss(&a[0],b,p);
    double w[99],t[99];
    int n[99];
    for(i=0;i<99;i++)
    {
        w[i]=((double)i+1)/50;
        n[i]=0;
        t[i]=0;
    }
    printf("SOR迭代计算结果如下:\n");
    for(i=0;i<99;i++)
        SOR(&a[0],b,n[i],w[i],t[i],x);
    int nmin;
    double tmin;
    int c=0,d=0;
    nmin=n[0];
    tmin=t[i];
    for(i=1;i<99;i++)
    {
        if(n[i]<nmin)
            {
                nmin=n[i];
                c=i;
            }
        if(t[i]<tmin)
        {
            tmin=t[i];
            d=i;
        }
    }
    printf("迭代步数最少，最佳松弛因子应为%lf\n",w[c] );
    printf("最小误差，最佳松弛因子应为%lf\n",w[d]);
    return 1;
}
