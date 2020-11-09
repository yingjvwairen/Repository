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
	for(int j=i-1;; j--) {
		b[j]=a[i-1];
		i--;
		if(a[i-1]=='\\')
			return b;
	}
}
int main() {
	char a[100];
	cin>>a;
	cout<<waylong(a)<<endl;
	printf("%s",getname(a));
}

