#include <iostream>
using namespace std;
#pragma - o0
class Complex
{
private:
    double real, imag;

public:
    Complex(){};
    explicit Complex(double r) : real(r), imag(0) {}
    explicit Complex(double r, double i) : real(r), imag(i) {} //explicit�ؼ��ֽ���Կ�ֻ��һ��ʵ�εĹ��캯�������﷨���ԣ�������Ĳ�����Ӱ��
    operator double() { return real; }
    Complex operator+(Complex c) { return Complex(real + c.real, imag + c.imag); }
    operator double() const { return real; }                                             //can be overloaded with non-const
    Complex operator+(Complex c) const { return Complex(real + c.real, imag + c.imag); } //can be overloaded with non-const
};
int main()
{
    const Complex cc(1, 2);
    Complex c(3, 4);
    double d;
    d = c + 2.5;
    d = cc + 2.5;
    cout << d;
}