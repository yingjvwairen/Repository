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
	printf("依次输入被转置矩阵中第%d行的数字(用空格隔开\n",i);		
		for(j=1;j<=y;++j)
			scanf("%d",&a[i][j]);
	}
	for(i=1;i<=x;i++)
			for(j=i;j<=y;j++)
		 		{
		 				int t;
		 				t=a[j][i];
		 				a[j][i]=a[i][j];
		 				a[i][j]=t;
		 		}		
		 for(i=1;i<=y;i++)
			for(j=1;j<=x;j++)
		 {
		 			printf("%d ",a[i][j]);			
					if(j%x==0)//行结束判定 
					printf("\n");//换个行，换行后默认左对齐 
		}
}

 
