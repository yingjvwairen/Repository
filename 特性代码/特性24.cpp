#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{
	int b=123456;
	cout<<hex<<setiosflags(ios::uppercase)<<b<<endl;//uppercase（大写字母 
	cout.unsetf(ios::uppercase);
	cout<<b<<endl;//注意之前插入流中的 hex  
	cout<<dec<<b<<endl;
	cout<<b<<endl;
}

