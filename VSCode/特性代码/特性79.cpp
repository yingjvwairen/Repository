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

	//c3.c();//[Error] invalid use of 'main()::c::c'，不允许使用类型名

	//c3=c1;

	//c3(c1);//[Error] no match for call to '(main()::c) (main()::c&)'，在没有适当operator()的情况下调用类类型的对象或将函数转换到指向函数的类型

	cout << c3.geti(); 
	
}

