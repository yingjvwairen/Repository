#include<iostream>
using namespace std;
int waylong(char* a) {
	int i=0;
	while(a[i]!='\0') {
		i++;
	}
	return i;
}
char* getname(char* a) {
	int i=0;
	while(a[i]!='\0') {
		i++;
	}
	char b[i];
	for(int j=i;; j--) {
		b[j]=a[i];//��i��Ϊi-1Ҳһ�� 
		i--;
		if(j==0)
			return b;
	}
}
int main() {
	char a[200]= {0};
	cin>>a;
	cout<<waylong(a)<<endl;
	printf("%s",getname(a)); 
}

