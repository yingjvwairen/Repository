#include <iostream>
#include <cmath>
using namespace std;
class Point {
	public:
		Point(): a(0), b(0) {
			cout<< "Default Constructor called. "<< endl;
		}
		Point(int x, int y): a(x), b(y) {
			cout<< "Constructor called. "<< endl;
		}
		~ Point() {
			cout<< "Destructor called. "<<endl;
		}
		int getX() const {
			return a;
		}
		int getY() const {
			return b;
		}
		void move (int newX, int newY) {
			a= newX;
			b= newY;
		}
	private :
		int a, b;
};

long(Point::*a)(int) ;

Point&fn1() {//Point fn1()
	Point*p=new Point(1,1);
	return * p;//�˾�����������ʽ����ת����Point ת���� Point& (��Ϊ������������ֵ����������ʱ�ᴴ����ʱ�������Ҵ���ʱ���������뱻����������ֵ������һ�� 
}

int main() {
	Point&a=fn1();//Point a=fn1();
	cout<<"the value of a is: "<<a.getY();
	delete&a;
	cout<< "Step one: "<< endl;
	Point &ptr1= * new Point;//��̬��������,û�и��������б�,��˵���ȱʡ���캯��
	delete &ptr1 ;//ɾ�������Զ�������������
	cout<< "Step two: "<< endl ;
	ptr1= * new Point (1,2);//��̬��������,�����������б�,��˵������βεĹ��캯��
	delete &ptr1 ;//ɾ�������Զ�������������
	return 0;
}

