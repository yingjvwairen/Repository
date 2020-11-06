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
   B *b = new B(*p); //这里的non-trival复制构造函数并没有连带将vftb指针一起拷贝（抛弃派生类中的个性，就像舍弃派生类中不在基类里的属性一样
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
