#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define PI 3.14159265358979

main(){
	int N[4] = {5, 10, 20, 40};
	int n;
	double x[41];
	double fx[41];
	double y[501];
	double fy[501];
	double tmp = 1.0;
	double max = 0.0;
	double sum;
	int i, j, k, m;
	double t;
	for(i = 0;i <= 500;i++){
		t = i;
		y[i] = t / 50 - 5;
		fy[i] =  1 / (1 + y[i] * y[i]);
	}
	cout<<"第1组节点误差："<<endl;
	for(k = 0;k < 4;k++){
		max = 0.0;
		n = N[k];
		/*****(1)*****/
		for(i = 0;i <= n;i++){
			t = i;
			x[i] = -5 + 10 * t / n;
			fx[i] = 1 / (1 + x[i] * x[i]);		//1/(1+x^2)
		}
		for(m = 0;m <= 500;m++){
			sum = 0.0;
			for(i = 0;i <= n;i++){
				tmp = 1.0;
				for(j = 0;j < i;j++){
					tmp = tmp * (y[m] - x[j]) / (x[i] - x[j]);
				}
				for(j = i + 1;j < n;j++){
					tmp = tmp * (y[m] - x[j]) / (x[i] - x[j]);
				}
				sum = sum + tmp * fx[i];
			}
			if(abs(sum - fy[m]) > max)	max = abs(sum - fy[m]);		//update max
		}
		printf("N=%d , %.12e\n", n, max);
	}
	cout<<endl<<"第2组节点误差："<<endl;
	for(k = 0;k < 4;k++){
		max = 0.0;
		n = N[k];
		/*****(2)*****/
		for(i = 0;i <= n;i++){
			t = i;
			x[i] = -5 * cos((2 * t + 1) * PI / (2 * n + 2));		//Chebyshev
			fx[i] = 1 / (1 + x[i] * x[i]);		//1/(1+x^2)
		}
		for(m = 0;m <= 500;m++){
			sum = 0.0;
			for(i = 0;i <= n;i++){
				tmp = 1.0;
				for(j = 0;j < i;j++){
					tmp = tmp * (y[m] - x[j]) / (x[i] - x[j]);
				}
				for(j = i + 1;j < n;j++){
					tmp = tmp * (y[m] - x[j]) / (x[i] - x[j]);
				}
				sum = sum + tmp * fx[i];
			}
			if(abs(sum - fy[m]) > max)	max = abs(sum - fy[m]);		//update max
		}
		printf("N=%d , %.12e\n", n, max);
	}
}
