#include<stdio.h>
#include<math.h>
void main()
{
 double x[4097],h[13],f[4097],l[4097],cha[13],S[13],he,jie[13];
 int i,j,k[13],m,n;
 for(i=0;i<4097;i++)
  {
   x[i]=1+(double)4/4096*(double)i;
   f[i]=sin(x[i]);
  }
 for(i=1;i<13;i++)
  {
   k[i]=i;
   n=(int)pow(2.00,(double)i);
   h[i]=(double)4/n;
   he=0;
   m=n/2;
   for(j=0;j<=n;j++)
    {
     l[j]=f[4096/n*j];
     he=he+h[i]*l[j]/3.00;
     if ((j!=0)&&(j!=n))
      {
       if (j%2==1) he=he+h[i]*l[j];
       else he=he+h[i]*l[j]/3.00;
      }
    }
   S[i]=he;
  }
 for(i=1;i<13;i++)
 {
  cha[i]=cos(1.00)-cos(5.00)-S[i];
  if(i>1) {jie[i]=log(fabs(cha[i-1]/cha[i]))/(log(2.00));}
 }
 for(i=1;i<13;i++)
  {
    printf("k=%d  ,  %16.14e  ,  %16.14e\n",k[i],S[i],cha[i]);
  }
}
