#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	//家出少年的行李问题（枚举法
	int m,n,maxw,ttlw,maxv,ttlv,x,y;
	struct Goods
	{
		int w;
		int v;
	};
	//struct Goods
	//{
	//	int w;
	//	int v;
	//} g[n+100]; 
	//Goods g[n+100];//注意n未输入前为随机数，所以此时容易因为内存不足以分配而导致程序终止
	cout << "请输入物品件数与行李最大承重" << "\n";
	cin >> n >> maxw;
	Goods g[n+100];//这里由于缓存的原因，所以数组要定义得比预计所需定义的内存大，不然会导致数据出现差错（所以说，一般定义数组需要得定义得比预算中的大 
	int wdnmd=0; //qiezi
	for(m=0;m<n;m++)
	{
	cout << "请输入第" << m+1 << "件的重量" << "\n";
	cin >> g[m].w;
	cout << "请输入第" << m+1 << "件的价值" << "\n";
	cin >> g[m].v;
	}
	maxv=0;
	for(m=1;m<pow(2,n);m++)
		{	ttlw=0,ttlv=0;//取位后外层循环要清零 
		for(y=0;y<n&&ttlw<maxw;y++)
			{
			wdnmd=pow(2,y);
			ttlw=ttlw+g[y].w*( (m & wdnmd) >> y );
			ttlv=ttlv+g[y].v*( (m & wdnmd) >> y );//取位
			}
			if(ttlw>maxw)
			ttlv=ttlv-g[y-1].v;//注意for内的第三个语句是由于第二条语句跳出循环时所执行的最后一句话 
			if(maxv<ttlv)
			maxv=ttlv,x=m;
		}
		//cout << "X" << "=" << "(";
		//for(y=n-1;y;y-=1)
			//{
			//wdnmd=pow(2,y);
				//m= (x&wdnmd)>>y;//继续取位
						//cout << m << ",";
			//}
			//cout << m << ")" << endl;(从右往左版 
		y=0;//初始化循环值 
		cout << "x" << "=" << "(";
		while(y<n-1)
		{
		wdnmd=pow(2,y);
			m=(x & wdnmd) >> y++;//继续取位
		cout << m << ",";
		}
		wdnmd=pow(2,y);
		m=(x & wdnmd) >> y; 
		cout << m << ")" << endl;
	cout << "你最多只可以带走价值" << maxv << "的物品";	
	
}
