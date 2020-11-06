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
/*	注意要先创建一个内存空间后再cin，
	如果只是：
	struct stu
	{
		int n;
	}*p;
	cin >> p->n;
	会因p->n所在的空间不确定或无此空间而报错，因为这个p实际上是一个"野指针" 
*/	 
}

