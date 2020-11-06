#include<iostream>
using namespace std;
void ConstTest1(){
    const int a = 5;
    int *p;
    p = const_cast<int*>(&a);
    (*p)++;
    cout<<a<<endl;
    cout<<*p<<endl;
    
}
void ConstTest2(){
    int i;
    cout<<"please input a integer:";
    cin>>i;
    const int a = i;
    int &r = const_cast<int &>(a);
    r++;
    cout<<a<<endl;
}
int main(){
    ConstTest1();
    ConstTest2();
    return 0;
}
//当常变量为 const int j =i 时，直接输出j时，编译器不能进行优化，也就是不能够直接用i代替j；
//当常变量为const int j =5时，直接输出j时，编译器会进行优化，也就是用文字常量5直接代替j；