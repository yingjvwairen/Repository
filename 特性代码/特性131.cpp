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
   ~D() { cout << "D::~D"; }
};
void fun(B *p)
{
   p->exec();
   B *b = new B(*p); //�����non-trival���ƹ��캯����û��������vftbָ��һ�𿽱��������������еĸ��ԣ����������������в��ڻ����������һ��
   b->exec();
   D *q = reinterpret_cast<D *>(b);
   q->exec();
   delete p;
   delete q;
}
int main()
{
   cout << "call fun()";
   fun(new D);
   return 0;
}
