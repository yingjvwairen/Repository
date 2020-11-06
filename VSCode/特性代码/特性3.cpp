#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a=2;
	int b=2;
	//用C中唯一的三目运算符组成的语句作为一个例子来说明++a代表表达式开始执行前a自加，而a++代表表达式执行结束后a自加
	//此例中的三目运算符语句包含两个表达式，？前作为一个判断表达式，？后两个表达式其中的一个作为输出表达式，所以说a先自加后再与b作比较，先输出后再自加
	cout << ( ++a > b ? a++ : b ) << "\n";	
	cout << a;	
} 
