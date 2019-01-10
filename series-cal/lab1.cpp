#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

double calculate(double x){
	int k;
	double sum;
	for(k = 1, sum = 0;k <= 100000000;k++){
		sum += 1/(k * (k + x));
	}
	sum += 1/(k * (k + x));
	return sum;
}

int main(){
	double size[7] = {0, 0.5, 1, sqrt(2), 10, 100, 300};
	int i;
	double ans;
	for(i = 0;i < 7;i++){
		ans = calculate(size[i]);
		printf("  %.2lf , %.13e\n",size[i],ans);
	}
}
