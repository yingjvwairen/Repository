#include<iostream>
#include<cstdio>
using namespace std;
//�������������������ʽ�ĺ���
int det()//determinant
{
	//�����Ȼ�Ϊ����������ʽ����ֵ	
} 
int main()
{	
	int x,y;
	printf("��������δ֪�������ͷ�����(�ÿո����\n");
	cin >> y >> x;
	if(x!=y)
		{cout<<"�˷��������޶�⣬���ﲻ������";return 0ul; }
	int a[x+100][y+100],i,j;
	for(i=1;i<=x;++i)
		{	
		printf("�������뷽����������������Ҹ������ÿո����\n",i);		
			for(j=1;j<=y;++j)
				scanf("%d",&a[i][j]);
		}
	int b[y+100];
	for(int i=1;i<y+2;++i)
		cout << "x" << i << '=' << b[i] << endl;
}
 
