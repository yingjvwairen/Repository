#include<iostream>
#include<string>
using namespace std;
int main() 
{
	long a;
	int y=0;
	string s="";//初始化一个'\0'入字符串 
	cin>>a;
	if(a==0) //特殊临界单独处理
	{
		cout<<0;
			return 0;
	}

	while(a>0)
	{
	y=a%16;
		if(y<10)
			s=char('0'+y)+s;  //利用字符的ASCII码在字符串前面拼接字符 (注意字符型变量的字符在内存空间中的实际存在形式其实就是ASCII码的值，是一个数，所以可以进行运算
								//char()括号内存放所需字符的ASCII码，这是另一种类型强制转换的方式，即：type2(type1)，将type1类型强制转换为type2 
								//（如果按照之前的方法来做强制类型转换是(char) ('0'+y)，即：(type2)type1，将type1类型强制转换为type2
		else
			s=char('A'-10+y)+s;  //A代表10，所以A的ASCII码减去10就代表字母和数字的ASCII码差值
	a=a/16;
	}
		cout<<s;
			return 0;
}

