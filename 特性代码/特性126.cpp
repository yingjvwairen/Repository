#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{	
	int * p = (int * )malloc( sizeof (int) );//malloc内存分配函数（memory allocation，形参代表所分配的字节数，返回值默认char*类型（字符型指针类型，即指向一个字节的指针
	//（因内存是按字节来分配的，而一个字节则是字节数的最小单位 
	//此语句中将返回值的类型强制转换为int*类型 
	free(p);//free函数，释放形参所指向的内存空间 
	//此语句是释放p指针所指向的内存（注意不是释放p指针本身
	free(malloc( sizeof (int) ));
	//此语句是释放malloc函数所开辟的内存（注意不是释放返回的指针本身（复习一下，此时返回的指针还是char*类型，这时候就体现了临时变量保护原始数据不被更改的作用了 
} 
