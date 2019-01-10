#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAX 10

double matrix[MAX][MAX + 1] = {{0,0}};
double answer[MAX] = {0};

void exchange(int x, int y, int n){
	int i;
	double temp;
	for(i = 0;i < n + 1;i++){
		temp = matrix[x][i];
		matrix[x][i] = matrix[y][i];
		matrix[y][i] = temp;
	}
}

bool Gauss(int n){
	int i, j, k, m;
	double times;
	for(i = 0;i < n;i++){
		if(matrix[i][i] == 0){
			for(k = i;k < n;k++){
				if(matrix[k][i] != 0){
					exchange(i,k,n);
					break;
				}
			}
			if(k == n)	return false;
		}
		times = matrix[i][i];
		for(j = i;j < n + 1;j++){
			matrix[i][j] /= times;
		}
		for(k = 0;k < n;k++){
			if(k == i)	continue;
			else{
				times = matrix[k][i];
				for(m = i;m < n + 1;m++){
					matrix[k][m] -= times * matrix[i][m];
				}
			}
		}
	}
	for(i = 0;i < n;i++){
		if(matrix[i][i] != 1)	return false;
		for(j = 0;j < n;j++){
			if(i == j)	continue;
			else{
				if(matrix[i][j] != 0)	return false;
			}
		}
	}
	for(i = 0;i < n;i++)	answer[i] = matrix[i][n];
	return true;
}

int main(){
	int n, i, j;
	FILE *fp = fopen("input.txt","r");
	n = 9;
	for(i = 0;i < n;i++){
		for(j = 0;j < n + 1;j++){
			fscanf(fp,"%lf",&matrix[i][j]);
		}
	}
	cout<<"根为："<<endl;
	if(Gauss(n)){
		for(i = 0;i < n;i++)	printf("%.12e\n",answer[i]);
	}
}
