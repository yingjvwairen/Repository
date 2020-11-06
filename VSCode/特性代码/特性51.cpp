#include<iostream>
using namespace std;
int main()
{
    int a[3][4] = {0};
    printf("sizeof(a) = %d\n",sizeof(a));
    //当a单独出现在sizeof()中时表示整个数组，内存占用量为48byte；（除此之外a单独出现表示整个数组的情况还有 &a 时，a表示整个数组，所以&a表示的是整个数组的首地址。而a只代表第0行的首地址） 
    printf("sizeof(a[0][0]) = %d\n",sizeof(a[0][0]));
    //a[0][0]表示二维数组的第一个元素，内存占用量为4byte；
    printf("sizeof(a[0]) = %d\n",sizeof(a[0]));
    //a[0]相当于二维数组中第一维数组的数组名，即第一行的所有内容，占16byte；
    printf("sizeof(a[0]+1) = %d\n",sizeof(a[0]+1));
    //表示第二行的所有内容，内存占用量为4byte；
    printf("sizeof(a+1) = %d\n",sizeof(a+1));
    //数组名并非单独出现在sizeof()中，故表达式表示数组指针常量+1，占4byte；
    printf("sizeof(*a) = %d\n",sizeof(*a));
    //a表示数组指针常量，对其解引用结果为第一行的所有内容，占16byte；
    printf("sizeof(a[3]) = %d\n",sizeof(a[3]));
    //注意 sizeof()内部的表达式并不进行计算，所以此时的3无效，表示的二维数组一行的内容。
    return 0;

	//注意！！！：由于二维数组是由一维数组组成的，所以在对二维数组进行初始化时花括号内嵌套的必须是花括号！若是在花括号内用圆括号()进行初始化，且其中含有逗号，编译器会将其按照逗号表达式进行处理。

}


