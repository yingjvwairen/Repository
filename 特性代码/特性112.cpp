#include <iostream>

using namespace std;
class A{
    public:
    explicit A(int){}
    explicit A(A&){}
};
A b;
int main(){
   A c=5;
   A a=b;//��Ϊû���Զ����operator=���Ե��ã�c++�����ɲ�����һ��ȱʡ��operator=����������explicit�ؼ��ֿ�����ֹͨ�����ֲ�������ʽ���ú���
   A c(5);
   A a(b);
}