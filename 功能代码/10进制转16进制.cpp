#include<iostream>
#include<string>
using namespace std;
int main() 
{
	long a;
	int y=0;
	string s="";//��ʼ��һ��'\0'���ַ��� 
	cin>>a;
	if(a==0) //�����ٽ絥������
	{
		cout<<0;
			return 0;
	}

	while(a>0)
	{
	y=a%16;
		if(y<10)
			s=char('0'+y)+s;  //�����ַ���ASCII�����ַ���ǰ��ƴ���ַ� (ע���ַ��ͱ������ַ����ڴ�ռ��е�ʵ�ʴ�����ʽ��ʵ����ASCII���ֵ����һ���������Կ��Խ�������
								//char()�����ڴ�������ַ���ASCII�룬������һ������ǿ��ת���ķ�ʽ������type2(type1)����type1����ǿ��ת��Ϊtype2 
								//���������֮ǰ�ķ�������ǿ������ת����(char) ('0'+y)������(type2)type1����type1����ǿ��ת��Ϊtype2
		else
			s=char('A'-10+y)+s;  //A����10������A��ASCII���ȥ10�ʹ�����ĸ�����ֵ�ASCII���ֵ
	a=a/16;
	}
		cout<<s;
			return 0;
}

