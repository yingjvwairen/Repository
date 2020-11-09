#include <iostream>

using namespace std;
class A{
    public:
    explicit A(int){}
    explicit A(A&){}
};
A b;
int main(){
   A c=5;
   A a=b;//因为没有自定义的operator=可以调用，c++会生成并调用一个缺省的operator=操作符。而explicit关键字可以阻止通过这种操作符隐式调用函数
   A c(5);
   A a(b);
}