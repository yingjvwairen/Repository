#include <iostream>
using namespace std;
int main()
{
    int a = 0x11223344;

    int *p = &a;

    char *c = (char *)p;

    printf("%d\n", a); //低字节存储在低地址里，是小端序

    *c = 'Aa';

    printf("%d\n", *c); //因为从int到char的裁剪数据是只保留低字节，所以可看出低位数据存储在低字节中

    printf("%c\n", *(c + 1)); //未定义数据

    c = "Aa"; //字符串特殊处理，低地址存储高位字符

    printf("%d\n", *c);

    printf("%c\n", *(c + 1)); //输出44则是小端字节序，11则是大端字节序
    //可以看出小端序低地址存储着低位数据，但是字符串例外，字符串首地址存储从左向右数的第一个字符
    return 0;
}
