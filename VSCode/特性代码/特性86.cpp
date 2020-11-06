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
//常成员函数返回值非const情况下，可以通过编译，但能通过返回引用修改常对象的数据成员吗 
//不行，不能用常数据初始化非常引用（因为常成员函数操作时数据均设置为const属性数据,即只读read-only 
//当然，可以用强制类型转换去除const属性从而达到更改常数据的目的 

