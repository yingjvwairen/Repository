#include <iostream>
#include <cstdio>
#include <cmath>
#define M 1000 
using namespace std;
int main()
{
	int a,b[M],n=1,c=0;//'='��ֵ����������ڵȺ���ߵı��� 
	cin >> a;
	for(int i=1;i<=n;i++)//��for���ĵ�һ���ж���ı�������forѭ���������ͷţ�����,�����в����ⶨ��n��ԭ����n֮ǰ���й����� 
		{
		cin >> b[i];//����һ������ʱ�Կո��\nΪ���� ;��Ϊ�ַ�����ֵʱ������\0Ϊ������\nΪ���� 
		if(getchar()=='\n')break;//getchar() ������һ���޲ε��ú����������г������\n��ͬʱҲ������һ�����ݵ����� ������������ݵ����������һ�����ݵ����� 
		n++;
		}
		for(int i=1;i<=n;i++)
		{
			c=c+b[i]*pow(a,n-i);
		}
		cout << c;
}  

