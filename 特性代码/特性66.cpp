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
		.pfun = myfun,   //������ָ��ָ��Ҫ���ú����ĵ�ַ
	};
	gcode.pfun(100);
	/*
	auto f=[](int a,int b) {
		return a>b;
	};
	auto f=[x](int a,int b) {
		return a>x;
	};//x��������
	int x=0, y=1;
	auto g=[&](int x) {
		return ++y;
	};//y���������ã�����g����޸�y����Ҫע��y��������
	*/
	bool(*fp)(int, int)=[](int a,int b) {
		return a>b;
	};//������ʱ�ſ�ת��Ϊ����ָ��
}





