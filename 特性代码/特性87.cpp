#include<iostream>
using namespace std;
int main() {
	const int constant = 21;
	int* modifier1 = (int*)(&constant);
	int* modifier2 = const_cast<int*>(&constant);
	*modifier1=7;
	*modifier2=7;
	const int & c=constant;
	const_cast<int&>(c)=7;
	cout<<constant;
	const int a = 1;
	int & b = const_cast<int&>(a);
	b = 2;
	cout << a;
	cout << b;
}
/*
将后五行代码进行反汇编
	const int a = 1;
00971F72 C7 45 F4 01 00 00 00 mov         dword ptr [a],1  
	int & b = const_cast<int&>(a);
00971F79 8D 45 F4             lea         eax,[a]     //可以发现，引用本质是指针，这里把a的地址先存到eax
00971F7C 89 45 E8             mov         dword ptr [b],eax   //再把地址赋值给b
	b = 2;
00971F7F 8B 45 E8             mov         eax,dword ptr [b]  //先把地址给eax
00971F82 C7 00 02 00 00 00    mov         dword ptr [eax],2    //中括号里面放的是地址
	cout << a ;
00971F88 8B F4                mov         esi,esp  
00971F8A 6A 01                push        1      //打印的时候，直接入栈的是1，这里发生了常量折叠
00971F8C 8B 0D D4 D0 97 00    mov         ecx,dword ptr [_imp_?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A (097D0D4h)]  
00971F92 FF 15 E4 D0 97 00    call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (097D0E4h)]  
00971F98 3B F4                cmp         esi,esp  
00971F9A E8 0E F3 FF FF       call        __RTC_CheckEsp (09712ADh)  
	cout << b;
00971F9F 8B F4                mov         esi,esp  
00971FA1 8B 45 E8             mov         eax,dword ptr [b]  
00971FA4 8B 08                mov         ecx,dword ptr [eax]  
00971FA6 51                   push        ecx  
00971FA7 8B 0D D4 D0 97 00    mov         ecx,dword ptr [_imp_?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A (097D0D4h)]  
00971FAD FF 15 E4 D0 97 00    call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (097D0E4h)]  
00971FB3 3B F4                cmp         esi,esp  
00971FB5 E8 F3 F2 FF FF       call        __RTC_CheckEsp (09712ADh) 

*/
//你会发现调试窗口中，两个变量的值按照我们所想，但打印时，却是先打印1，后打印2。这是因为常量折叠。
//c++里的常量折叠（或者常量替换)是将const常量放在符号表中，给其分配内存，但实际读取时类似宏替换。编译器直接进行替换优化。
//编译器虽然会分配空间, 但是在预编译阶段, 会在编译进行优化的时候直接进行常量替换
//reinterept_cast：int和float不能转换:传引用	const_cast：在编译阶段去掉const属性