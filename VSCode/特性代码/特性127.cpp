#include <iostream>
using namespace std;
template <size_t N>
void ft(int (&a)[N]) //不可写成int a[N]、int (a)[N]、int a[5]、int (a)[5]或int (&a)[5]。因为这样子传参没有数组长度信息，模板无法推导出模板参数
{
    for (int i = 0; i < N; ++i)
        cout << a[i];
}
void f(int a[5]) //也可写成int (&a)[5]
{
    for (int i = 0; i < 5; ++i)
        cout << a[i];
}
//#pragma push
#pragma O0 //也能写作#pragma -O0
int main()
{
    int a[5] = {4 [a] = 3}; //C中指定初始化器的语法C++并不支持
    for (int i = 0; i < 5; ++i)
        cout << a[i];
    ft(a);
    ft<5>(a);
    f(a);
}
#pragma// pop