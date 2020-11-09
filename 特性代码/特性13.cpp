#include<stdio.h>
#define N 1024
long func1(char *s)
{
	int i,t; 
	long ans =0;
	for(i=0;s[i];++i)//未赋值的字符型变量的初值全为'\0'，ASCII码则为0
	{
		if(s[i]>='0'&&s[i]<='9')
		t=s[i]-'0';//注意字符型变量的字符在内存空间中的实际存在形式其实就是ASCII码的值，是一个数，所以可以进行运算 
		if(s[i]>='A'&&s[i]<='Z')
		t=s[i]-'A'+10;//A代表10，所以用减去A的ASCII码值再加十的方法可以得到原数
		if(s[i]>='a'&&s[i]<='z')
		t=s[i]-'a'+10;//实际上十六进制中的字母按ASCII码排序的话也最多只能到达f 
		ans=ans*16+t;
	}
	return ans;
 } 
long func2(int m,int n)
{	
	float ans=0,num=0;
	while(m)//这里比用m/10多了一次循环 
		ans=float(ans+m%10)/n,++num,m/=10;
	for(int i=0;i!=num;++i)//这里比用int i=1多了一次循环 
		ans=ans*8;
	return ans;
}
int main()
{
	int m,n;
	char s[N];//字符串与字符数组相结合的方式定义字符串变量
	printf("请输入进制\n");
	scanf("%d",&n); 
	if(n==16) 
	{
	printf("请输入数值\n");
	scanf("%s",s);//注意此处要用%s输入一个字符串，而不是用%c输入一个字符
	m=func1(s),printf("%d",m);
	return 0x0UL;//U和L分别是数值的后缀，U或u代表其前数值是无符号型（unsigned，L或l代表其前数值是长整型（long，而0x是代表其后数值是16进制的前缀 
				//这里的return起终止程序运行之用，顺带防止了控制流往后的多余语句执行 
	}
	printf("请输入数值\n");
	scanf("%d",&m);
	m=func2(m,n),printf("%d",m);
}
