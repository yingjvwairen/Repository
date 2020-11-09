class base{};
class derived://private base{}; //private和protected型继承由于访问受限，所以无法用类型兼容转换规则实施派生类到基类或基类到派生类的转化
//virtual public base{};  //虚拟基类无法通过static_cast隐含转换为派生类的指针（因为虚继承下的对象内存布局和非虚继承不同，内存分布不是连续的，且派生类中会有额外的指向虚基类的指针
public base{};
base *pb = new derived();
derived *pd = static_cast<derived *>(pd);
derived d;
base &rb = d;
derived &rd = static_cast<derived &>(rb);
base b;
derived d2=static_cast<derived &>(b);
int main(){}
