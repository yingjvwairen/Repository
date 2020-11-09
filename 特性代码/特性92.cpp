#include<iostream>
using namespace std;

class Fred;	//前向引用声明
 
class Barney {
public:
  /*
  void method() {
    x.yabbaDabbaDo();	//错误：Fred类的对象在定义之前被使用(使用前向引用声明时，你只能使用被声明的符号，而不能涉及类的任何细节
  }
  */
 void method();
 private:
  Fred &x;//经过前向引用声明，可以声明Fred类的对象引用(尽管使用了前向引用声明，但是在提供一个完整的类定义之前，不能声明该类的对象
        //因为没有定义类，编译器未获得内存大小和数据占比等信息，无法为对象分配存储空间。但是为引用分配却可以，因为引用本质是泛化的指针，占8字节
};
//void Barney::method(){x.yabbaDabbaDo();}//实质也是在提供一个完整的类定义之前使用该类的对象，是无法操作的 
class Fred {
public:
  void yabbaDabbaDo(){};
private:
  Barney &y;
}; 
void Barney::method(){x.yabbaDabbaDo();}//可以在提供一个完整的类定义后使用该类的对象 
int main()
{

}
