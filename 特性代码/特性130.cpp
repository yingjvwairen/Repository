#include <iostream>
using namespace std;
class C
{
    int k;

public:
    //�����ڹ��캯��������������ָ���������ͣ����캯���������������ܷ���ֵ
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
