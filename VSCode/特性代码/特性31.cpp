#include<iostream>
using namespace std;
int main()
{
	/*typedef void (*pFunParam)();
	typedef void (*b[10])(pFunParam); //将定义的pFunParam类型放入参数表中作为此函数的参数类型 */ 
	typedef double(*pFun)(); //用typedef声明一个变量，使之变为一个数据类型 
	typedef pFun(*pFunParam)[9];
	pFunParam Pa;
	void (*p)();
	void (*p);
	void (); //括号里为空的话，编译器默认为0或NULL，所以此句意思是将0或NULL强制转换为void类型，与(void)NULL;或(void)0;等同
	//嵌套的typedef变量声明。但要注意typedef不是简单的宏替换，用其实际类型替代同义字，因为typedef在编译时会被解释（因而也可以让编译器来应付超越预处理器能力的文本替换 
	//typedef有一个特别的长处：它受范围规则约束，使用typedef定义的变量类型其作用范围限制在所定义的函数或者文件内（取决于此变量定义的位置，因为typedef实质上是一个存储类关键字，所以变量失效typedef自然也失效
	//存储类关键字：一类关键字（保留字，它限定了变量的存储类型，包括：register、mutable、auto、static、extern 
}

