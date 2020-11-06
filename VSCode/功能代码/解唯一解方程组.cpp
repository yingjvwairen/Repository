#include<iostream>
#include<cstdio>
using namespace std;

int main()
{	

	//使用行化简求只含唯一解的方程组的解 

	int a[4][5];
	printf("请依次输入三个方程中x y z各自的系数以及等号右边的数，格式如5 2 4 0\n");
	printf("你懂的，请输入第一个方程，别乱来哈\n");
	scanf("%d %d %d %d",&a[1][1],&a[1][2],&a[1][3],&a[1][4]);
	printf("请输入第二个方程\n");
	scanf("%d %d %d %d",&a[2][1],&a[2][2],&a[2][3],&a[2][4]);
	printf("请输入第三个方程\n");
	scanf("%d %d %d %d",&a[3][1],&a[3][2],&a[3][3],&a[3][4]); 
	
	//以下试图化为标准型 
	



for(int N=1;N<4;N++)
	{
		
		//以下写个行替换代码,试图将第一行与第N行对换 


		int k,c;
		for(c=1;c<5;c++)
			{
				k=a[1][c];
				a[1][c]=a[N][c];
				a[N][c]=k;
			}
			
		//写个列转化的代码吧 
		
		int t,m,n;
		for(m=2;m<4;m++)
		{
				while(a[m][N]==0)//如果发现相应位置已为 0的话就跳到下一位置 
					m+=1;
				if(m>3)
					break;//跳出此关于m的for循环 
					t=a[1][N]/a[m][N];
					for(n=1;n<5;n++)
						a[m][n]=a[m][n]-a[1][n]*t;
					m-=1;//不跳回来就麻烦了	
		}
		//以上，把第一行第N列变为了最简列 ,同时第N行一行的其他数据也发生了相应的变化 
	
	
			//众所周知，行交换完后得换回来才行 	
			
			
				for(c=1;c<5;c++)
			{
					k=a[N][c];
					a[N][c]=a[1][c];
					a[1][c]=k;
			}
	} 
			//以上，将前三列列化简
	
	
	
	for(int i=1;i<4;i++)
	cout << a[i][4] << " " << endl;		 
		
	return 0;
}    




































	
	
	
	

