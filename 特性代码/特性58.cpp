#include<iostream>
#include<malloc.h> 
using namespace std;
   void  buf( char **s)

    {

           *s = "message";

    }
int main()
{
	char  **s1 ;

	s1 = (char **) malloc(sizeof(char*));//系统对于未分配地址的指针，默认会初始化为NULL，即空指针。因此程序运行时，*s会报错，因空指针不指向任何内容
	
	//创建的是malloc（sizeof（....））,注意sizeof运算符，所以开辟的是个4个字节的区域，因此有几个 * 号其实没关系的，因为都是属于指针变量，都一样占用四个字节大小的内存空间
	
	//注意：32bit操作系统中指针大小才会是4个字节，如果是 64位 OS 里的话则应为8个字节	

	*s1 =  "hello world";
   
	char *s2 ;

	buf(&s2);

	printf("%s\n%s",*s1,s2);

    free(s1);
   
}

