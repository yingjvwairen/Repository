#include <iostream>
using namespace std;
class Object
{
   int _id;

public:
   Object(int id) : _id(id)
   {
      if (id < 0)
         throw "invalid argument";//ע�⣬����Ĺ�����������ڹ��캯������������ִ����Ϻ���ϵͳ�ڲ��Զ���ɵġ����ﹹ�캯��ִ��δ��ɣ�����δ������
      cout << "C" << _id << endl;
   }
   ~Object() { cout << "D" << _id << endl; }
};
void func()
{
   Object a(1);
   static Object b(2);
   Object c(-1);
   Object d(3);
}
int main()
{
   try
   {
      Object a(4);
      func();
      Object b(5);
   }
   catch (const char *err)
   {
      //�ҵ�һ��ƥ���쳣������catch�쳣������ȳ�ʼ���쳣��������try�����ο鿪ʼ���쳣��������֮�乹������δ�����������Զ����󣨾ֲ������ڶ���/��̬�����ڶ��󣩽�������
      //����Ҫע����ǣ���static���εľ�̬���󲢲����ڴ˴�����������Ϊstatic�����������������ڵ�ͬ�ľ�̬�����ڣ�����ֱ����������Żᱻ�ͷ�  
      cout << "error:" << err << endl;
   }
   return 0;
}