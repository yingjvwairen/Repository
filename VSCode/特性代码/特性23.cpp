#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a = 0.000123456789 ;
	cout << a << endl;
	double b = 0.123456789;
	cout << b << endl;
	double c = 123.456789;
	cout << c << endl;
	float d = 0.000123456789 ;
	cout << d << endl;
	float g = 0.123456789;
	cout << g << endl;
	float h = 123.456789;
	cout << h << endl;
	//cout浮点数默认格式的精度为6（即用四舍五入法保留六位有效数字 
	double i = 123.45678;
	double j = 123.4567890456789;
	cout << setiosflags(ios::fixed);
	cout << i << endl;
	cout << j << endl; 
	//fixed，定点小数格式（即固定小数格式，会默认四舍五入保留小数点后六位数字。printf就是默认用的固定小数格式输出
	cout << setiosflags(ios::fixed) << setprecision(8) << j ;
	//将定点小数格式默认的保留小数点后六位数字控制为保留小数点后八位数字 
}

