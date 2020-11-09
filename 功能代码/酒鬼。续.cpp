#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std; 
int main() 
{
	int m,ml,pg,pz,yh,hg,hz,qh;
		 string str1="不想";
		 string str2; 
		 cout << "赊账的话...也许能让你多喝几瓶。但是问题是你想不想赊账？" << endl;
		 cin >> str2;
		 if(str1==str2)
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
		 while(pg/4.00+pz/2.00>=1)
			{qh=pg/4.00+pz/2.00;
			pg%=4,pz%=2;
			yh=yh+qh;}
			
		cout << "能喝" << yh << "瓶"<< endl << "还剩" << ml << "元钱";
}	

