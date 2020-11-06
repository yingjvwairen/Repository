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
    ConWithException() : _pBuf(NULL) {} //����зǾ�̬const��Ա����Ҫ�ڳ�ʼ���б��н��г�ʼ��

    int *_pBuf;
};

int main(int argc, char **argv)

{
    ConWithException *cwe = NULL;
    try

    {

        cwe = ConWithException::factory(); //Ҫע��try���������������ı���ֻ��try�ڿɼ�
    }

    catch (std::runtime_error &e)

    {

        cout << e.what() << endl;
    }
 
    delete cwe;
 
    return 0;
}
/*
ʹ�ù���ģʽʱ�����캯��ִ��ʧ���׳��쳣��������Եõ����⣬��Ϊ���캯��ʮ���������������ɵ���ɶ���Ĺ��������������Ĺ��������ɹ�����factory���������
������һ�����е���ͨ��Ա�������������������в����κ��쳣����Ϊ�����Ѿ���ȷ���������������Ľ����쳣����Ҳ�ܱ�֤�����������������ȷ�ص��ã��ž�memory leak
���캯��������Ϊ˽�У��Ա�֤�ӹ�����ȫ�ز�������
ʹ�ù���ģʽ�������Խ�ֹ��ջ�Ϸ��������ʵJava��Objective-C������ô���ģ����ڱ�Ҫ��ʱ�������а���
*/