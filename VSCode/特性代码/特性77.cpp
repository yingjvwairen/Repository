//��Ӧʵ������1.(2) 
#include <iostream>
using namespace std;

class SimpleCircle
{
public:
	SimpleCircle();
	SimpleCircle(int);
	SimpleCircle(const SimpleCircle &);
	~SimpleCircle() { 
		delete itsRadius;
		}
	void setRadius(int);
	int getRadius() const;
	
	int * get_addr(){
		return itsRadius;
	}
	
private:
	int *itsRadius;
};

SimpleCircle::SimpleCircle()
{
	itsRadius = new int(5);
}

SimpleCircle::SimpleCircle(int radius)
{
	itsRadius = new int(radius);
}

SimpleCircle::SimpleCircle(const SimpleCircle & rhs)
{	cout<<"in copy constructor"<<endl;
	int val = rhs.getRadius();
	itsRadius = new int(val);
}
//���û�и��ƹ��캯�����ͻ���ɶ����ڸ���ʱ�򵥵�ָ�븴��(��ǳ�������������е�ָ�����ָ��ͬһ�ڴ浥Ԫ
//���ϸ��ƹ��캯���Ĵ���󣬽���˲�ͬ��������ڴ�ռ�����⡣���������û��ָ���Ա��ϵͳ���Զ���ɶ���ĸ��Ƽ��ͷš�����û��ָ���Ա���࣬Ҳ�Ͳ���д�������
int SimpleCircle::getRadius() const
{
	return *itsRadius;
}

int main()
{
	SimpleCircle CircleOne, CircleTwo(9),t3(CircleTwo),t4=CircleTwo;  
	//t4=CircleTwo;// = ִ�е���Ȼ��ǳ��������û��ִ�и��ƹ��캯����t4�Ĺ��캯��ִ�е���֮ǰ����ʱִ�е�Ĭ�Ϲ��캯���������������ڵ�������ʱ�������ڸ��Ե������������ͷ�ͬ���ĵ�ַ  
	cout << "CircleOne: " << CircleOne.getRadius() <<"  "<< CircleOne.get_addr() <<endl;
	cout << "CircleTwo: " << CircleTwo.getRadius() <<"  "<< CircleTwo.get_addr() << endl;
	cout << "t3: " << t3.getRadius() <<"  "<<t3.get_addr() << endl;
	cout << "t4: " << t4.getRadius() <<"  "<<t4.get_addr() <<endl;
	
	return 0;
}
