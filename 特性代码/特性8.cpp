#include <iostream>
using namespace std;
int& fun(int& a){
a++;
a;
a;a; 
return a;
} //把a返回引用函数,也就是说这个fun()就是a的别名
int main(void){
int b =10;
fun(b); //同理,fun(b)就是b自增后的b的别名
cout << b <<endl;
return 0;
}
