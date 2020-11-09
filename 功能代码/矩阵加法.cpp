#include<iostream>
#include<cstdio>
using namespace std;

int main()
{	
	int x,y;
	printf("依次输出行和列(用空格隔开\n");
	cin >> x >> y;
	int a[x+100][y+100],i,j;
	for(i=1;i<=x;++i)
	{	
	printf("依次输入被加矩阵中第%d行的数字(用空格隔开\n",i);		
		for(j=1;j<=y;++j)
			scanf("%d",&a[i][j]);//输入数字 	
	}
		 int b[x+100][y+100],c[x+100][y+100],m,n;
	for(m=1;m<=x;m++)
	{	
	printf("依次输入加矩阵第%d行的数字(用空格隔开\n",m);
		for(n=1;n<=y;n++)
			{
				scanf("%d",&b[m][n]);//输入数字 	
				c[m][n] = a[m][n] + b[m][n];			
			} 
	}		
		 		
		//以下是固定的输出代码，你懂的 
		 for(m=1;m<=x;m++)
			for(n=1;n<=y;n++)
		 {
		 			printf("%d ",c[m][n]);//将输入的数字输出			
					if(n%y==0)//行结束换行 
					printf("\n");//换个行,换行后默认左对齐 
		}
}

 
