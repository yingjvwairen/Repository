#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std; 
int main() 
{
	int m,ml,pg,pz,yh,hg,hz,qh;
		 string str1="����";
		 string str2; 
		 cout << "���˵Ļ�...Ҳ���������ȼ�ƿ���������������벻�����ˣ�" << endl;
		 cin >> str2;
		 if(str1==str2)
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
		 while(pg/4.00+pz/2.00>=1)
			{qh=pg/4.00+pz/2.00;
			pg%=4,pz%=2;
			yh=yh+qh;}
			
		cout << "�ܺ�" << yh << "ƿ"<< endl << "��ʣ" << ml << "ԪǮ";
}	

