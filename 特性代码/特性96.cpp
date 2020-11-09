#include <iostream>
#include <cstring>
using namespace std;
class Mammal
{
public:
    virtual void Name() = 0;
};

class Dog : public Mammal
{
    char *name;

public:
    Dog(char *name1)
    {
        //name = new char[strlen( name1 )];
        name = new char[strlen(name1 + 1)]; //注意为字符串数据开辟内存空间时分配的存储空间需要比所需空间多出至少一个字节
        strcpy(name, name1);
    }
    void Name()
    {
        cout << "Dog:" << name << endl;
    }
};
class Cat : public Mammal
{
    char *name;

public:
    Cat(char *name1)
    {
        name = new char[strlen(name1) + 1];
        strcpy(name, name1);
    }
    void Name()
    {
        cout << "Cat:" << name << endl;
    }
};
//void print(Mammal Mp)
void print(Mammal &Mp) //根据程序设计原则，不允许声明抽象类的对象，但允许声明抽象类的指针或引用，因为虚函数只能通过指针或引用来调用
{
    Mp.Name();
}

int main()
{
    Dog d1("Wo Wo");
    Cat c1("Mei Mei");
    print(d1);
    print(c1);
}
