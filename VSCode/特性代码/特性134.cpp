#include <iostream>
using namespace std;
class A
{
public:
    int a;

    A(int a) : a(a) {}

    int get() { return a; }

    int *const get_address() { return &a; } //因为返回右值，所以此语句等价于int *get_address() { return &a; }

    int &get_reference() { return a; }

    int const_get() const { return a; } //因为返回值本身就是个右值，所以编译器在优化时把const去掉了，所以从const int 到int 的转换才不会报错

    //int *const_get_address() const { return &a; }//error: invalid conversion from 'const int*' to 'int*'

    //int &const_get_reference() const { return a; }//error: binding reference of type 'int&' to 'const int' discards qualifiers
};
class B : private A
{
    int b;

public:
    B(int b) : b(b), A(b) {}

    int get() { return b; }

    int *const get_address() { return &b; }

    int &get_reference() { return b; }

    int const_get() const { return b; }

    //int *const_get_address() const { return &a; }//error

    //int &const_get_reference() const { return a; }//error
};
template <class T>
class C
{
    T b;

public:
    C(T c) : b(c) {}

    T get() { return b; }

    T *const get_address() { return &b; }

    T &get_reference() { return b; }

    T const_get() const { return b; }

    //T *const_get_address() const { return &b; } //error

    //T &const_get_reference() const { return b; } //error

    T *operator->() const { return &b; }

    T &operator*() const { return b; }
};
int main()
{
    A t(10);

    cout << t.const_get();

    *(t.get_address()) = 20;

    cout << t.get();

    t.get_reference() = 30;

    cout << t.get();

    C<int> c(40);

    cout << c.const_get();

    *c = 50;

    cout << c.get();
}
