#include<iostream>
using namespace std;
int p(int x,int n) {
	if(n==0) {
		return 1;
	}
	if(n==1) {
		return x;
	}
	if(n>1) {
		return ((2*n-1)*x*p(x,n-1)-(n-1)*p(x,n-2))/n;
	}
}
int main() {
	int m;
	m=1;
	cout << m*m , 4/m , m/2 ;//注意流插入符只能插入一个表达式，此逗号表达式未加括号，所以会被认为是插入第一个表达式
	cout << (m+1) ?  m : m-1 ;//注意流插入符只能插入一个表达式，此条件表达式未加括号，所以会被认为是插入第一个表达式
	/* 
	m+1>m;
	cout << m+1>m;//>在运算符里无法重载 
	*/ 
}

