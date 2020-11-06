#include <iostream>
using namespace std;

class Base0 {	//�������Base0
	public:
		Base0(int var) : var0(var) { cout << "construction of Base0" << endl;}
		int var0;
		void fun0() {
			cout << "Member of Base0" << endl;
		}
};
class Base1: virtual public Base0 {	//����������Base1
	public:	//�����ⲿ�ӿ�
		Base1(int var) : Base0(var) { cout << "construction of Base1" << endl;}
		int var1;
};
class Base2: public Base0 {	//����������Base2
	public:	//�����ⲿ�ӿ�
		Base2(int var) : Base0(var) { cout << "construction of Base2" << endl;}
		int var2;
};
class Derived: public Base1, public Base2 {
		//����������Derived
	public:	//�����ⲿ�ӿ�
		Derived(int var) : Base0(var), Base1(var), Base2(var) { cout << "construction of Derived" << endl;}
		int var;
		void fun() {
			cout << "Member of Derived" << endl;
		}
};
int main() {	//����������
	Derived d(1);	//����Derived�����d
	return 0;
}

