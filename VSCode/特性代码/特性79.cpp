#include<iostream>
using namespace std;
int main() {

	class c {
			int i;
		public:
			c(int j) {
				i=j;
			}
			c() {

			}
			int geti() {
				return i;
			}
	};

	c c1(5);

	//c c3;

	//c c3(c1);

	c c3=c1;

	//c3.~c();

	//c3.c();//[Error] invalid use of 'main()::c::c'��������ʹ��������

	//c3=c1;

	//c3(c1);//[Error] no match for call to '(main()::c) (main()::c&)'����û���ʵ�operator()������µ��������͵Ķ���򽫺���ת����ָ����������

	cout << c3.geti(); 
	
}

