#include <iostream>
#include <cstdio>
using namespace std;
int main() 
{
	int n,maxw;
	cout << "物品数n与背包最大重量" << endl;
	cin >> n >> maxw;
	struct goods 
	{
		float w;
		float v;
		float xjb;
		int Num;
	} g[n+1],t;
	double wdnmd;
	for(int i=1; i<=n; i++) 
	{
		cout << "g[" << i << "].w=";
		cin >> g[i].w;
		cout << "g[" << i << "].v=";
		cin >> g[i].v;
		g[i].Num=i;
		g[i].xjb=(g[i].v/g[i].w);
	}
	for(int i=1; i<=n-1; i++)
		for(int j=i+1; j<=n; j++)
			if(g[i].xjb<g[j].xjb) 
			{
				t=g[i];
				g[i]=g[j];
				g[j]=t;
			}
	int sumw=0,sumv=0,b=1;
	bool X[n+1];
	for(int m=1; m<=n+1; m++)
		X[m]=0;
	while(sumw+g[b].w<=maxw)
	{
		sumw=sumw+g[b].w;
		sumv=sumv+g[b].v;
		X[g[b].Num]=1;
		b++;
	}
	cout << "X=(";
	int j;
	for(j=1; j<n; j++)
		cout<<X[j]<<",";
	cout << X[j] << ")" << endl;
	cout << "总重:" << sumw << endl;
	cout << "总价值:" << sumv <<endl;
}
