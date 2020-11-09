#include <iostream>

using namespace std;

class Base

{

public:
    Base() { foo(); } //在类中直接调用方法名，调用的就是本类的方法

    virtual void foo(void) { cout << "Base::foo(void)" << endl; }

    virtual void callFoo(void) { foo(); }
};

class Derived : public Base

{

public:
    Derived() { foo(); }

    void foo(void) { cout << "Derived::foo(void)" << endl; }
};

int main(int argc, char **argv)

{

    Base *pB = new Derived;

    pB->callFoo();

    if (pB)

        delete pB;

    return 0;
}