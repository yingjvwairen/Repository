#include<iostream>
using namespace std;
int main() 

{

	int i;

	//for循环中的语句有三条，第一条为循环体前初始化，第二条为进入循环体前的条件判断语句，第三条为循环体前调整（可以将循环前初始化语句看作是第一次进入循环时的循环前调整，就像初始化和赋值的关系一样 

	for(i=0; i<4; i++) 
	
	{

		if(i==3) continue;//continue会执行for循环前调整 

		cout << i;
		
	}

	cout << i;

	for(i=0; i<4; i++) 
	
	{

		if(i==3) break;//break会直接跳出for循环体，退出时当然也不会执行for语句里下一次循环时的循环前调整了 

		cout << i;
		
	}

	cout << i;

}

