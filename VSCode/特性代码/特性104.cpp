#include <iostream>
using namespace std;

int main()
{
    struct test
    {
        int a : 1;
        int   : 0;
        int c : 1;
    } t;
    t.a = -1;
    cout << t.a << endl;    //�������Ż����ڴ˴������˳����滻��ʹ��ֱ�����-1�������������ڴ�ռ䣨��ƾһ������λ�����ܴ���-1Ҳ����֤
    cout << sizeof(test) << endl;
    cout << sizeof(int) << endl;
    return 0;
}