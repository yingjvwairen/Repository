#include<iostream>
using namespace std;
class a{
	public:
	int* s=new int[10];
	a(int b){
		s[3]=b;//����д�ڹ��캯���⣬��Ϊд�ڹ��캯����ı�������Ϊ�����������������ǲ����������磺int b;b=10;//������Ϊbδ������������ 
	}
	~a(){
	delete s;//����ʱֻ������һ��int�Ŀռ䣬���Ի������ 
	}
}; 
int main()
{
	a t(9);
	cout<<t.s[3];//ע�⣺����ʱ�ᱨ�� 
}

