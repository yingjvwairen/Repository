#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{
	int b=123456;
	cout<<hex<<setiosflags(ios::uppercase)<<b<<endl;//uppercase����д��ĸ 
	cout.unsetf(ios::uppercase);
	cout<<b<<endl;//ע��֮ǰ�������е� hex  
	cout<<dec<<b<<endl;
	cout<<b<<endl;
}

