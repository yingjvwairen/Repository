#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std; 
int main() 
{
	int m,ml,pg,pz,yh,hg,hz,qh;
		 char a[10],b[10]="����"; 
		 cout << "���˵Ļ�...Ҳ���������ȼ�ƿ���������������벻�����ˣ�" << endl;
		 cin >> a;
		 if(!strcmp(a,b))
		 {cout << "Ԥ��(Ԫ" <<endl;
		 cin >> m;
		 yh=m/2;
		 ml=m-yh*2;
		 pg=yh;
		 pz=yh;
		 while(pg/4!=0||pz/2!=0)
			{hg=pg/4;
			 hz=pz/2;
			pg=pg-hg*4+hg+hz;
			pz=pz-hz*2+hg+hz;
			yh=yh+hg+hz;}
		cout << "�ܺ�" << yh << "ƿ"<< endl << "��ʣ" << ml << "ԪǮ";
			return 0;
		}
		 cout << "Ԥ��(Ԫ" <<endl;
		 cin >> m;
		 yh=m/2;
		 ml=m-yh*2;
		 pg=yh;
		 pz=yh;
		 while(pg/4!=0||pz/2!=0)
			{hg=pg/4;
			 hz=pz/2;
			pg=pg-hg*4+hg+hz;
			pz=pz-hz*2+hg+hz;
			yh=yh+hg+hz;}
			if(pz==1&&pg==1)
			yh++;
			if(pg==2&&pz<=1)
			yh+=2;
			if(pg==3&&pz==1)
			yh+=2;
			if(pg==3&&pz==0)
			yh++;
			
		cout << "�ܺ�" << yh << "ƿ"<< endl << "��ʣ" << ml << "ԪǮ";
}	

