#include <iostream>
using namespace std;
#define TRUE false  //true和false是大小写敏感的
#define true false
#define true false  //此句给true重定义，因为先前已有相同的定义，所以编译器只会承认一次定义
#define false true  //此时此句相当于#undef true，因为对于形成循环的替换而言，替换只会循环一次
#define true false+100  //此句给true重定义，编译器仅承认最近一次的重定义
int main()
{
    cout << true << endl;   //true-->false+100-->true+100，只会进行一次循环
    cout << TRUE << endl;   //TRUE-->false-->true-->false+100，形成一次循环
    cout << NULL << endl;   //NULL也是区分大小写的
    cout << __null << endl; //预处理器会将NULL替换为__null，所以这两个其实是等价的
    return 0;
}

