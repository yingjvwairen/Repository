#include <iostream>
using namespace std;

//�ڶ����ػ����еĳ�Ա�������Ǿ�̬��Ա������ʼ���Ȳ�����ʱ�򣬲���Ҫ��template<>��ǰ׺

template <class T>
struct A
{
    void f(T) {}
};
template <>
struct A<int>
{
    void f(int);
};
void h()
{
    A<int> a;
    a.f(16); // A<int>::f must be defined somewhere
}
//explicit specialization syntax not used for a member of
//explicitly specialized class template specialization
void A<int>::f(int) {}

template <class T>
class testclass
{
public:
    static int _data;
};

template <>
class testclass<int>
{
public:
    static int _data;
};

int testclass<int>::_data = 1;
template <>
int testclass<char>::_data = 2;

int main()
{
    cout << testclass<int>::_data << endl;
    cout << testclass<char>::_data << endl;

    testclass<int> obji1, obji2;
    testclass<char> objc1, objc2;

    cout << obji1._data << endl;
    cout << obji2._data << endl;
    cout << objc1._data << endl;
    cout << objc2._data << endl;

    obji1._data = 3;
    objc2._data = 4;

    cout << obji1._data << endl;
    cout << obji2._data << endl;
    cout << objc1._data << endl;
    cout << objc2._data << endl;

    return 0;
}