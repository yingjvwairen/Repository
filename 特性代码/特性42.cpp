#include<iostream>
using namespace std;
int main()
{	int a=0;
	if(a=!0)// !0 为 1 ，将1赋给a（ ! 一个非零值都是 0 
	cout << a << endl;
	if(!(a=0))//将0赋给a 
	cout << a << endl ;
	if(!(a=1))//将0赋给a,并将此赋值语句的真值作为if语句的判断条件 
	cout << a;
	else if(a=0)
	cout << a; 
	else cout << !0;// !0 为 1 
}

