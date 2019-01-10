#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

#define MAX 10000
#define epsilon 0.0000000001

double f(double x){
	return (pow(x,3) / 3 - x);
}

/*****************Newton iterative*****************/

double f1(double x){
	return (pow(x,2) - 1);
}

double g(double x){
	return (x - f(x) / f1(x));
}

void Newton(double x0){
	int k;
	double x_k1, x_k0 = x0;
	for(k = 0;k < MAX;k++){
		x_k1 = g(x_k0);
		if(abs(x_k1 - x_k0) < epsilon){
			cout<<"初值 ";
			printf("%.1lf , %.13e , ",x0,x_k1);
			cout<<k + 1<<endl;
			return;
		}
		x_k0 = x_k1;
	}
	cout<<"初值 "<<x0<<" , 无根";
}

/*****************ARC*****************/

void ARC(double x_0,double x_1){		//x0 as k-1, x1 as k
	int k;
	double f1, f2;
	double x_k;  //k+1
	double x_k0 = x_0, x_k1 = x_1;
	f1 = f(x_k0);
	for(k = 2;k < MAX;k++){
		f2 = f(x_k1);
		x_k = x_k1 - ((f2 * (x_k1 - x_k0)) / (f2 - f1));		//x_k as k+1 
		if((abs(x_k - x_k1) < epsilon) || abs(f(x_k)) < epsilon){
			cout<<"初值 ";
			printf("%.1lf,%.1lf , %.13e , ",x_0,x_1,x_k);
			cout<<k + 1<<endl;
			return;
		}
		f1 = f2;
		x_k0 = x_k1;
		x_k1 = x_k;
	}
	cout<<"初值 "<<x_k0<<","<<x_k1<<" , 无根";
}

int main(){
	int i;
	double data[5] = {0.0,0.1,0.2,0.9,9.0};
	cout<<"Newton迭代，初值、根和迭代步数："<<endl;
	for(i = 1;i < 5;i++){
		Newton(data[i]);
	}
	cout<<endl;
	cout<<"弦截法，初值、根和迭代步数："<<endl;
	for(i = 0;i < 4;i++){
		ARC(data[i],data[i + 1]);
	}
}
