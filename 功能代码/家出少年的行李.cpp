#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	//�ҳ�������������⣨ö�ٷ�
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
	//Goods g[n+100];//ע��nδ����ǰΪ����������Դ�ʱ������Ϊ�ڴ治���Է�������³�����ֹ
	cout << "��������Ʒ����������������" << "\n";
	cin >> n >> maxw;
	Goods g[n+100];//�������ڻ����ԭ����������Ҫ����ñ�Ԥ�����趨����ڴ�󣬲�Ȼ�ᵼ�����ݳ��ֲ������˵��һ�㶨��������Ҫ�ö���ñ�Ԥ���еĴ� 
	int wdnmd=0; //qiezi
	for(m=0;m<n;m++)
	{
	cout << "�������" << m+1 << "��������" << "\n";
	cin >> g[m].w;
	cout << "�������" << m+1 << "���ļ�ֵ" << "\n";
	cin >> g[m].v;
	}
	maxv=0;
	for(m=1;m<pow(2,n);m++)
		{	ttlw=0,ttlv=0;//ȡλ�����ѭ��Ҫ���� 
		for(y=0;y<n&&ttlw<maxw;y++)
			{
			wdnmd=pow(2,y);
			ttlw=ttlw+g[y].w*( (m & wdnmd) >> y );
			ttlv=ttlv+g[y].v*( (m & wdnmd) >> y );//ȡλ
			}
			if(ttlw>maxw)
			ttlv=ttlv-g[y-1].v;//ע��for�ڵĵ�������������ڵڶ����������ѭ��ʱ��ִ�е����һ�仰 
			if(maxv<ttlv)
			maxv=ttlv,x=m;
		}
		//cout << "X" << "=" << "(";
		//for(y=n-1;y;y-=1)
			//{
			//wdnmd=pow(2,y);
				//m= (x&wdnmd)>>y;//����ȡλ
						//cout << m << ",";
			//}
			//cout << m << ")" << endl;(��������� 
		y=0;//��ʼ��ѭ��ֵ 
		cout << "x" << "=" << "(";
		while(y<n-1)
		{
		wdnmd=pow(2,y);
			m=(x & wdnmd) >> y++;//����ȡλ
		cout << m << ",";
		}
		wdnmd=pow(2,y);
		m=(x & wdnmd) >> y; 
		cout << m << ")" << endl;
	cout << "�����ֻ���Դ��߼�ֵ" << maxv << "����Ʒ";	
	
}
