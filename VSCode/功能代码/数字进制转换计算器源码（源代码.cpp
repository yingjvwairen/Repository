#include<iostream>
using namespace std;
int main()
{
	long n;//long���;���long int���ͣ��˸��ֽ� 
	int p,c,m=0,s[1024];
	cout << "������ת��������ת��������,֮���ÿո�ָ������зָ�У�������Ϻ�س�����\n"; 
	cin >> n >> p; 
	while(n!=0)
	{
		c=n%p;
		n=n/p;
		m++,s[m]=c;
	}
	for(int k=m;k>=1;--k)
	{
		if(s[k]>=10)
		cout << (char)(s[k]+55);//������ת������10��ʱ������Ҫ����ĸ�����������55��Ȼ��ǿ��ת�����ַ��;Ϳɵõ����Ӧ����ĸ 
		else
		cout << s[k];
	}
} 
