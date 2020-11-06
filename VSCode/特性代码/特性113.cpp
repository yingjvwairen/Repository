#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A constructor" << endl;
    }

    ~A()
    {
        cout << "A destructor" << endl;
    }
};

int main()
{
    A(), // 注意， 是逗号运算符。A()构建了一个临时对象，这种临时对象会在语句结束后被析构
        printf("end xxx\n");
    printf("end yyy\n");
    const char *p = (string("abc") + string("def")).c_str(); // 临时对象在执行完该句后析构了
    cout << p << endl;                                       // 此时p指向垃圾值，但内存未重写

    return 0;

}