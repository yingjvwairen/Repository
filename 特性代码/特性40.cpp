#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	FILE *pF;
	pF=(FILE*)malloc(128);

FILE *fp=fopen("��������������","ab+");//�ļ������ܰ�����ǵ� \ / " < > | ? * : �����κ�һ���ַ�������ȫ�Ƿ�����û���������� 

int a=0,b,i;    

while(getc(fp)!=EOF)

a++;

for(i=1;i<1024*128-a;i++)

putc(0,fp);

fclose(fp);

}

