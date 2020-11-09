#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a[4][4],i,j;
	printf("请依次输入9个数且从左到右从上到下代表加的矩阵的数字且各数间用空格隔开\n");
	for(i=1;i<4;i++)
	{
		for(j=1;j<4;j++)
			scanf("%d",&a[i][j]);//输入数字 	
	}
		for(i=1;i<4;i++)
			for(j=i;j<4;j++)
		 		//以下是固定的交换代码，你懂的 
				 {
		 				int t;
		 				t=a[j][i];
		 				a[j][i]=a[i][j];
		 				a[i][j]=t;
		 		}
		 int b[4][4],c[4][4],m,n;
	printf("请依次输入9个数且从左到右从上到下代表被加的矩阵的数字且各数间用空格隔开\n");
	for(m=1;m<4;m++)
	{
		for(n=1;n<4;n++)
			{
				scanf("%d",&b[m][n]);//输入数字 	
				c[m][n] = a[m][n] - b[m][n];			
			} 
	}		
		 		
		//以下是固定的输出代码，你懂的 
		 for(m=1;m<4;m++)
			for(n=1;n<4;n++)
		 {
		 			printf("%d ",c[m][n]);//将输入的数字输出			
					if(n%3==0)//行结束换行 
					printf("\n");//换个行,换行后默认左对齐 
		}
}

 
