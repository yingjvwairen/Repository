#define  MEM_SIZE(type, member)   sizeof(((type*)0)->member)
#define  OFFSETOF(type, member)  ( (size_t)( &( ( (type*)0 )->member ) ) )  //相对于0地址的地址值就是以字节为单位的偏移量值

#include<stdio.h>
#include<stddef.h>

typedef struct
{
 char a;  
 char c; 
 short b;         
 int d;
 char e;
}test_struct;

int main(void)
{  
 /* stddef.h宏 */
 printf("offset(a): %d\n", offsetof(test_struct, a));
 printf("offset(c): %d\n", offsetof(test_struct, c));
 printf("offset(b): %d\n", offsetof(test_struct, b));
 printf("offset(d): %d\n", offsetof(test_struct, d));
 printf("offset(e): %d\n", offsetof(test_struct, e));
 
 /* 自定义宏 */
 printf("OFFSETOF(a): %d\n", OFFSETOF(test_struct, a));
 printf("OFFSETOF(c): %d\n", OFFSETOF(test_struct, c));
 printf("OFFSETOF(b): %d\n", OFFSETOF(test_struct, b));
 printf("OFFSETOF(d): %d\n", OFFSETOF(test_struct, d));
 printf("OFFSETOF(e): %d\n", OFFSETOF(test_struct, e));
 
 return 0; 
}