#include<iostream>
using namespace std;
int main()
{
     int a[3]={1,2,3};
     int (&b)[3]=a;//对数组的引用 
     cout<<&a[0]<<" "<<&b[0]<<endl;
     cout<<&a[1]<<" "<<&b[1]<<endl;
     cout<<&a[2]<<" "<<&b[2]<<endl;
     
     const int (&ref)[3] ={2,3,5}; //gcc编译的时候加上选项 -std=c++0x
	 //ref[0] = 35; （错误
	 int iv = 100;
	 //int *&pir = &iv;（错误，右值传递时需要创建临时变量  
	 int c=1;
	 double d;
	 d=c;
	 cout.setf(ios::showpoint);
	 cout << d;
	 const int ival = 1024;
	 //const int * &pi_ref = &ival;（ 错误，右值的指针也是右值 ，所创建的临时变量在完整表达式执行结束后就被析构，故此时形参必须定义为常引用，不然就会无效化或无法确定该值
	 //此时编译器会认为此语句不合法 
	 //但是可以自己定义一个“临时变量”（过渡变量，使“临时变量”不再“临时”： 
	 //const int *p = &ival;
	 //const int *&pi_ref = p;
	 const int e = 23;
	 const int *p = &e;
	 const int *& ref4 = p;//此时p是左值 
	 typedef string* pstring;string s;
	 const pstring cstr1 = &s;
	 
}
