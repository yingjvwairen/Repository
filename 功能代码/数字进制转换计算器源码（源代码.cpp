#include<iostream>
using namespace std;
int main()
{
	long n;//long类型就是long int类型，八个字节 
	int p,c,m=0,s[1024];
	cout << "输入需转换的数和转换进制数,之间用空格分隔或其中分割换行，输入完毕后回车即可\n"; 
	cin >> n >> p; 
	while(n!=0)
	{
		c=n%p;
		n=n/p;
		m++,s[m]=c;
	}
	for(int k=m;k>=1;--k)
	{
		if(s[k]>=10)
		cout << (char)(s[k]+55);//当进制转换大于10的时候，让需要用字母代替的数加上55，然后强制转换成字符型就可得到相对应的字母 
		else
		cout << s[k];
	}
} 
