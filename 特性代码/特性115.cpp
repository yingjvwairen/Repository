#include <iostream>
using namespace std;
class Base
{
public:
    Base()
    {
        std::cout<<"���๹��"<<endl;
    }
    ~Base()
    {
        std::cout<<"��������"<<endl;
    }
    static int get()
    {
        std::cout<<"get()"<<endl;
        return 55;
    }
    static int count;
};
Base b;
int Base::count = Base::get();  //���ﲻ�ܵ���̬�������ᱨ��
int main()
{
    std::cout<<"main "<<endl;
    return 0;
}