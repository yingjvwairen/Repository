#include <iostream>
using namespace std;
class B{
 public:
  virtual void exec()  {cout<<"B::exec"<<'\n';}
  virtual B* clone()  { return new B(*this); }
  ~B(){cout<<"B::~B"<<'\n';}
};

class D1 : public B{
  public:
    virtual void exec() { cout<<"D1::exec"<<'\n';}
    virtual B* clone() { return new D1(*this); }
    ~D1() { cout<<"D1::~D1"<<'\n';}
};

class D2 :public B{
  public:
    virtual void exec() { cout<<"D2:exec"<<'\n';}
    virtual B* clone() { return new D2(*this); }
    ~D2(){cout<<"D2::~D2"<<'\n';}
};

void func(B &b)
{
  B *q=b.clone();
  q->exec();
  if(D2 *dp=dynamic_cast<D2*>(q)) 
  {
    B b=*dp;
    b.exec();
    delete dp;
  }
  else
   delete q;
}

int main() {
  D1 d1;
  D2 d2;
  func(d1);
  func(d2);
}

