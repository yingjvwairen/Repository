#include <iostream>
using namespace std;
class Mammal
{

public:
   char voice;
   virtual char hit() { return this->voice; }

/*private:
   Mammal(){
      cout<<"Mammal";
   } 在派生类继承基类时，会继承下基类的构造函数和析构函数。此时如基类的构造函数或析构函数为private属性，则派生类的构造和析构都会失败
*/};

class Dog : public Mammal
{
   char derivedvoice;

public:
   Dog(char voice)
   {
      derivedvoice = voice;
   }
   char hit() { return this->derivedvoice; }
};
/*
每个多态类有一个虚表（virtual table）
虚表中有当前类的各个虚函数的入口地址
每个对象有一个指向当前类的虚表的指针（虚指针vptr）
构造函数中会为对象的虚指针赋值
*/
void shout(Mammal &M) //只能通过指针或者引用调用虚函数（多态类型的指针或引用调用虚函数时，通过虚指针找到虚表，进而找到所调用虚函数的入口地址，通过该入口地址调用虚函数
{
   cout << '"' << M.hit() << '"';
}
int main()
{
   Dog d('W');
   shout(d);
   return 0;
}