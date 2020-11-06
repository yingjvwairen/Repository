#include<iostream>
using namespace std;
int ope(int *a,int m,int n) 
{
	for(int i=0;i<m*n;++i)
	a[i]=111;
}
int main()
{
	int a[5][5];
	ope(a[0],5,5);
	cout<<a[4][2];
}

