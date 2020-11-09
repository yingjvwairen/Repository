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
        name = new char[strlen(name1 + 1)]; //ע��Ϊ�ַ������ݿ����ڴ�ռ�ʱ����Ĵ洢�ռ���Ҫ������ռ�������һ���ֽ�
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
void print(Mammal &Mp) //���ݳ������ԭ�򣬲���������������Ķ��󣬵����������������ָ������ã���Ϊ�麯��ֻ��ͨ��ָ�������������
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
