#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int x[32800];
int main(){
 int a=4,b=7;
 int M=RAND_MAX;
 for(int i=0;i<=M;++i)
 x[i+1]=(a*time(NULL)+b)%M,printf("%i\n",x[i]);
 // time(NULL)能获取当前的系统时间，返回的结果是一个time_t类型，其实就是一个大整数，其值表示自CUT（Coordinated Universal Time）时间1970年1月1日00:00:00（称为UNIX系统的Epoch时间）起到当前时刻的秒数
 // time(0)自然也行，毕竟NULL在C中是0的宏定义 
}

