#include<iostream>
using namespace std;
//函数同类型数据但个数不同时是否可重载？可以 
//构造函数时自定义其他的构造函数时，默认构造函数还会被自动调用吗？不会 
//自定义其他的构造函数可以与默认构造函数共存吗？可以 
//复制构造函数中形参能有多个类的对象吗？可以,且定义含有多个类对象的复制构造函数不会影响系统生成默认复制构造函数 
//复制构造函数中给形参全都赋上默认值的话还算默认复制构造函数吗？不算了，且定义含有默认形参值的复制构造函数不会影响系统生成默认复制构造函数，但重载时会因为默认复制构造函数也不需传参而报错 
//struct中能有成员函数吗？能，与class基本一致 
//类中public的static成员类外可见吗？不可见 
struct s{
	private:
	static s t;//必须得有static的限定，因为C++规定被static修饰且不是const的数据成员的初始化必须是在类外，因为如果是在类内定义的话那就会使得每次构造对象时都会创建一个static成员，这就不是static了 
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
		static bot s;//必须得有static的限定，因为ISO C++ forbids in-class initialization of non-const static member 
}; 
int main()
{
	bot s(s);
	bot i(i);
	bot j(i);
	bot(2,2);
	bot(2,2,2);
}

