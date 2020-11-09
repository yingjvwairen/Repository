#include<iostream>
#include<cstdio>
using namespace std;
#define N 1024
long func1(char *s)
{
	int i,t; 
	long ans =0;
	for(i=0;s[i];++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		t=s[i]-'0'; 
		if(s[i]>='A'&&s[i]<='Z')
		t=s[i]-'A'+10;
		if(s[i]>='a'&&s[i]<='z')
		t=s[i]-'a'+10; 
		ans=ans*16+t;
	}
	return ans;
} 
float func2(double m,int n)
{	
	if(n==2)
	{
char b[1024];
	int c,j=0,n,p;
	c=(int)m,m=m-c;
	while(c!=0)
	{
		n=c%2;
		c=c/2;
		++j,b[j]=char(48+n);
	}
	for(int k=j;k>=1;--k)	
		cout << b[k];++j;
	for(int i=j;i!=25+j;++i)
	if(m*2>1)
		if(i==j)
		cout << ".1",m=m*2-1;
		else
		b[i]='1',m=m*2-1,cout << b[i];
	else
		if(i==j)
			cout << ".0",m*=2;
		else
		b[i]='0',m=m*2,cout << b[i];	
	return 0;
	}
float ans=0,num=0;
	while(m) 
		ans=float(ans+int(m)%10)/n,++num,m/=10;
	for(int i=0;i!=num;++i) 
		ans=ans*8;
	return ans;
}
int main()
{
	double m,n;
	char s[N]; 
	printf("请输入进制\n");
	scanf("%lf",&n); 
	if(n==16) 
	{
	printf("请输入数值\n");
	scanf("%s",s); 
	m=func1(s),printf("%d",m);
	return 0x0UL;
	}
	printf("请输入数值\n");
	scanf("%lf",&m);
	func2(m,n);
}

