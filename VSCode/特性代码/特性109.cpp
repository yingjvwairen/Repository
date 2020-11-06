#include <stdio.h>

int line = 1;
 
int main()
{
 
	printf("%*s\n",7-(line>4?line-4:4-line),
		"*******"+2*(line>4?line-4:4-line));
	if(++line !=8)
		main();
/*
首先说一下%*s的用法，即*可以理解为是用一个int参数来代替，比如:
printf("%*s\n", 5, "def");就相当于printf("%5s\n", "def");指定了字符串输出的宽度
另外，"*******"+2*(line>4?line-4:4-line)，其实就是一个字符串指针加上一个int整数，也就是指针的平移了
比如line=1第一行时，2*(line>4? line-4:4-line)即为6，也就是7个星号的字符串指针平移6个，所以输出一个星号了
这个程序用到了main函数的递归调用，注意一定要写上退出条件，否则就无限循环了

 * 在scanf中的作用是跳过，例如：scanf("%*d %*d %d",&n);printf("%d",n);
这样当输入 1 2 3的时候，只会存储n，正常打印3
 * 在printf("%*d",width,n);因为是*d的顺序，所以width实际表达的是输出宽度，n才是要输出的内容
例如：int n=3;scanf("%d",width);printf("%*d",width,n);
*/ 
	return 0;
}