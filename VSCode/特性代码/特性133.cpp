#include <iostream>
using namespace std;

class B
{
public:
    virtual void exec() { cout << "B::exec"; }
    ~B() {}
};
class D : public B
{
public:
    virtual void exec() { cout << "D::exec"; }
    virtual void exeD() { cout << "D::exeD"; }
    ~D() { cout << "D::~D"; }
};
void fun(B *p)
{
    p->exeD(); //�ھ��ж�̬�Ե�����£�������ת��Ϊ����ָ��ʱ���麯�����еĺ���Ҳ����нض�
               //��ֻ�������������������ͬ���ĺ����������������ĺ�����������������������д�Ļ��ຯ�����ڸ����˻��ຯ��������ຯ��ͬ�������Ա�����
    B *b = new B(*p);
    b->exeD();
    D *q = reinterpret_cast<D *>(b); //ʹ��reinterpret_castǿ��ת��֮�������׳���Segmentation fault
    q->exeD();                       //����bʵ��ָ���������ǻ��࣬����ǿ��ת��Ϊ������ʱ��ͨ���麯����ָ�����޷��ҵ������ຯ���������ʼ��ַ�ģ�����ֶδ���
                                     //���bָ����������������Ķ���Ļ��Ͳ���������
    delete p;
    delete q;
}
int main()
{
    cout << "call fun()";
    fun(new D);
}