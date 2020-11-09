#include <iostream>
#include <cstdio>
//#define int b 
using namespace std;
int main()
{
	//long int;（保留字（关键字 ，不能作为宏名（即宏标识符 
	int a;
	a=16;
	printf("%0o",a); //printf中八进制的格式字符是 0o 或 o ; 十六进制的是 0x 或 x  
	//printf("%0",a);（错误 
	return 016;//此语句执行完毕则程序结束运行，控制流也随之消失 
	return 0x16;//return后数字的进制表示：标明八进制所用的格式字符是 0 ; 十六进制则是用 0x 标明，而return输出的是十进制数 
	//return 0o16;（错误 
	//return x16;（错误
	//return o16;（错误
} 
