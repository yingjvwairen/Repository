#include <iostream>
using namespace std;
class Mammal
{

public:
   char voice;
   virtual char hit() { return this->voice; }

/*private:
   Mammal(){
      cout<<"Mammal";
   } ��������̳л���ʱ����̳��»���Ĺ��캯����������������ʱ�����Ĺ��캯������������Ϊprivate���ԣ���������Ĺ������������ʧ��
*/};

class Dog : public Mammal
{
   char derivedvoice;

public:
   Dog(char voice)
   {
      derivedvoice = voice;
   }
   char hit() { return this->derivedvoice; }
};
/*
ÿ����̬����һ�����virtual table��
������е�ǰ��ĸ����麯������ڵ�ַ
ÿ��������һ��ָ��ǰ�������ָ�루��ָ��vptr��
���캯���л�Ϊ�������ָ�븳ֵ
*/
void shout(Mammal &M) //ֻ��ͨ��ָ��������õ����麯������̬���͵�ָ������õ����麯��ʱ��ͨ����ָ���ҵ���������ҵ��������麯������ڵ�ַ��ͨ������ڵ�ַ�����麯��
{
   cout << '"' << M.hit() << '"';
}
int main()
{
   Dog d('W');
   shout(d);
   return 0;
}