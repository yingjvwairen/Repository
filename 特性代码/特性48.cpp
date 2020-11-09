
#include <stdio.h>

 

#define SIZE 1024

/*

I/O���壺

���˻�������Ժ󣬶����д�������Ժϲ�Ϊһ��ϵͳ���ã�

������ϵͳ���õĴ������������߳��������Ч�ʡ�





��׼I/O�У�һ���򿪵��ļ���Ϊ��(stream)��

���������ڶ�(������)��д(�����)���д(���������)��

ÿ��������������ͻ����������

�ֱ��Ӧ��stdin(��׼������)��stdout(��׼�����)�Լ�stderr(��׼���������)

*/

 

 

/*

fopen:

#include <stdio.h>

FILE *fopen(const char *path, const char *mode);



"r"��"rb"����ֻ����ʽ�򿪡�

"w"��"wb"����ֻд��ʽ�򿪣������ļ����Ƚض�Ϊ�㡣

"a"��"ab"����д��ʽ�򿪣�������׷�����ļ�β��

"r+"��"rb+"��"r+b"���Ը��·�ʽ��(����д)��

"w+"��"wb+"��"w+b"���Ը��·�ʽ�򿪣������ļ����Ƚض�Ϊ�㡣

"a+"��"ab+"��"a+b"���Ը��·�ʽ�򿪣�������׷�����ļ�β��



ע����ĸb��ʾ�ļ���һ���������ļ��������ı��ļ�

*/

int main1()

{ 

	//��׼I/O��������ֱ�Ӳ����ļ�������������ʹ���ļ�ָ��

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

    

���ݴ��ļ���stream����ptrָ������ݻ������

size����ָ��ÿ�����ݼ�¼�ĳ��ȣ�nmemb����Ҫ����ļ�¼�ĸ�����

�����ķ���ֵ�ǳɹ��������ݻ�������ļ�¼�ĸ���(�����ֽ���)��

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

	//feof()ֻ���ڲ������ļ��Ľ������������βʱ�����ط�0

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

fwrite()��ָ�������ݻ�������ȡ�����ݼ�¼����������д���������

#include <stdio.h>

size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);

���ķ���ֵ�ǳɹ�д��ļ�¼������

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

	//feof()ֻ���ڲ������ļ��Ľ������������βʱ�����ط�0

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

���ļ�����ȡ����һ���ֽڲ�������Ϊһ���ַ����ء�

���������ļ���β����ִ���ʱ������EOF

#include <stdio.h>

int fgetc(FILE *stream);

int getc(FILE *stream);

int getchar(void);



fputc():

fputc()��һ���ַ�д��һ������ļ����У�

������д���ֵ�����ʧ�ܣ��򷵻�EOF��

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

 

 

