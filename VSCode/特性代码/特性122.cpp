#include <iostream>

void foo() { std::cout << "ȫ��"; };

namespace
{
    void foo() { std::cout << "����"; };
} // namespace

namespace A
{
    void foo() { std::cout << "A"; };
    //foo(); //���������ռ��еĳ�Ա�������ռ��в����ɼ���������������
    namespace B
    {
        void foo() { std::cout << "B"; };
    } // namespace B

    void test()
    {
        //using namespace B;
        foo(); //����A::foo, ������foo;�������������ƣ�С�����ռ��Ա���ش������ռ��Ա
    }
} // namespace A


int main()
{
    //using namespace A::B;
    ::foo(); //���ȵ���ȫ�����еĳ�Ա����ʱ�����ռ����еĳ�Ա�����ء�ȫ������û�вŻ�����������еĳ�Ա
    A::B::foo();
    //foo();
    using A::foo;//foo����Ҫʹ�õĳ�Ա���֣���foo()�Ǹ��������ñ��ʽ
    foo;
    foo();
}
