#include <iostream>
using namespace std;
class CA
{
    int k;

public:
    void f() { cout << "CA::f" << endl; }
};
class CB : public CA
{
};
class CC : public CA
{
};
class CD : public CB, public CC
{
}; //在C++中，多重继承是不推荐的，而一旦离开了多重继承，虚拟继承就完全失去了存在的必要（因为这样只会降低效率和占用更多的空间
int main()
{
    CD d;
    //d.f();//request for member 'f' is ambiguous
}
/*
f只定义了一个，为什么无法确定？
在多重继承下，子类所继承的成员都是从基类列表中所含有的成员继承而来的
因为编译器编译到函数被调用处时需要确定被调用函数的定义
调用CD::f时，由于f是在CA中被定义的，CB、CC在继承f时就会继承CA中的f定义，并在编译器的语法树中生成CB::f和CC::f标识作为标记
所以生成CD::f的时候，由于被CD继承的基类CB、CC都有由CA继承来的一个函数f，此时，CD将试图继承这两个f，这就导致标识CD::f不明确了
当我们不使用CD::f的时候，以上标识都不会被生成。所以，如果去掉d.f()一句，这一段编译不会有错
要解决这个问题，这里有两个方法：
1、重写函数f()：
此时由于我们明确定义了CD::f，编译器检查到CD::f()调用时就无需再像上面一样去逐级生成CD::f标识了
此时CD的元素结构如下：
|CB(CA)|
|CC(CA)|
故此时的sizeof(CD) = 8;（CB、CC各有一个元素k）
2、使用虚拟继承：
虚拟继承又称作共享继承，这种共享其实也是编译期间实现的
class CA
{
int k;
public:
void f() {cout << "CA::f" << endl;}
};
class CB : virtual public CA //也可写作：public virtual CA
{ 
};
class CC : virtual public CA
{
};
class CD : public CB, public CC
{
};
int main()
{
CD d;
d.f();
}
此时，当编译器确定d.f()调用的具体含义时，将生成如下的CD结构：
|CB|
|CC|
|CA|
同时，在CB、CC中都分别包含了一个指向CA的虚基类指针列表vbptr（virtual base table pointer）（虚基表指针）
其中记录的是从CB、CC的vbtable的首地址（vbptr）到CA的元素之间的偏移量。此时，不会生成各子类的函数f标识，除非子类重写了该函数，从而达到共享的目的
VS2010中，在Project Properties->C++->Command Line->Additional Options里面加上/d1reportSingleClassLayoutX，可以查看类X的对象布局
也正因此，此时的sizeof(CD) = 12（vbptrCB + vbptrCC + sizeof(int)）（32位机中指针占4个字节）
另注：
如果CB，CC中各定义一个int型变量，则sizeof(CD)就变成20(两个vbptr + 3个sizeof(int)
如果CA中添加一个virtual void f1(){}，sizeof(CD) = 16（vfptrCA +vbptrCB + vbptrCC + sizeof(int)）;
再添加virtual void f2(){}，sizeof(CD) = 16不变。原因：带有虚函数的类，其内存布局上只用包含一个指向虚函数列表的指针（vfptr）（虚函数表指针）
*/