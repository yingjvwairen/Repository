/*
C语言程序必须从main函数开始吗？

程序的入口地址是可以指定的，c语言编译器默认以main作为入口地址

 __attribute__ 这个关键字，它可以设置函数属性，变量属性，类型属性
*/

#include <stdio.h>
//这种函数在main()之前执行
/*
 * This attribute lead gcc/ld to exec this function 
 * before the "main".
 */
extern "C"
{

    __attribute ((__constructor__))   //在main函数之前被调用的函数 
  void pre_func(void) {
        printf("pre_func\n");
}
}
int main( int argc, char ** argv )
{
  printf("%s/n",__FUNCTION__);
  return 0;
}
/*
同理在main函数退出之后执行的函数
static void stop() __attribute ((destructor));

只需要有__attribute ((constructor/destructor)) 关键字修饰即可
*/

/*
vc不支持attribute关键字，在vc中，可以使用如下方法：
#include <stdio.h>
int
main( int argc, char ** argv )
{
        printf("%s\n",__FUNCTION__);
        return 0;
}

int before_main()
{
        printf("%s\n",__FUNCTION__);
        return 0;
}
int after_main()
{
        printf("%s\n",__FUNCTION__);
        return 0;
}
typedef int func();
#pragma data_seg(".CRT$XIU")
static func * before[] = { before_main };
#pragma data_seg(".CRT$XPU")
static func * after[] = { after_main };
#pragma data_seg()

*/

//而且可以在main前后调用多个函数，在gcc下使用attribute声明多个constructor、destructor，vc下在before、after数组中添加多个函数指针