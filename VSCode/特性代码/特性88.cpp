#include <iostream>
using namespace std;

class Test {
	public:
		Test(int d) {}
	    Test(Test& d) {}                //�������ԭ������ʱ�������г��ԣ���������ʱ����ƥ��
	//	Test(const Test& d) {}           //����ͨ��
};

Test reTmp() {
	return Test (10);
}

int main(void) {
	Test t2 = reTmp();
	return 0;
}

