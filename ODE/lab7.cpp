#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

#define f(x,y) (-x*x*y*y)
main(){
	int m, i, j;
	double H[4] = {0.1,0.05,0.025,0.0125};
	double a, b, y0;
	double xn, yn, yn1;
	double k1, k2, k3, k4;
	double h;
	a = 0;
	b = 1.5;
	y0 = 3;
	double ans = 3/(1+1.5*1.5*1.5);
	double e[4];
	for(i = 0;i < 4;i++){
		h = H[i];
		m = (b - a) / h;
		xn = a;
		yn = y0;
		for(j = 0;j < m;j++){
			k1 = f(xn,yn);
			k2 = f((xn+h/2),(yn+h*k1/2));
			k3 = f((xn+h/2),(yn+h*k2/2));
			k4 = f((xn+h),(yn+h*k3));
			yn1 = yn + h/6*(k1+2*k2+2*k3+k4);
			xn += h;
			yn = yn1; 
		}
		cout<<"步长："<<h<<" , ";
		printf("%.12e , ",abs(ans - yn));
		e[i] = abs(ans - yn);
		printf("%.12e\n",log(e[0] / e[i]) / log(H[0] / H[i]));
	}
}
