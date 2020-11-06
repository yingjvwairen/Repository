#include<iostream>
#include<cstdio>
using namespace std;
//这里打算整个求方阵行列式的函数
int det()//determinant
{
	//可以先化为三角形行列式再求值	
} 
int main()
{	
	int x,y;
	printf("依次输入未知数个数和方程数(用空格隔开\n");
	cin >> y >> x;
	if(x!=y)
		{cout<<"此方程有无限多解，这里不做讨论";return 0ul; }
	int a[x+100][y+100],i,j;
	for(i=1;i<=x;++i)
		{	
		printf("依次输入方程组的增广矩阵参数且各数间用空格隔开\n",i);		
			for(j=1;j<=y;++j)
				scanf("%d",&a[i][j]);
		}
	int b[y+100];
	for(int i=1;i<y+2;++i)
		cout << "x" << i << '=' << b[i] << endl;
}
 
