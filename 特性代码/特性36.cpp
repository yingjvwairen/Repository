
#include<iostream>

#include<stdlib.h> 

using namespace std;

#define len 3

/*
realloc和malloc的使用区别；
     (1)realloc(void *ptr,size_t size);
	 realloc是在已经分配好内存块的重新分配，
	 如果开始指针分配为NULL，则和malloc用法一致，否则如果开始内存块小，保存原内存块，再次基础新增，如果是开始内存块大，则在此基础减去尾部内存块。返回值是分配好内存块的头指针。
        (2)malloc(zise_t size);
		malloc是对没有分配过内存块的直接进行分配，返回值是分配好内存块的返回值是分配好内存块的头指针。通过malloc分配好的内存块一般要用free(size_t size)来释放内存块。
         (3)通过realloc和malloc来申请的内存块是返回的指针是无符号类型的，所以在返回后程序员可以定义为任意类型的指针。
*/

int main()

{

	int s;

	int **num = NULL;//通过二级指针来定义一个二维数组，然后进行取值

	num = (int **)realloc(num, sizeof(int*)*len);

	for(int i=0;i<3;i++)


		num[i] = (int *)malloc(sizeof(int) * 2);


	for (int i = 0; i < len; i++)

	{

		cout << "请输入数字:";

		cin >> s;

		num[i][0] = 1;

		num[i][1] = s;

		cout << num[i] << endl;

	}

}

