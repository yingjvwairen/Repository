#include<iostream>
using namespace std;
int main()
{
	FILE*fp;
	cout << (fp=fopen("test.txt","r"));//������ֵ�ĸ�ֵ��䣬ִ����Ϻ󷵻���ֵ��������������ֵ�ĸ�ֵ���ǰ��������� 
	 
	int x;
	cout << endl << (x=3*5+9);//��֤��ֵ���ʽ�ķ���ֵ 
	
	cout << '\n' << fp;
	cout << '\n' << NULL;
}	

