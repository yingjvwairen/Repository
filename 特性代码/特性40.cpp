#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	FILE *pF;
	pF=(FILE*)malloc(128);

FILE *fp=fopen("、？《》“”：","ab+");//文件名不能包括半角的 \ / " < > | ? * : 其中任何一个字符，但是全角符号则没有这种限制 

int a=0,b,i;    

while(getc(fp)!=EOF)

a++;

for(i=1;i<1024*128-a;i++)

putc(0,fp);

fclose(fp);

}

