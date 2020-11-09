#include<stdio.h>
#include<malloc.h>
using namespace std;
int main(){
	FILE *fp=fopen("C:\\Users\\q2423\\Desktop\\Ьиад37.txt","ab");
	fseek(fp,0,SEEK_END);
	long size = ftell(fp);
	char *buffer=(char*)calloc(128*1024-size,1);
	fwrite(buffer,128*1024-size,1,fp);
	fclose(fp);
}

