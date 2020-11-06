#include <iostream>
using namespace std;
class People
{
public:
   int age;
   People()
   {
      cout << "default construction" << endl;
   }
   People(int a)
   {
      age = a;
      cout << "construction with int" << endl;
   }
   People(const People &p)
   {
      //*this = p;//此语句会调用赋值运算符重载函数导致无限循环导致程序崩溃
      cout << "copy with const People&" << endl;
   }
   People(People &&p) //右值引用自带const属性，所以此句与const People &&p等效。注意，右值引用的两个&号需分开写，否则会被认为是对引用类型的引用，但这是不被允许的
   {
      //*this = p;
      cout << "copy with const People&&" << '\n';
   }
   void operator=(People p) //p如为临时变量，则会被编译器优化为People &&p，此时实际执行过程中与const People &&p、People &&p、const People &p中任一句等效
   {
      age = p.age;
      //*this = p;//试图添加此语句会引发无限循环，导致程序崩溃
      //但是注意，无限循环的函数是 copy with const People& 和 operator = People 这两个函数，但是因为 operator = People 语句在循环之后，并不会到达，所以输出的是copy with const People&
      cout << "operator = People"
           << "\n";
   }
};
void foo(void)
{
   People p1(10);
   People p2;
   p2 = 10;        //此语句被编译器优化成了一次右值引用，使得调用赋值运算符重载函数时并不将临时变量赋给函数形参
   People p3 = 10; //在此处编译器进行了优化，使得p3的构造过程不经过拷贝构造函数的调用，而直接调用含参构造函数，注意，此时拷贝构造函数里的代码并不会被执行
                   /*
	隐式类类型转换：用单个实参来调用的构造函数定义了从形参类型到类类型的一个隐式转换（C++ Primer），可以用关键字explicit声明函数防止这种隐式转换
	如果是多个未含默认值的实参，则无法完成隐式转换
	*/
}
int main()
{
   foo();
}