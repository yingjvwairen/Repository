
#include<iostream>

#include<stdlib.h> 

using namespace std;

#define len 3

/*
realloc��malloc��ʹ������
     (1)realloc(void *ptr,size_t size);
	 realloc�����Ѿ�������ڴ������·��䣬
	 �����ʼָ�����ΪNULL�����malloc�÷�һ�£����������ʼ�ڴ��С������ԭ�ڴ�飬�ٴλ�������������ǿ�ʼ�ڴ������ڴ˻�����ȥβ���ڴ�顣����ֵ�Ƿ�����ڴ���ͷָ�롣
        (2)malloc(zise_t size);
		malloc�Ƕ�û�з�����ڴ���ֱ�ӽ��з��䣬����ֵ�Ƿ�����ڴ��ķ���ֵ�Ƿ�����ڴ���ͷָ�롣ͨ��malloc����õ��ڴ��һ��Ҫ��free(size_t size)���ͷ��ڴ�顣
         (3)ͨ��realloc��malloc��������ڴ���Ƿ��ص�ָ�����޷������͵ģ������ڷ��غ����Ա���Զ���Ϊ�������͵�ָ�롣
*/

int main()

{

	int s;

	int **num = NULL;//ͨ������ָ��������һ����ά���飬Ȼ�����ȡֵ

	num = (int **)realloc(num, sizeof(int*)*len);

	for(int i=0;i<3;i++)


		num[i] = (int *)malloc(sizeof(int) * 2);


	for (int i = 0; i < len; i++)

	{

		cout << "����������:";

		cin >> s;

		num[i][0] = 1;

		num[i][1] = s;

		cout << num[i] << endl;

	}

}

