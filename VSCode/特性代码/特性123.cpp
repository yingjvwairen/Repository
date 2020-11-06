#include <iostream>

int fun(int a, int b)
{
    return a + b;
}

#define fun(int) std::cout << "funºêº¯ÊıÌæ»»"
//#define fun(a) std::cout << "funºêº¯ÊıÌæ»»"
#define printf(int, ints) std::cout << "printfºêº¯ÊıÌæ»»"
#define scanf(a,...) std::cout << "scanfºêº¯ÊıÌæ»»"
//Ò²¿ÉĞ´×÷£º#define scanf std::cout << "scanfºêº¯ÊıÌæ»»";»ò#define scanf(...) std::cout << "scanfºêº¯ÊıÌæ»»"

int main()
{
    fun(__FILE__);
    fun(1);
    fun;
    fun();
    int i;
    scanf("%d", &i);
    printf("Hello World%d", i);
}