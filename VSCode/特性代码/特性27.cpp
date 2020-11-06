#include<iostream>
using namespace std;
int main()
{
	FILE*fp;
	cout << (fp=fopen("test.txt","r"));//用作真值的赋值语句，执行完毕后返回左值（建议在用作真值的赋值语句前后加上括号 
	 
	int x;
	cout << endl << (x=3*5+9);//验证赋值表达式的返回值 
	
	cout << '\n' << fp;
	cout << '\n' << NULL;
}	

