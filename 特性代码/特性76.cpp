#include<iostream>
using namespace std;
class a{
	public:
	int* s=new int[10];
	a(int b){
		s[3]=b;//不能写在构造函数外，因为写在构造函数外的变量被认为是在声明变量而不是操作变量，如：int b;b=10;//报错，因为b未定义数据类型 
	}
	~a(){
	delete s;//析构时只析构了一个int的空间，所以会出问题 
	}
}; 
int main()
{
	a t(9);
	cout<<t.s[3];//注意：析构时会报错 
}

