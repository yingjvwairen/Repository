#include <cassert>
#include <iostream>
using namespace std;
template <typename T>
class A{
	public:
		T a;
	T geta ()const{return a;}
	T & operator [](const A<T> & b)const{const int & c=a;return const_cast<int&>(c);}
	const T & operator ()(const A<T> & b)const{const int & c=a;return a;}
	A(T a=100){a=a;}
}; 
int main() {
	A<int> a(5);
	const A<int> b;
	cout<<(const_cast<int&>(b(a))=1000);
	cout<<(b[a]=5);
	cout<<b.geta();
	cout<<b.a;
	getchar();
}
//����Ա��������ֵ��const����£�����ͨ�����룬����ͨ�����������޸ĳ���������ݳ�Ա�� 
//���У������ó����ݳ�ʼ���ǳ����ã���Ϊ����Ա��������ʱ���ݾ�����Ϊconst��������,��ֻ��read-only 
//��Ȼ��������ǿ������ת��ȥ��const���ԴӶ��ﵽ���ĳ����ݵ�Ŀ�� 

