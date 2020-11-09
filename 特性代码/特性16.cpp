#include<iostream>
using namespace std;
int main()
{	
	bool b[1024];
	double a;int c,m=0,n,p;
	cin >> a;
	c=int(a),a=a-int(a);
	while(c!=0)
	{
		n=c%2;
		c=c/2;
		++m,b[m]=n;
	}
	for(int k=m;k>=1;--k)	
		cout << b[k];++m;
	for(int i=m;i!=25+m;++i)
	if(a*2>1)
		if(i==m)
		cout << ".1",a=a*p-int(a);
		else
		b[i]='1',a=a*p-int(a),cout << b[i];
	else
		if(i==m)
			cout << ".0",a*=2;
		else
		b[i]='0',a=a*2,cout << b[i];
}

