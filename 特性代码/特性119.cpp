#include <iostream>
using namespace std;
class A
{
public:
    explicit A(int x = 0) : a(x){};
    int a;
};
void f(A a) { cout << a.a; }
//注意上两块代码的顺序不能对调
int main()
{
    //f(20); // ERROR 隐式转换被禁止.
    f(static_cast<A>(20)); //须显式转换
}