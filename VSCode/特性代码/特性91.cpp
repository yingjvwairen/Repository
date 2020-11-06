#include <iostream>
using namespace std;
class Object
{
   int _id;

public:
   Object(int id) : _id(id)
   {
      if (id < 0)
         throw "invalid argument";//注意，对象的构造和析构是在构造函数和析构函数执行完毕后由系统内部自动完成的。这里构造函数执行未完成，对象未被构造
      cout << "C" << _id << endl;
   }
   ~Object() { cout << "D" << _id << endl; }
};
void func()
{
   Object a(1);
   static Object b(2);
   Object c(-1);
   Object d(3);
}
int main()
{
   try
   {
      Object a(4);
      func();
      Object b(5);
   }
   catch (const char *err)
   {
      //找到一个匹配异常参数的catch异常处理后，先初始化异常参数，后将try保护段块开始到异常被抛掷处之间构造且尚未析构的所有自动对象（局部生存期对象/动态生存期对象）进行析构
      //但需要注意的是，被static修饰的静态对象并不会在此处被析构，因为static对象具有与程序运行期等同的静态生存期，所以直到程序结束才会被释放  
      cout << "error:" << err << endl;
   }
   return 0;
}