#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;
/*
输出规则：
l1:以辅音字母加y结尾，则将y变成i，再加es;
l2:以s，x，ch，sh结尾，加es;
l3:以元音o结尾，加es;
l4:其他情况统统只加s; 
*/
string Plurals(string str)
{
	string ans = str;
	int len = str.size();
	if ((str[len - 2] != 'a') && (str[len - 2] != 'e') && (str[len - 2] != 'i') && (str[len - 2] != 'o') && (str[len - 2] != 'u') && (str[len - 1] == 'y'))
		str[len - 1] = 'i',ans = str + "es";
	else if ((str[len - 1] == 'o') || (str[len - 1] == 's') || (str[len - 1] == 'x'))
		ans = str + "es";
	else if (str[len - 1] == 'h')
		if ((str[len - 2] == 'c') || (str[len -2] == 's'))
			ans = str + "es";
		else
			ans = str + "s";
	return ans;
}
int main()
{		
	string str;
	while (cin >> str)//每循环一次就需要输入一次数据程序才会继续执行，如不输入数据程序就会在这由cin产生的断点处停止，但不会结束运行
						//换句话来说就是这种会产生断点的循环判断语句会使得程序不会停止运行而是无休止的在该语句产生断点使得此循环无限地循环下去 
    		cout << Plurals(str) << '\n';//此源文件中在这语句之后的语句都不会执行 
    		cout << str << endl; 
	return 0;
} 

