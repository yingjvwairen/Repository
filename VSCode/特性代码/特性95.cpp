class A
{
   static int m;
   static A a;
   A *pa;
   A &ra;
   //静态数据成员的类型可以是所属类的对象，而普通数据成员则不可以。普通数据成员的只能声明为所属类类型的指针或引用
   mutable int _i;//需要注意的是：mutable不能修饰const和static类型的变量
   static int _staticVal;
   int _val;
   void test() const
   { //const 成员函数

      _i++;         //正确，mutable数据成员（被mutable修饰的变量，将处于可变的状态，即便它是在一个const函数中（在C++中，mutable也是为了突破const的限制而设置的
      _staticVal++; //正确，static数据成员（静态数据成员的值在const成员函数中可以被合法的改变
      //_val++;       //错误
   }

public:
   //static int GetM() const { return this->m; }
   //this指针只能用于非静态成员函数内部，所以注意静态成员函数只能访问属于该类的静态数据成员或静态函数成员，而不可以访问类的非静态成员，因为静态成员函数不含this指针
   //且静态成员函数上不允许使用类型限定符（即静态成员函数不可以同时声明为 virtual、const、volatile
   static int GetM() { return m; }
   int fun(int i = m); //静态数据成员可以成为成员函数的可选参数，而普通数据成员则不可以
};
int A ::m;
int (*pf1)() = &A::GetM;    //需要注意的是，静态成员函数的地址可用普通的函数指针类型储存，而普通成员函数地址需要用类成员函数指针类型来储存
int (A::*p)(int) = &A::fun; //非静态成员函数系统会自动将this指针添加到形参列表中，而普通的函数指针不会这样，所以不能用普通的函数指针来存储
int main() {}