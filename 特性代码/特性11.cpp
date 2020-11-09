#include<iostream>
#include<cmath>
using namespace std;
int main()
{ 
 float y;   
 y=(3^2+4^2)^(1/2);//^是按位异而不是开平方           
 printf("%.2f",y);  
 y=sqrt(pow(3,2)+pow(4,2)); 
 printf("%.2f",y);         
}

