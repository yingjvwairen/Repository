#include <iostream>
#include <iomanip>
using namespace std;
int main( )
{
   double a=123.456,b=3.14159,c=-3214.67,d=-1241244.213;
   cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2);
   cout<<setw(10)<<a<<endl;
   cout<<setw(10)<<b<<endl;
   cout<<setw(10)<<c<<endl;
   cout<<setw(10)<<d<<endl;
   //先统一设置定点形式输出，取两位小数，右对齐，这些设置对其后的输出均有效(除非重新设置)，而setw只对其后一个输出项有效，因此必须在输出a,b,c之前都要写setw(10)
   cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<setw(10);
   cout<<a<<endl;
   cout<<b<<endl;
   cout<<c<<endl;
   cout<<d<<endl;
}
