#include <iostream>
using namespace std;
int& fun(int& a){
a++;
a;
a;a; 
return a;
} //��a�������ú���,Ҳ����˵���fun()����a�ı���
int main(void){
int b =10;
fun(b); //ͬ��,fun(b)����b�������b�ı���
cout << b <<endl;
return 0;
}
