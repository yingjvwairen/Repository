
#include <stdio.h>

 

#define SIZE 1024

/*

I/O缓冲：

有了缓冲机制以后，多个读写操作可以合并为一次系统调用，

减少了系统调用的次数，将大大提高程序的运行效率。





标准I/O中，一个打开的文件称为流(stream)，

流可以用于读(输入流)、写(输出流)或读写(输入输出流)。

每个进程在启动后就会打开三个流，

分别对应：stdin(标准输入流)、stdout(标准输出流)以及stderr(标准错误输出流)

*/

 

 

/*

fopen:

#include <stdio.h>

FILE *fopen(const char *path, const char *mode);



"r"或"rb"：以只读方式打开。

"w"或"wb"：以只写方式打开，并把文件长度截短为零。

"a"或"ab"：以写方式打开，新内容追加在文件尾。

"r+"或"rb+"或"r+b"：以更新方式打开(读和写)。

"w+"或"wb+"或"w+b"：以更新方式打开，并把文件长度截短为零。

"a+"或"ab+"或"a+b"：以更新方式打开，新内容追加在文件尾。



注：字母b表示文件是一个二进制文件而不是文本文件

*/

int main1()

{ 

	//标准I/O函数并不直接操作文件描述符，而是使用文件指针

	//FILE *fp = fopen("fopen.c","w+");

	//FILE *fp = fopen("ffopen.c","a+");

	FILE *fp = fopen("fffopen.c","r+");

	if(fp == NULL)

	{

		perror("fopen ");

		return -1;

	}

	else

	{

		printf("success\n");

	}

	return 0;

}

 

/*

fread:

#include <stdio.h>

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

    

数据从文件流stream读到ptr指向的数据缓冲区里。

size参数指定每个数据记录的长度，nmemb给出要传输的记录的个数。

函数的返回值是成功读到数据缓冲区里的记录的个数(不是字节数)。

*/

 

int main2()

{

	FILE *fp = fopen("sqstack.c","ab+");

	if(fp == NULL)

	{

		perror("fopen ");

		return -1;

	}

	

	char buf[SIZE] = {0};

 

	int ret;

	while(ret = fread (buf,sizeof(char),SIZE-1,fp))

	{

		buf[ret*sizeof(char)] = '\0';

		printf("%s\n",buf);

	}

	//feof()只用于测试流文件的结束，当到达结尾时，返回非0

	if(ret == 0 && !feof(fp))

	{

		perror("fread ");

		return -1;

	}

	printf("read over\n");

	fclose(fp);

	return 0;

}

 

/*

fwrite()从指定的数据缓冲区里取出数据记录，并把它们写到输出流中

#include <stdio.h>

size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);

它的返回值是成功写入的记录个数。

*/

 

int main3()

{

	FILE *fp = fopen("sqstack.c","ab+");

	if(fp == NULL)

	{

		perror("fopen ");

		return -1;

	}

	

	FILE *fp1 = fopen("stack.c","ab+");

	if(fp == NULL)

	{

		perror("fopen ");

		return -1;

	}

	

	char buf[SIZE] = {0};

	

	int ret;

	while(ret = fread (buf,sizeof(char),SIZE-1,fp))

	{

		fwrite (buf,sizeof(char),SIZE-1,fp1);

	}

	//feof()只用于测试流文件的结束，当到达结尾时，返回非0

	if(ret == 0 && !feof(fp))

	{

		perror("fread ");

		return -1;

	}

	printf("read over\n");

	

	fclose(fp);

	fclose(fp1);

	

	return 0;

}

/*

fgetc() :  

从文件流里取出下一个字节并把它作为一个字符返回。

当它到达文件结尾或出现错误时，返回EOF

#include <stdio.h>

int fgetc(FILE *stream);

int getc(FILE *stream);

int getchar(void);



fputc():

fputc()把一个字符写到一个输出文件流中，

它返回写入的值，如果失败，则返回EOF。

#include <stdio.h>

int fputc(int c, FILE *stream);

int putc(int c, FILE *stream);

int putchar(int c);



*/

int main()

{

	FILE *fp = fopen("sqstack.c","ab+");

	if(fp == NULL)

	{

		perror("fopen ");

		return -1;

	}

	

	FILE *fp1 = fopen("qsstack.c","ab+");

	if(fp == NULL)

	{

		perror("fopen ");

		return -1;

	}

	/*

	char buf[SIZE] = {0};



	while(1)

	{

		int c = fgetc(fp);

		if(c == EOF)

			break;

		fputc(c,fp1);

	}

	*/

	

 

	int c = fgetc(fp);

	while(c != EOF)

	{

		fputc(c,fp1);

		c = fgetc(fp);

	}

	if(feof(fp))

	{

		printf("read over\n");

	}

	else

	{

		printf(" something went wrong\n");

	}

 

	fclose(fp);

	fclose(fp1);

	return 0;

}

 

 

