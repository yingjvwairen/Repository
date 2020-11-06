#include <iostream>
using namespace std;
class C
{
    int k;

public:
    //不能在构造函数或析构函数上指定返回类型，构造函数或析构函数不能返回值
    //void C() { return k; }  //error: return type specification for constructor/destructor invalid
    //void ~C() { return k; } //error: returning a value from a constructor/destructor
};

class c
{
    int k;

public:
    c() { return; }
    ~c() { return; }
};

int main()
{
}
