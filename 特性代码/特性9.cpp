#include<iostream>
using namespace std;
int main()
{
     int a[3]={1,2,3};
     int (&b)[3]=a;//����������� 
     cout<<&a[0]<<" "<<&b[0]<<endl;
     cout<<&a[1]<<" "<<&b[1]<<endl;
     cout<<&a[2]<<" "<<&b[2]<<endl;
     
     const int (&ref)[3] ={2,3,5}; //gcc�����ʱ�����ѡ�� -std=c++0x
	 //ref[0] = 35; ������
	 int iv = 100;
	 //int *&pir = &iv;��������ֵ����ʱ��Ҫ������ʱ����  
	 int c=1;
	 double d;
	 d=c;
	 cout.setf(ios::showpoint);
	 cout << d;
	 const int ival = 1024;
	 //const int * &pi_ref = &ival;�� ������ֵ��ָ��Ҳ����ֵ ������������ʱ�������������ʽִ�н�����ͱ��������ʴ�ʱ�βα��붨��Ϊ�����ã���Ȼ�ͻ���Ч�����޷�ȷ����ֵ
	 //��ʱ����������Ϊ����䲻�Ϸ� 
	 //���ǿ����Լ�����һ������ʱ�����������ɱ�����ʹ����ʱ���������١���ʱ���� 
	 //const int *p = &ival;
	 //const int *&pi_ref = p;
	 const int e = 23;
	 const int *p = &e;
	 const int *& ref4 = p;//��ʱp����ֵ 
	 typedef string* pstring;string s;
	 const pstring cstr1 = &s;
	 
}
