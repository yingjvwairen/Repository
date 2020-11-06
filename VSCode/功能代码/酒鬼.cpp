#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std; 
int main() 
{
	int m,ml,pg,pz,yh,hg,hz,qh;
		 char a[10],b[10]="不想"; 
		 cout << "赊账的话...也许能让你多喝几瓶。但是问题是你想不想赊账？" << endl;
		 cin >> a;
		 if(!strcmp(a,b))
		 {cout << "预算(元" <<endl;
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
		cout << "能喝" << yh << "瓶"<< endl << "还剩" << ml << "元钱";
			return 0;
		}
		 cout << "预算(元" <<endl;
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
			
		cout << "能喝" << yh << "瓶"<< endl << "还剩" << ml << "元钱";
}	

