#include <iostream>
using namespace std;
int main()
{
    //break 语句只能在循环或开关中使用
    //switch中的代码块是根据开关索引值和跳转表项跳转后顺序执行的，如果进入某个case后没有break语句，那么就会继续执行下一个case，因为所有case的指令都是平铺的
    //即case后面的常量仅起语句标号作用，系统一旦找到入口标号，就从此标号开始执行，不再进行标号判断，所以必须加上break语句，以便结束switch语句
    //但是开关中的最后一个代码块末尾可以不用break跳出，因为会自行通过大括号跳出
    int i = 10;
    int const a = 5, b = 7, c = 11;
    switch (i) //开关索引值必须是一个能计算出char、byte、short、int或enum类型的值
    //为什么？因为编译器需要switch后面的语句和case后面的值精确匹配，而计算机无法精确表达一个float等其他数据类型
    {
    default: //default代表开关索引值不匹配任一label时的默认跳转label
             /*
    关于 defaut的位置：

    MSDN 的说法：

     There can be at most one default statement.
     The default statement need not come at the end; it can appear anywhere in the body of the switch statement.
     In fact it is often more efficient if it appears at the beginning of the switch statement.
     A case or default label can only appear inside a switch statement. 

   最多有一个default语句在一个switch中
   default 声明不一定在末尾，它可以出现在switch的任何地方
   实际上如果default出现在switch的开头会更有效率。
    */

        cout << "default";
    case c:           //case后常量表达式的数据类型要和开关索引值的类型一样，且必须各不相同，否则对同一值就会有多种执行方案
        char d; 
        cout << c << d;

    case a:
        d ;
        cout << a << d;

    case b:
        d ;
        cout << b << d;
    }

    return 0;
}
/*
《CSAPP》一书中对switch跳转表这样说到：
跳转表是一个数组，表项i是一个代码段的地址，这个代码段实现当开关索引值等于i时程序应该采取的动作。
程序代码用开关索引值来执行一个跳转表内的数组引用，确定跳转指令的目标。
和使用一个很长的if else相比，使用跳转表的优点是执行开关语句的时间与开关情况的数量无关。
GCC根据开关情况的数量和开关情况的稀疏程度来翻译开关语句。当开关情况数量较多，并且值的跨度范围比较小时，就会使用跳转表。

跳转表的原理可以简单描述如下：

在使用switch case时，当代码中case的情况较为连续时，引入跳转表这种数据结构，对每一种case进行编号。
其中case不同对应代码执行不同的使用不用编号，case不同对应代码执行相同的，使用相同编号，case缺失的使用同一种编号。

分支数在三个及以下，且case值连续的情况下：
用cmp指令判断索引值是否与case后面的值相等，如相等就跳到对应的代码，全都不相等就通过jmp到default处

分支数在四个及以上，且case值连续的情况下：
让索引从0开始。由于case后面跟着的值是连续的，这里就直接用cmp判断switch中的值是否超过最大索引，超过则直接跳转到default处，如果在索引范围内，就通过
jmp dword ptr [edx*4+XXXXXXh]
跳转到对应的位置，这里[XXXXXX]保存的是一张跳转地址的表

分支数在四个及以上，且case值不连续的情况下：
我们知道在case后面的值不连续时编译器会用default的地址填充不存在的索引的跳转地址，使其连续。
所以case的值相差不多的情况下与上面相比没有什么区别，但是如果相差很多，编译器还逐条填充的话就造成了过多内存的浪费。这时就会利用二级跳转表（The Two-Level Jump Table)
用一张多出来的表保存着索引值，其中不存在的索引都替换为default的索引，对比上一种情况，替换地址需要4个字节，而替换索引只需要1个字节，引入一张索引的表更加合理

分支数在四个及以上，且case值之间相差巨大：
先判断表达式是否大于中间值，即采用二分法分而治之，如果大于中间值就继续与大的那堆数据的中间值比较，小于同理，之后循环往复
*/