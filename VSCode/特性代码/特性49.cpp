#include<iostream>
using namespace std;
int main()
{
	int t;
	
	putchar(65);//putchar的参数是int类型数据，代表了一个字符，它返回写入(stdout)的值 
	
	cout << putchar(65);//putchar的返回值也是int类型，此语句会调用putchar函数，输出65所代表的字符，之后用putchar的返回值输出 
	
	cout << getchar();//getchar返回的是int类型数值，参数为void(无参数) 
}

