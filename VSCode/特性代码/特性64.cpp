#include<iostream>
using namespace std;
//����ͬ�������ݵ�������ͬʱ�Ƿ�����أ����� 
//���캯��ʱ�Զ��������Ĺ��캯��ʱ��Ĭ�Ϲ��캯�����ᱻ�Զ������𣿲��� 
//�Զ��������Ĺ��캯��������Ĭ�Ϲ��캯�������𣿿��� 
//���ƹ��캯�����β����ж����Ķ����𣿿���,�Ҷ��庬�ж�������ĸ��ƹ��캯������Ӱ��ϵͳ����Ĭ�ϸ��ƹ��캯�� 
//���ƹ��캯���и��β�ȫ������Ĭ��ֵ�Ļ�����Ĭ�ϸ��ƹ��캯���𣿲����ˣ��Ҷ��庬��Ĭ���β�ֵ�ĸ��ƹ��캯������Ӱ��ϵͳ����Ĭ�ϸ��ƹ��캯����������ʱ����ΪĬ�ϸ��ƹ��캯��Ҳ���贫�ζ����� 
//struct�����г�Ա�������ܣ���class����һ�� 
//����public��static��Ա����ɼ��𣿲��ɼ� 
struct s{
	private:
	static s t;//�������static���޶�����ΪC++�涨��static�����Ҳ���const�����ݳ�Ա�ĳ�ʼ�������������⣬��Ϊ����������ڶ���Ļ��Ǿͻ�ʹ��ÿ�ι������ʱ���ᴴ��һ��static��Ա����Ͳ���static�� 
	s(){
	}
	int bt(int b){t=b;
	}
	public:
	s(int=10){
	}
	s(int,int){
	}
	s(int,int,int){
	}
	s(s&,s&){
	} 
	static int b;
	s(s&s=t){
	} 
};
class bot{
	public:
	bot(){
	}
	bot(int=10){
	}
	bot(int,int){
	}
	bot(int,int,int){
	}
	bot(bot&,bot&){
	} 
	static int b;
	bot(bot&s=s){
	}
	private:
		static bot s;//�������static���޶�����ΪISO C++ forbids in-class initialization of non-const static member 
}; 
int main()
{
	bot s(s);
	bot i(i);
	bot j(i);
	bot(2,2);
	bot(2,2,2);
}

