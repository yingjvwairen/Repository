#include <iostream>

int fun(int a, int b)
{
    return a + b;
}

#define fun(int) std::cout << "fun�꺯���滻"
//#define fun(a) std::cout << "fun�꺯���滻"
#define printf(int, ints) std::cout << "printf�꺯���滻"
#define scanf(a,...) std::cout << "scanf�꺯���滻"
//Ҳ��д����#define scanf std::cout << "scanf�꺯���滻";��#define scanf(...) std::cout << "scanf�꺯���滻"

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