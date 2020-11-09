#include <iostream>

void foo() { std::cout << "全局"; };

namespace
{
    void foo() { std::cout << "匿名"; };
} // namespace

namespace A
{
    void foo() { std::cout << "A"; };
    //foo(); //在子命名空间中的成员父命名空间中并不可见（和作用域类似
    namespace B
    {
        void foo() { std::cout << "B"; };
    } // namespace B

    void test()
    {
        //using namespace B;
        foo(); //引用A::foo, 而不是foo;（和作用域类似，小命名空间成员隐藏大命名空间成员
    }
} // namespace A


int main()
{
    //using namespace A::B;
    ::foo(); //优先调用全局域中的成员，此时匿名空间域中的成员被隐藏。全局域中没有才会调用匿名域中的成员
    A::B::foo();
    //foo();
    using A::foo;//foo才是要使用的成员名字，而foo()是个函数调用表达式
    foo;
    foo();
}
