#include<iostream>
using namespace std;
int main()
{	
	cout << '\n';
	cout << "\\n" << endl;
	cout << "\\\n" << endl;
	cout << "hahah" << '\r' << "wara"; 
	system("help");//注意：在Windows操作系统下的system()函数中的DOS命令可以不区别大小写
	system("pause"); 
	system("date");
	system("time"); 
	system("cls");
	//system("dir");
	system("color 3F");//直接调用已经被收录在标准c库中的system()函数中的color命令(DOS，而此经由system发出的DOS命令(color可以改变控制台的前景色和背景色，例如 system(“color 0A”); 其中color后面的0是背景色代号，A是前景色代号 
						/* 
						各颜色代码如下：
							0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色 6=黄色 7=白色 8=灰色 9=淡蓝色 A=淡绿色 B=淡浅绿色 C=淡红色 D=淡紫色 E=淡黄色 F=亮白色 
						*/ 
}

