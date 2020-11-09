#include<iostream> 
#include<cstdio>
#include<conio.h>
using namespace std;
int main(){
	int x[20];
	int n=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		if(getch()=='\r')
		break;
		n++;	
	}
	for(int i=1;i<=n;i++)
	cout<<x[i];	
}

