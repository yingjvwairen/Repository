#include <iostream>
using namespace std;
class Base
{
public:
    Base()
    {
        std::cout<<"基类构造"<<endl;
    }
    ~Base()
    {
        std::cout<<"基类析构"<<endl;
    }
    static int get()
    {
        std::cout<<"get()"<<endl;
        return 55;
    }
    static int count;
};
Base b;
int Base::count = Base::get();  //这里不能调静态函数，会报错
int main()
{
    std::cout<<"main "<<endl;
    return 0;
}