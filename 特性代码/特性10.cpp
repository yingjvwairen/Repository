#include<iostream>
using namespace std;
int main()
{
	cout << char(65) << '\n';//65Ĭ����int���������ݣ���֮ǿ��ת��Ϊchar���� 
	cout << (char) 65 << "\n";//65Ĭ����int���������ݣ���֮ǿ��ת��Ϊchar���� 
	//����������ǿ������ת���ķ��� 
	//��������֤��ʽ 
	int a=1;
	double b;
	b= double(a);
	cout.setf(ios::showpoint);
	cout << b << endl;
	cout << a << endl; 
}

