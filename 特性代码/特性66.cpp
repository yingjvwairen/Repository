#include <stdio.h>
#include <stdlib.h>
void (*pfun)(int data);
void myfun(int data) {
	printf("get data:%d\n",data);
}
int main(int argc,char *argv[]) {
	pfun = myfun;
	(*myfun)(100);
	int(*a)[10][10];
	int b[10][10];
	a=&b;
	typedef struct gfun {
		void (*pfun)(int);
	} gfun;
	gfun gcode= {
		.pfun = myfun,   //将函数指针指向要调用函数的地址
	};
	gcode.pfun(100);
	/*
	auto f=[](int a,int b) {
		return a>b;
	};
	auto f=[x](int a,int b) {
		return a>x;
	};//x被捕获复制
	int x=0, y=1;
	auto g=[&](int x) {
		return ++y;
	};//y被捕获引用，调用g后会修改y，需要注意y的生存期
	*/
	bool(*fp)(int, int)=[](int a,int b) {
		return a>b;
	};//不捕获时才可转换为函数指针
}





