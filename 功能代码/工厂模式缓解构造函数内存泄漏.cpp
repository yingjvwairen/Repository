#include <iostream>

#include <exception>

#include <stdexcept>

using namespace std;

class ConWithException

{

public:
    static ConWithException *factory()

    {

        ConWithException *cwe = new ConWithException;

        if (cwe)

        {

            cwe->_pBuf = new int[100];

            //other initialization...
        }

        return cwe;
    }

    ~ConWithException()

    {

        cout << "Destructor!" << endl;

        if (_pBuf != NULL)

        {

            cout << "Delete buffer..." << endl;

            delete[] _pBuf;

            _pBuf = NULL;
        }
    }

private:
    ConWithException() : _pBuf(NULL) {} //如果有非静态const成员还需要在初始化列表中进行初始化

    int *_pBuf;
};

int main(int argc, char **argv)

{
    ConWithException *cwe = NULL;
    try

    {

        cwe = ConWithException::factory(); //要注意try代码块内声明或定义的变量只有try内可见
    }

    catch (std::runtime_error &e)

    {

        cout << e.what() << endl;
    }
 
    delete cwe;
 
    return 0;
}
/*
使用工厂模式时，构造函数执行失败抛出异常的问题可以得到缓解，因为构造函数十分轻量级，可轻松的完成对象的构建。而重量级的工作都交由工厂（factory）方法完成
工厂是一个公有的普通成员函数，如果在这个函数中产生任何异常，因为对象已经正确构建，可以完美的进行异常处理，也能保证对象的析构函数被正确地调用，杜绝memory leak
构造函数被声明为私有，以保证从工厂安全地产生对象
使用工厂模式，还可以禁止从栈上分配对象（其实Java、Objective-C都是这么做的），在必要的时候，这会很有帮助
*/