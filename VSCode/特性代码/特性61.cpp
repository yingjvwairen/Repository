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
	cout << m*m , 4/m , m/2 ;//ע���������ֻ�ܲ���һ�����ʽ���˶��ű��ʽδ�����ţ����Իᱻ��Ϊ�ǲ����һ�����ʽ
	cout << (m+1) ?  m : m-1 ;//ע���������ֻ�ܲ���һ�����ʽ�����������ʽδ�����ţ����Իᱻ��Ϊ�ǲ����һ�����ʽ
	/* 
	m+1>m;
	cout << m+1>m;//>����������޷����� 
	*/ 
}

