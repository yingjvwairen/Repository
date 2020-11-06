#include <iostream>
using namespace std;
class People
{
public:
   int age;
   People()
   {
      cout << "default construction" << endl;
   }
   People(int a)
   {
      age = a;
      cout << "construction with int" << endl;
   }
   People(const People &p)
   {
      //*this = p;//��������ø�ֵ��������غ�����������ѭ�����³������
      cout << "copy with const People&" << endl;
   }
   People(People &&p) //��ֵ�����Դ�const���ԣ����Դ˾���const People &&p��Ч��ע�⣬��ֵ���õ�����&����ֿ�д������ᱻ��Ϊ�Ƕ��������͵����ã������ǲ��������
   {
      //*this = p;
      cout << "copy with const People&&" << '\n';
   }
   void operator=(People p) //p��Ϊ��ʱ��������ᱻ�������Ż�ΪPeople &&p����ʱʵ��ִ�й�������const People &&p��People &&p��const People &p����һ���Ч
   {
      age = p.age;
      //*this = p;//��ͼ��Ӵ�������������ѭ�������³������
      //����ע�⣬����ѭ���ĺ����� copy with const People& �� operator = People ������������������Ϊ operator = People �����ѭ��֮�󣬲����ᵽ������������copy with const People&
      cout << "operator = People"
           << "\n";
   }
};
void foo(void)
{
   People p1(10);
   People p2;
   p2 = 10;        //����䱻�������Ż�����һ����ֵ���ã�ʹ�õ��ø�ֵ��������غ���ʱ��������ʱ�������������β�
   People p3 = 10; //�ڴ˴��������������Ż���ʹ��p3�Ĺ�����̲������������캯���ĵ��ã���ֱ�ӵ��ú��ι��캯����ע�⣬��ʱ�������캯����Ĵ��벢���ᱻִ��
                   /*
	��ʽ������ת�����õ���ʵ�������õĹ��캯�������˴��β����͵������͵�һ����ʽת����C++ Primer���������ùؼ���explicit����������ֹ������ʽת��
	����Ƕ��δ��Ĭ��ֵ��ʵ�Σ����޷������ʽת��
	*/
}
int main()
{
   foo();
}