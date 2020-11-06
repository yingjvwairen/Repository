#include<iostream>
using namespace std;
int main()
{
	cout << char(65) << '\n';//65默认是int的整型数据，将之强制转换为char类型 
	cout << (char) 65 << "\n";//65默认是int的整型数据，将之强制转换为char类型 
	//以上是两种强制类型转换的方法 
	//下述是验证方式 
	int a=1;
	double b;
	b= double(a);
	cout.setf(ios::showpoint);
	cout << b << endl;
	cout << a << endl; 
}

