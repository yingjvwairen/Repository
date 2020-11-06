#include<iostream>
using namespace std;
int ** arrayaverage(int **array,int Msize,int Nsize) {
	int average[Msize];
	for(int i=0; i<Msize; ++i) {
		int sum=0;
		for(int j=0; j<Nsize; ++j) {
			sum+=array[i][j];
		}
		average[i] =sum/Nsize;
	}
	return average,array;
}
int **sum(int **p) {
	p[1][1]=2*p[1][1];
}
int main() {
	int a[2][2];
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			a[i][j]=1;
		}
	}
	int **q=a;
	int **p=q;
	sum(p);
	cout<<a[1][1];
}
