#include <iostream>
#include <cstdio>
//#define int b 
using namespace std;
int main()
{
	//long int;�������֣��ؼ��� ��������Ϊ�����������ʶ�� 
	int a;
	a=16;
	printf("%0o",a); //printf�а˽��Ƶĸ�ʽ�ַ��� 0o �� o ; ʮ�����Ƶ��� 0x �� x  
	//printf("%0",a);������ 
	return 016;//�����ִ����������������У�������Ҳ��֮��ʧ 
	return 0x16;//return�����ֵĽ��Ʊ�ʾ�������˽������õĸ�ʽ�ַ��� 0 ; ʮ������������ 0x ��������return�������ʮ������ 
	//return 0o16;������ 
	//return x16;������
	//return o16;������
} 
