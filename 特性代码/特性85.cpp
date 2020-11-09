//TestCast.cpp:Definestheentrypointfortheconsoleapplication.
//#include"stdafx.h"
#include"stdlib.h"
#include<tchar.h> //�����ļ��п�ֱ��ʹ�ã����趨��
#include<iostream>
using namespace std;

class Base {
	public:
		virtual void f() {
			cout << "Base::f" << endl;
		}
		void f1() {
			cout << "Base::f1" << endl;
		}
	private:
		double x;
		double y;
};

class Derived : public Base {
	public:
		virtual void f() {
			cout << "Derived::f" << endl;
		}
		virtual void k() {
			cout << "Derived::k" << endl;
		}
	private:
		double z;
};

class Base1 {
	public:
		virtual void g() {
			cout << "Base1::g" << endl;
		}
		void g1() {
			cout << "Base1::g1" << endl;
		}
};

class Derived1 : public Base, public Base1 {
	public:
		virtual void f() {
			cout << "Derived1::f" << endl;
		}
		virtual void h() {
			cout << "Derived1::h" << endl;
		}
};

void Test1() {
	//���ڵ��̳У�
	//���pD���ָ��Derived����dynamic_cast��static_castЧ����ͬ
	Base* pD = new Derived;

	Derived* pD1 = dynamic_cast<Derived*>(pD);
	pD1->f();
	pD1->k();
	pD1->f1();

	Derived* pD2 = static_cast<Derived*>(pD);
	pD2->f();
	pD2->k();
	pD2->f1();

	//�������pB�������ָ��Derived������dynamic_cast�򷵻�NULL���ܹ�����Ľ�ֹerror�ķ�����
	//�����static_cast��Ȼ���صĲ�ΪNULL����������ʱ�����׳�exception��
	/**/////Errorcode
	//Base* pB = new Base();
	//Derived* pD3 = static_cast<Derived*>(pB);
	//pD3->f();
	//pD3->k();
	//pD3->f1();
	//Derived*pD4 = dynamic_cast<Derived*>(pB);
	//pD4->f();
	//pD4->k();
	//pD4->f1();
}

void Test2() {
	//���ڶ��ؼ̳У�
	//���pD���ָ�����Derived1��ʹ��dynamic_cast��static_cast������ת��ΪDerived1��
	//�������Ҫת��ΪBase���ֵ���Base1������ʹ��dynamic_cast��ʹ��static_cast���ܱ��롣
	Base* pD = new Derived1;
	Derived1* pD1 = dynamic_cast<Derived1*>(pD);
	pD1->f();
	pD1->h();
	pD1->f1();

	Derived1* pD2 = static_cast<Derived1*>(pD);
	pD2->f();
	pD2->h();
	pD2->f1();

	Base1* pB1 = dynamic_cast<Base1*>(pD);
	pB1->g();

	/**/////errorcannotcompiler
	//Base1* pB2 = static_cast<Base1*>(pD);
	//pB2->g();
	//��Ȼ����pB�������ָ��Derived1����Ҫת��ΪDerived1��Base���ֵ���Base1�������Test1�е�error�����ͬ��
}
//���Ͽ��Կ�����dynamic_cast���ж�̬�ԣ���static_castû�У�������Ϊ��̬����C++�ų��ֵģ���static_cast��C�ġ����⣬dynamic_cast��֧�ֽ���ת����cross cast���� 
int _tmain(int argc, _TCHAR*argv[]) {
	Test1();
	Test2();
	return 0 ;
}
