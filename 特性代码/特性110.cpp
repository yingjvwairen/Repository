#include<stdio.h>

int line =1,i= 1;
 
int func();
 
int main()
{
	printf("%d ",line);
	line++;
	if(line<=9)
		printf("%d ",(main()+i++));
	func();
	return 0;
};
 
int func()
{
	if(line<=13)
	{
		line++;
		main();
	}
	return 0;
}
/*
事实证明main函数只是程序的入口，也相当于一个普通的函数，也能被自身调用，也能被其他函数调用。这和一般的函数之间互相调用的概念是一样的
不过需要注意的是，main函数不管是自身的调用还是被其他函数调用，和递归函数类似，都要设置函数终止的条件，不然就会陷入死循环
*/