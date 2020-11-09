#include <iostream>
using namespace std;

class Base0 {	//定义基类Base0
	public:
		Base0(int var) : var0(var) { cout << "construction of Base0" << endl;}
		int var0;
		void fun0() {
			cout << "Member of Base0" << endl;
		}
};
class Base1: virtual public Base0 {	//定义派生类Base1
	public:	//新增外部接口
		Base1(int var) : Base0(var) { cout << "construction of Base1" << endl;}
		int var1;
};
class Base2: public Base0 {	//定义派生类Base2
	public:	//新增外部接口
		Base2(int var) : Base0(var) { cout << "construction of Base2" << endl;}
		int var2;
};
class Derived: public Base1, public Base2 {
		//定义派生类Derived
	public:	//新增外部接口
		Derived(int var) : Base0(var), Base1(var), Base2(var) { cout << "construction of Derived" << endl;}
		int var;
		void fun() {
			cout << "Member of Derived" << endl;
		}
};
int main() {	//程序主函数
	Derived d(1);	//定义Derived类对象d
	return 0;
}

