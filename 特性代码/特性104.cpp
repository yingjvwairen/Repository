#include <iostream>
using namespace std;

int main()
{
    struct test
    {
        int a : 1;
        int   : 0;
        int c : 1;
    } t;
    t.a = -1;
    cout << t.a << endl;    //编译器优化：在此处进行了常量替换，使得直接输出-1而不经过访问内存空间（仅凭一个比特位并不能存下-1也能验证
    cout << sizeof(test) << endl;
    cout << sizeof(int) << endl;
    return 0;
}