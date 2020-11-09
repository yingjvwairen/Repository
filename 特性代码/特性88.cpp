#include <iostream>
using namespace std;

class Test {
	public:
		Test(int d) {}
	    Test(Test& d) {}                //编译出错，原因是临时变量具有常性，拷贝构造时并不匹配
	//	Test(const Test& d) {}           //编译通过
};

Test reTmp() {
	return Test (10);
}

int main(void) {
	Test t2 = reTmp();
	return 0;
}

