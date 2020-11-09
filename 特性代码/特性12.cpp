#include<iostream>
#include<cstdio>
using namespace std;
int main()
{    float y;
 y=1+1/(1+1/(1+1/5.0));//与5.0进行运算的数会被类型隐式转换为float类型          
 printf("%.2f",y);    
}


