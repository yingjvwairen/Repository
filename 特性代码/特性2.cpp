#include<iostream>
#include<cstdio>
using namespace std;
const float P=3.0;
int a=0;//定义全局变量a并初始化值为0（赋初值0 ，和int a;等价 
//需要注意的是对同一个变量的定义只可出现一次，而声明则没有这种限制（因为定义变量会为此变量开辟新内存空间，所以多次定义同一个变量会造成内存空间的冲突
//如int a;为a开辟了内存空间，并默认为变量赋初始值（假设值，且赋的初始值是根据变量类型决定的，一般静态变量（全局和有static修饰的变量，会默认赋0；而动态变量（局部变量，会赋随机值
//声明不限次数是因为声明某变量是外部变量不会开辟新内存空间，所以没有矛盾 
extern int a;//声明变量a是外部变量 
extern int a;//声明变量a是外部变量 
extern int a;//声明变量a是外部变量 
extern int a;//声明变量a是外部变量 
	inline float m(const float r);//声明函数，函数名前加上了inline修饰符，说明此函数是内联函数 ，即建议编译器让此函数与调用它的位置内联 
	//试图提高速度（define宏定义也可以 
	//对形参加类型修饰符const无意义 （不必要的声明函数会降低编译和程序运行的效率 
	main()//不加返回值类型限定的函数的返回值默认为int类型 
	{
		float a;
		a =2.0;//局部变量优先 
		cout << m(a);	
	}
	inline float m(float r)
	{
		return P*r;
	}//定义内联函数 ，inline（内联限定符，声明时已有修饰过，所以这里可有可无 
