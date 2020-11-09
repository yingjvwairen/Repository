#include<iostream>
using namespace std;
class Complex{
	public:
		Complex (int a ,int b);
		Complex (int a);
		void set(int a, int b);
		void add(Complex m);
		void show();
	private :
		int  x;
		int  y;
};
Complex::Complex(int a , int b){
	x=a;
	y=b;
}
Complex::Complex(int a){
	x=a;
}
void Complex::add(Complex m){
	x=x+m.x;
	y=y;
}
void Complex::show(){
	cout<<x<<"+"<<y<<"i"<<endl;
}
int main(){
	Complex c1(3,5);
	Complex c2=4.5;
	c1.add(c2);
	c1.show();
	return 0;	
}

