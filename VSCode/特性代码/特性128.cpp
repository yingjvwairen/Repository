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
    explicit Complex(double r, double i) : real(r), imag(i) {} //explicit关键字仅针对可只传一个实参的构造函数。因语法特性，传多个的不受其影响
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