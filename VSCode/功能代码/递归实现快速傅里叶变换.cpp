#include<bits\stdc++.h>
using namespace std;

const double PI = 3.1415926535;
const double pi=3.14159265358979;
struct Complex {
double r, i;
Complex() { r= 0, i= 0; }
Complex(double real ,
double imag): r(real), i(imag) {}
};
Complex operator + (Complex a, Complex b) { return Complex(a.r + b.r, a.i + b.i); } 
Complex operator -(Complex a, Complex b) { return Complex(a.r - b.r, a.i-b.i); } 
Complex operator * (Complex a, Complex b) { return Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);}
void FFT(Complex* a, int lim) {
if (lim == 1) return;
Complex a0[lim >> 1], a1[lim >> 1];
for(int i=0;i<lim;i+=2)
a0[i>>1]=a[i],a1[i>>1]=a[i+1];
FFT(a0, lim >> 1);
FFT(a1,lim >> 1);
Complex wn = Complex(cos(2.0 * PI / lim), sin(2.0 * PI / lim));
Complex w = Complex(1, 0);
for(int k=0;k<(lim>>1);++k){
a[k] = a0[k] + w * a1[k];
a[k+(lim>>1)]=a0[k]-w*a1[k];
w =w* wn;
}}
