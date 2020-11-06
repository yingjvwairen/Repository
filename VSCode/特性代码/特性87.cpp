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
�������д�����з����
	const int a = 1;
00971F72 C7 45 F4 01 00 00 00 mov         dword ptr [a],1  
	int & b = const_cast<int&>(a);
00971F79 8D 45 F4             lea         eax,[a]     //���Է��֣����ñ�����ָ�룬�����a�ĵ�ַ�ȴ浽eax
00971F7C 89 45 E8             mov         dword ptr [b],eax   //�ٰѵ�ַ��ֵ��b
	b = 2;
00971F7F 8B 45 E8             mov         eax,dword ptr [b]  //�Ȱѵ�ַ��eax
00971F82 C7 00 02 00 00 00    mov         dword ptr [eax],2    //����������ŵ��ǵ�ַ
	cout << a ;
00971F88 8B F4                mov         esi,esp  
00971F8A 6A 01                push        1      //��ӡ��ʱ��ֱ����ջ����1�����﷢���˳����۵�
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
//��ᷢ�ֵ��Դ����У�����������ֵ�����������룬����ӡʱ��ȴ���ȴ�ӡ1�����ӡ2��������Ϊ�����۵���
//c++��ĳ����۵������߳����滻)�ǽ�const�������ڷ��ű��У���������ڴ棬��ʵ�ʶ�ȡʱ���ƺ��滻��������ֱ�ӽ����滻�Ż���
//��������Ȼ�����ռ�, ������Ԥ����׶�, ���ڱ�������Ż���ʱ��ֱ�ӽ��г����滻
//reinterept_cast��int��float����ת��:������	const_cast���ڱ���׶�ȥ��const����