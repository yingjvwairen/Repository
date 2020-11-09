#include <iostream>  
  
using namespace std;  
char (*pFun)(int);//此语句定义了一个函数指针pFUN，它指向一个返回类型为char，有一个整型的参数的函数（函数指针的形式：返回类型(*函数名)(参数表)   
char glFun(int a) //此语句定义了一个返回类型为char，参数为int的函数 
{  
    cout << a;  
    //return a;  
}  
  
int main()  
{   
    pFun = glFun;  //将函数glFun的地址赋值给变量pFun。可知：函数的函数名实际上是一个指针，且该指针指向函数在内存中的首地址  
    (*pFun)(2);  // *pFun 显然是取pFun所指向地址的内容，当然也就是取出了函数glFun()的内容，并给定参数为2
    return 0;  
}  
