#include<iostream>
using namespace std;
int main()
{
	struct stu
	{
		int No;
	};
	stu pm;
	stu *p=&pm;
	cin >> p->No;
/*	ע��Ҫ�ȴ���һ���ڴ�ռ����cin��
	���ֻ�ǣ�
	struct stu
	{
		int n;
	}*p;
	cin >> p->n;
	����p->n���ڵĿռ䲻ȷ�����޴˿ռ��������Ϊ���pʵ������һ��"Ұָ��" 
*/	 
}

