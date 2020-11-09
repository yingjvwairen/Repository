#include<iostream>
#include<cstdio>
using namespace std;

int main()
{	
	int x,y;
	printf("依次输出被乘矩阵的行和列(用空格隔开\n");
	cin >> x >> y;
	int a[x+100][y+100],i,j;
	for(i=1;i<=x;++i)
	{	
	printf("依次输入被乘矩阵中第%d行的数字(用空格隔开\n",i);		
		for(j=1;j<=y;++j)
			scanf("%d",&a[i][j]);
	} 	
	printf("输入乘矩阵的列数\n");
		int z;
			cin >> z;	
		 int b[y+100][z+100],c[x+100][z+100],m,n,g;
	for(m=1;m<=y;m++)
	{	
	printf("依次输入乘矩阵第%d行的数字(用空格隔开\n",m);
		for(n=1;n<=z;n++)
			scanf("%d",&b[m][n]); 	
	}		
	
	
	for(m=1;m<=x;m++)
	{										
			for(g=1;g<=z;g++)
			    {
				  	c[m][g]=0;//注意要赋值（顺便初始化该值 
						for(n=1;n<=y;n++)						
							c[m][g] = c[m][g] + a[m][n] * b[n][g];																			
				}
	}
	//以下是固定的输出代码，你懂的 
		 for(m=1;m<=x;m++)
			for(g=1;g<=z;g++)
		 {
		 			printf("%d ",c[m][g]);//将输入的数字输出			
					if(g%z==0)//行结束换行 
					printf("\n");//换个行,换行后默认左对齐 
		}	
}

 
