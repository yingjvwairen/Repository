#include<iostream>
using namespace std;
int main()
{
	/*typedef void (*pFunParam)();
	typedef void (*b[10])(pFunParam); //�������pFunParam���ͷ������������Ϊ�˺����Ĳ������� */ 
	typedef double(*pFun)(); //��typedef����һ��������ʹ֮��Ϊһ���������� 
	typedef pFun(*pFunParam)[9];
	pFunParam Pa;
	void (*p)();
	void (*p);
	void (); //������Ϊ�յĻ���������Ĭ��Ϊ0��NULL�����Դ˾���˼�ǽ�0��NULLǿ��ת��Ϊvoid���ͣ���(void)NULL;��(void)0;��ͬ
	//Ƕ�׵�typedef������������Ҫע��typedef���Ǽ򵥵ĺ��滻������ʵ���������ͬ���֣���Ϊtypedef�ڱ���ʱ�ᱻ���ͣ����Ҳ�����ñ�������Ӧ����ԽԤ�������������ı��滻 
	//typedef��һ���ر�ĳ��������ܷ�Χ����Լ����ʹ��typedef����ı������������÷�Χ������������ĺ��������ļ��ڣ�ȡ���ڴ˱��������λ�ã���Ϊtypedefʵ������һ���洢��ؼ��֣����Ա���ʧЧtypedef��ȻҲʧЧ
	//�洢��ؼ��֣�һ��ؼ��֣������֣����޶��˱����Ĵ洢���ͣ�������register��mutable��auto��static��extern 
}

