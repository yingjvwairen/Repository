#include <iostream>
using namespace std;
class A
{
public:
    explicit A(int x = 0) : a(x){};
    int a;
};
void f(A a) { cout << a.a; }
//ע������������˳���ܶԵ�
int main()
{
    //f(20); // ERROR ��ʽת������ֹ.
    f(static_cast<A>(20)); //����ʽת��
}