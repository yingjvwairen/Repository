#include<iostream> 
#include<cstdio>
#include<conio.h>
using namespace std;
int main(){
	
	char a[20];
	int n=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=getch();
		cout<<"*";
		if(a[i]=='\r')
		break;
		n++;
	}
	for(int i=1;i<=n;i++)
	cout<<a[i];	
}

