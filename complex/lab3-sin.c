#include<stdio.h>
#include<math.h>
void main()
{
 double x[4097],h[13],f[4097],l[4097],cha[13],I[13],he,jie[13];
 int i,j,k[13],n;
 for(i=0;i<4097;i++)
  {
   x[i]=1+(double)4/4096*(double)i;
   f[i]=sin(x[i]);
  }
 I[0]=2*(f[0]+f[4096]);
 for(i=0;i<13;i++)
  {
   k[i]=i;
   n=(int)pow(2.00,(double)i);
   h[i]=(double)4/n;
   he=0;
   if(i>0)
   {
    for(j=0;j<=n;j++)
     {
      l[j]=f[4096/n*j];
      he=he+h[i]*l[j];
     }
    I[i]=he-0.5*h[i]*(f[0]+f[4096]);
   }
  }
 for(i=0;i<13;i++)
 {
  cha[i]=cos(1.00)-cos(5.00)-I[i];
  if(i>0) {jie[i]=log(fabs(cha[i-1]/cha[i]))/(log(2.00));}
 }
 for(i=0;i<13;i++)
  {
   printf("k=%d  ,  %16.14e  ,  %15.13f\n",k[i],cha[i],jie[i]);
  }
}
