#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int x[32800];
int main(){
 int a=4,b=7;
 int M=RAND_MAX;
 for(int i=0;i<=M;++i)
 x[i+1]=(a*time(NULL)+b)%M,printf("%i\n",x[i]);
 // time(NULL)�ܻ�ȡ��ǰ��ϵͳʱ�䣬���صĽ����һ��time_t���ͣ���ʵ����һ������������ֵ��ʾ��CUT��Coordinated Universal Time��ʱ��1970��1��1��00:00:00����ΪUNIXϵͳ��Epochʱ�䣩�𵽵�ǰʱ�̵�����
 // time(0)��ȻҲ�У��Ͼ�NULL��C����0�ĺ궨�� 
}

