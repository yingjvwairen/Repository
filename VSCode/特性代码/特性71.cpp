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
	return * p;//此句中隐含有隐式类型转换：Point 转换到 Point& (因为被调函数返回值给主调函数时会创建临时变量，且此临时变量类型与被调函数返回值的类型一致 
}

int main() {
	Point&a=fn1();//Point a=fn1();
	cout<<"the value of a is: "<<a.getY();
	delete&a;
	cout<< "Step one: "<< endl;
	Point &ptr1= * new Point;//动态创建对象,没有给出参数列表,因此调用缺省构造函数
	delete &ptr1 ;//删除对象，自动调用析构函数
	cout<< "Step two: "<< endl ;
	ptr1= * new Point (1,2);//动态创建对象,并给出参数列表,因此调用有形参的构造函数
	delete &ptr1 ;//删除对象，自动调用析构函数
	return 0;
}

