#include <iostream>
using namespace std;
template <size_t N>
void ft(int (&a)[N]) //����д��int a[N]��int (a)[N]��int a[5]��int (a)[5]��int (&a)[5]����Ϊ�����Ӵ���û�����鳤����Ϣ��ģ���޷��Ƶ���ģ�����
{
    for (int i = 0; i < N; ++i)
        cout << a[i];
}
void f(int a[5]) //Ҳ��д��int (&a)[5]
{
    for (int i = 0; i < 5; ++i)
        cout << a[i];
}
//#pragma push
#pragma O0 //Ҳ��д��#pragma -O0
int main()
{
    int a[5] = {4 [a] = 3}; //C��ָ����ʼ�������﷨C++����֧��
    for (int i = 0; i < 5; ++i)
        cout << a[i];
    ft(a);
    ft<5>(a);
    f(a);
}
#pragma// pop