#include<iostream>
using namespace std;
int main()
{	int a=0;
	if(a=!0)// !0 Ϊ 1 ����1����a�� ! һ������ֵ���� 0 
	cout << a << endl;
	if(!(a=0))//��0����a 
	cout << a << endl ;
	if(!(a=1))//��0����a,�����˸�ֵ������ֵ��Ϊif�����ж����� 
	cout << a;
	else if(a=0)
	cout << a; 
	else cout << !0;// !0 Ϊ 1 
}

