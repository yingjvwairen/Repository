//对应实验六，1.(2) 
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
//如果没有复制构造函数，就会造成对象在复制时简单的指针复制(即浅拷贝，即对象中的指针变量指向同一内存单元
//加上复制构造函数的代码后，解决了不同对象各有内存空间的问题。如果程序里没有指针成员，系统会自动完成对象的复制及释放。所以没有指针成员的类，也就不必写深拷贝代码
int SimpleCircle::getRadius() const
{
	return *itsRadius;
}

int main()
{
	SimpleCircle CircleOne, CircleTwo(9),t3(CircleTwo),t4=CircleTwo;  
	//t4=CircleTwo;// = 执行的仍然是浅拷贝，并没有执行复制构造函数，t4的构造函数执行的是之前声明时执行的默认构造函数。它的问题在于当对象撤销时，导致在各自的析构函数里释放同样的地址  
	cout << "CircleOne: " << CircleOne.getRadius() <<"  "<< CircleOne.get_addr() <<endl;
	cout << "CircleTwo: " << CircleTwo.getRadius() <<"  "<< CircleTwo.get_addr() << endl;
	cout << "t3: " << t3.getRadius() <<"  "<<t3.get_addr() << endl;
	cout << "t4: " << t4.getRadius() <<"  "<<t4.get_addr() <<endl;
	
	return 0;
}
