#include<iostream>
using namespace std;
//关于do{}while(0)特性的用法

bool Execute()
{

   int *p = new int;

   bool bOk(true);
   //利用do{}while(0)的作用域
   do
   {
      //执行并进行错误处理时，可将待执行代码放置于do后的{}中，这样可以让代码进入循环体作用域内，此时就可利用break跳出循环的特性跳出代码块了
      bOk = -1;
      if(!bOk) break;

      bOk = 0;
      if(!bOk) break;

      bOk = 1;
      if(!bOk) break;

      // ..........

   }while(0);

    //利用循序结构，这里可以写结束或跳出代码块时需执行的代码
    delete p;   
    p = NULL;
    return bOk;
   
}

//#define SAFE_DELETE(p) do{ delete p; p = NULL;} while(0)

//假设这里去掉do...while(0)

#define SAFE_DELETE(p) {delete p; p = NULL;}

int main(){

    int*p=new int;

    //if(NULL != p){};else return 0;//else所在语句编译不会通过，因为大括号后的分号代表了一个空语句，导致else前就不是if语句了

    //if(NULL != p)SAFE_DELETE(p);else return 0;//所以此句编译通不过，因为相当于执行完大括号里的语句之后又执行了一个空语句之后才是else语句

    /*

即上一条语句被解释为：

    if(NULL != p){
        delete p; 
        p = NULL;
    }
        ;               //空语句
    else                //[Error] 'else' without a previous 'if'
        return 0;
   
    */
//可以看出错误出在;直接位于代码块的后面，但如果将代码嵌入do...while(0)则可以解决这类问题

#undef SAFE_DELETE

#define SAFE_DELETE(p) do{ delete p; p = NULL;} while(0)    //注意最后没有分号;

if(NULL != p)SAFE_DELETE(p);else return 0;

/*
解决的另一个办法就是遵循代码规范：

if (NULL != p)
{
    SAFE_DELETE(p);
}
else
{
    return 0;
}

*/
//这样就不会出问题了，但是这样编写的宏就使得代码的灵活性与简洁性就减弱了，也就不具有通用性和健壮性了。因为这样它就有对宏使用者的假设了，如其编码规范，技术水平等。 

}