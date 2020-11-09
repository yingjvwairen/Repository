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
    p->exeD(); //在具有多态性的情况下，派生类转换为基类指针时，虚函数表中的函数也会进行截断
               //即只保留与基类中所属函数同名的函数，派生类新增的函数被丢弃，但是派生类重写的基类函数由于覆盖了基类函数且与基类函数同名，所以被保留
    B *b = new B(*p);
    b->exeD();
    D *q = reinterpret_cast<D *>(b); //使用reinterpret_cast强制转换之后极其容易出现Segmentation fault
    q->exeD();                       //由于b实际指向的类对象是基类，故在强制转换为派生类时，通过虚函数表指针是无法找到派生类函数代码的起始地址的，会出现段错误
                                     //如果b指向的类对象是派生类的对象的话就不会有问题
    delete p;
    delete q;
}
int main()
{
    cout << "call fun()";
    fun(new D);
}