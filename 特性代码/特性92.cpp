#include<iostream>
using namespace std;

class Fred;	//ǰ����������
 
class Barney {
public:
  /*
  void method() {
    x.yabbaDabbaDo();	//����Fred��Ķ����ڶ���֮ǰ��ʹ��(ʹ��ǰ����������ʱ����ֻ��ʹ�ñ������ķ��ţ��������漰����κ�ϸ��
  }
  */
 void method();
 private:
  Fred &x;//����ǰ��������������������Fred��Ķ�������(����ʹ����ǰ�������������������ṩһ���������ඨ��֮ǰ��������������Ķ���
        //��Ϊû�ж����࣬������δ����ڴ��С������ռ�ȵ���Ϣ���޷�Ϊ�������洢�ռ䡣����Ϊ���÷���ȴ���ԣ���Ϊ���ñ����Ƿ�����ָ�룬ռ8�ֽ�
};
//void Barney::method(){x.yabbaDabbaDo();}//ʵ��Ҳ�����ṩһ���������ඨ��֮ǰʹ�ø���Ķ������޷������� 
class Fred {
public:
  void yabbaDabbaDo(){};
private:
  Barney &y;
}; 
void Barney::method(){x.yabbaDabbaDo();}//�������ṩһ���������ඨ���ʹ�ø���Ķ��� 
int main()
{

}
