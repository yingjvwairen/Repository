#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A constructor" << endl;
    }

    ~A()
    {
        cout << "A destructor" << endl;
    }
};

int main()
{
    A(), // ע�⣬ �Ƕ����������A()������һ����ʱ����������ʱ�������������������
        printf("end xxx\n");
    printf("end yyy\n");
    const char *p = (string("abc") + string("def")).c_str(); // ��ʱ������ִ����þ��������
    cout << p << endl;                                       // ��ʱpָ������ֵ�����ڴ�δ��д

    return 0;

}