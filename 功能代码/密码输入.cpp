#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
int main()
{	char* getline(char*,int);
	const char password[1024]="Tamako love story";//getch()��char���ִ�Сд�������⴮����Ҳ�����ִ�Сд�� 
	char str[1024];
	cout << "վ����������\n"; 
	getline(str,1024);
	if(strcmp(str,password))
	cout << "\n�����ȥ\n";
	else
	{cout << "\nɽ�����ӳ�������\n";return 0;} 
	printf("\n%c\n",str[2]);//������%s����������Խ�磬�������� 
	printf("\n%d\n",&str[2]);//������%s����������Խ�磬�������� 
}
char* getline(char* buffer,int len)
{
	int i=0;
	char ch;
	while(i<len-1)//ע����C�����б������������ܷ���forѭ���У�������Ҳ������� 
	{
		if(0!=kbhit())//�������Ƿ������루��keyboardhit�����еĻ��᷵��һ������ֵ �����򷵻��� 
		{
			ch=getch();//��ʱkbhitδʹ�����λ�����������������ͣ��ʿ����� 
			if(ch=='\r')// ֻ�����ϻس�������ʱ�Ż�������� ����Ҫ�ر�ע�������C������'\r'���ǻ���  
			break;
			putchar('*');
			buffer[i]=ch;
			++i;
		}
	//ע���ʱ�����õĿ⺯�����ܴ��л��ԣ����ͷ����getchar()	
	}
	buffer[i]='\0';
	return buffer;
}
