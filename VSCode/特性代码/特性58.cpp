#include<iostream>
#include<malloc.h> 
using namespace std;
   void  buf( char **s)

    {

           *s = "message";

    }
int main()
{
	char  **s1 ;

	s1 = (char **) malloc(sizeof(char*));//ϵͳ����δ�����ַ��ָ�룬Ĭ�ϻ��ʼ��ΪNULL������ָ�롣��˳�������ʱ��*s�ᱨ�����ָ�벻ָ���κ�����
	
	//��������malloc��sizeof��....����,ע��sizeof����������Կ��ٵ��Ǹ�4���ֽڵ���������м��� * ����ʵû��ϵ�ģ���Ϊ��������ָ���������һ��ռ���ĸ��ֽڴ�С���ڴ�ռ�
	
	//ע�⣺32bit����ϵͳ��ָ���С�Ż���4���ֽڣ������ 64λ OS ��Ļ���ӦΪ8���ֽ�	

	*s1 =  "hello world";
   
	char *s2 ;

	buf(&s2);

	printf("%s\n%s",*s1,s2);

    free(s1);
   
}

