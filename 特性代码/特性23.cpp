#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a = 0.000123456789 ;
	cout << a << endl;
	double b = 0.123456789;
	cout << b << endl;
	double c = 123.456789;
	cout << c << endl;
	float d = 0.000123456789 ;
	cout << d << endl;
	float g = 0.123456789;
	cout << g << endl;
	float h = 123.456789;
	cout << h << endl;
	//cout������Ĭ�ϸ�ʽ�ľ���Ϊ6�������������뷨������λ��Ч���� 
	double i = 123.45678;
	double j = 123.4567890456789;
	cout << setiosflags(ios::fixed);
	cout << i << endl;
	cout << j << endl; 
	//fixed������С����ʽ�����̶�С����ʽ����Ĭ���������뱣��С�������λ���֡�printf����Ĭ���õĹ̶�С����ʽ���
	cout << setiosflags(ios::fixed) << setprecision(8) << j ;
	//������С����ʽĬ�ϵı���С�������λ���ֿ���Ϊ����С������λ���� 
}

