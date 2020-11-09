#include<iostream>
using namespace std;
int main()
{	
	char b[1024];
	double a;int c,m=0,n,p;
	cout << "请输入数值和需转化为的进制类型";
	cin >> a >> p;
	c=int(a),a=a-int(a);
	while(c!=0)
	{
		n=c%p;
		c=c/p;
		++m,b[m]=n;
	}
	for(int k=m;k>=1;--k)
	if(b[k]>=10)
		cout << char(b[k]+55); 
	else	
		cout << b[k];++m;
	for(int i=m;i!=25+m;++i)
	if(a*p>1)
		if(i==m)
		cout << "." << char(a*p+55),a=a*p-int(a);
		else
		b[i]='1',a=a*p-int(a),cout << b[i];
	else
		if(i==m)
			cout << ".0",a*=p;
		else
		b[i]='0',a=a*p-int(a),cout << b[i];
}

