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
   //��ͳһ���ö�����ʽ�����ȡ��λС�����Ҷ��룬��Щ���ö������������Ч(������������)����setwֻ�����һ���������Ч����˱��������a,b,c֮ǰ��Ҫдsetw(10)
   cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<setw(10);
   cout<<a<<endl;
   cout<<b<<endl;
   cout<<c<<endl;
   cout<<d<<endl;
}
