#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
int main()
{	char* getline(char*,int);
	const char password[1024]="Tamako love story";//getch()和char区分大小写，所以这串密码也是区分大小写的 
	char str[1024];
	cout << "站在宇宙的入口\n"; 
	getline(str,1024);
	if(strcmp(str,password))
	cout << "\n玩儿蛋去\n";
	else
	{cout << "\n山田尚子厨无误了\n";return 0;} 
	printf("\n%c\n",str[2]);//不能用%s，否则会访问越界，程序会崩溃 
	printf("\n%d\n",&str[2]);//不能用%s，否则会访问越界，程序会崩溃 
}
char* getline(char* buffer,int len)
{
	int i=0;
	char ch;
	while(i<len-1)//注意在C语言中变量的声明不能放在for循环中，否则会找不到变量 
	{
		if(0!=kbhit())//检测键盘是否有输入（即keyboardhit，如有的话会返回一个非零值 ，否则返回零 
		{
			ch=getch();//此时kbhit未使光标移位（不是连续读入类型，故可输入 
			if(ch=='\r')// 只有遇上回车（换行时才会结束输入 ，需要特别注意的是在C语言中'\r'才是换行  
			break;
			putchar('*');
			buffer[i]=ch;
			++i;
		}
	//注意此时所调用的库函数不能带有回显，如库头函数getchar()	
	}
	buffer[i]='\0';
	return buffer;
}
