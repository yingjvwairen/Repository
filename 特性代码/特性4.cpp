#include <iostream>
#include <cstdio>
#include <cmath>
#define M 1000 
using namespace std;
int main()
{
	int a,b[M],n=1,c=0;//'='赋值运算符作用于等号左边的变量 
	cin >> a;
	for(int i=1;i<=n;i++)//在for语句的第一句中定义的变量会在for循环结束后释放（析构,此例中不在这定义n的原因是n之前已有过定义 
		{
		cin >> b[i];//输入一个数据时以空格或\n为结束 ;而为字符串赋值时则是以\0为结束，\n为换行 
		if(getchar()=='\n')break;//getchar() 明显是一个无参调用函数，此例中程序读入\n的同时也结束了一个数据的输入 （结束多个数据的输入以组成一组数据的输入 
		n++;
		}
		for(int i=1;i<=n;i++)
		{
			c=c+b[i]*pow(a,n-i);
		}
		cout << c;
}  

