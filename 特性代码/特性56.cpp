#include<iostream>
using namespace std;
int test (int n)
{
	if (n==1||n==2)
	return 1;
	else
	{int a;
	a=test(n-1)+test(n-2);
	return a;}	
} 
int main()
{
	cout<<test(6);
}

