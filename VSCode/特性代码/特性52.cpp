#include<iostream>
using namespace std;
//[Note] initializing argument 1 of 'void test(int)'
void test(int M)
{
	return;
} 
int main()
{	
	char * str1[10];
	//test(str1);//'char**' 
	//test(&str1[0]);//'char**'
	//test(&str1);//'char* (*)[10]'  
	char ** str2 [10];
	//test(str2);//'char***'
	char * str[10][10];
	//test(&str[10]);//'char* (*)[10]'
	//test(str[10]);//'char**'
	//test(&str);//'char* (*)[10][10]'//对数组名取地址时代表整个数组的首地址
	//test(str);//'char* (*)[10]' 	
	//test(&(&str[0][0]));//看上去好像是str=&str[0]=&(&str[0][0])=&&str[0][0]，但是这样写会报错，原因是非数组指针在其解引用时不会被判定为是一个数组类型，所以解引用只能对非数组指针操作一次		 
	//test(&str[0]);//'char* (*)[10]'	str[0]代表str[0][10]这个数组的指针，对其解引用则会得到一个步长为[10]的指针，所以 +1 后会得到 &str[1] 
	//test(&str[0][0]);//'char**'
	char * str4;
	//test(&str4);//'char**'
	char * str8[10][10][10];
	//test(&str8);//'char* (*)[10][10][10]'
	//test(str8);//'char* (*)[10][10]'
	//test(str8[0]);//'char* (*)[10]'
	//test(&str8[0]);//'char* (*)[10][10]'
	char * str0[10][10][10][10];
	//test(str0[8]);//'char* (*)[10][10]' 
	
	//以上的 (*)[10] 代表的是指向10个元素的指针类型（含有10个元素的数组的首地址，而 (*)[10][10] 则是表示指向含有10个指向10个元素的指针元素的数组的指针类型（首地址 
	
	/*
	
	判断类型的方法：没有 & 解引用符号变量的先利用数组名为数组首元素地址这一特点化为含有解引用符号的变量，转化之后中括号的缺省数量就是指向数组的指针类型后中括号的数量
	
	例如：	char * str8[10][10][10];
	
		str8，不含有 & ，但可转化为 &str8[0]，而这个变量仅含一个中括号，也就是缺省了两个中括号，所以类型是：char* (*)[10][10]
		
		&str8，已含有 & ，不含有中括号，中括号数量为零，所以缺省了全部的中括号，所以类型是：char* (*)[10][10][10]		 

	*/
	 
	/* 
	int t[10][10]; 
	t[0][1]=100;
	t[1][0]=200;
	cout << **(t+1);// *((t+1)[0]);
	cout << *(t+1)[0];//注意运算符的优先级 
	//cout << *(t+1[0]);//[Error] invalid types 'int[int]' for array subscript 数组下标类型不可用，原因是[]运算符的优先级比+要高，故使得1会先与之结合，下标类型自然无效 
	*/ 
	
	/* 
	int a[12];
	printf("\n%d\n", &a[0]);
	printf("%d\n", &a[0]+1);
	printf("%d", &a+1);
	printf("\n%d", a);
	*/ 
	
	/*
	char str3[0];
	gets(str3);//读到换行符时会在结束输入的同时丢弃换行符，导致换行符并不会被接下来可能会出现的输入语句所捕捉到，所以不需要在此语句之后清空输入临时存储区（即缓冲区（系统使用缓冲的I/O 
	puts(str3);//puts函数在输入完所指向的字符串后还会追加输出一个换行符 
	cout<<str3[sizeof(str3)];
	*/
	
	/*
	scanf("%d",t[1]);
	getchar();
	*/
	
	/*
	int a[10];
	a[2]=300;
	cout << 2[a];//*(2+a);
	*/
	
	char (*)();
	char (*)[2];
	char (*);
	cout << char ();
}

