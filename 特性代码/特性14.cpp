#include<iostream>
#include<cstdio>
using namespace std;

int main()
{	

	//使用行化简求可逆矩阵的逆 

	int a[4][8];
	printf("请依次输入矩阵三行中各自的数，格式如5 4 0\n");
	printf("你懂的，请输入第一行中的数，别乱来哈\n");
	scanf("%d %d %d",&a[1][1],&a[1][2],&a[1][3]);
	printf("请输入第二行中的数\n");
	scanf("%d %d %d",&a[2][1],&a[2][2],&a[2][3]);
	printf("请输入第三行中的数\n");
	scanf("%d %d %d",&a[3][1],&a[3][2],&a[3][3]); 
	
	for(int i=1;i<4;i++)
		{
			for(int j=4;j<7;j++)
				a[i][j]=0;
				a[i][i+3]=1;
		}
	
	//以下试图通过行化简将此矩阵化为标准型 
	
	

	int m,n,k,c,M=0;

for(int N=1;N<4;N++)
	{
		
		//以下写个行替换代码,试图将第一行与符合对角条件的行作对换 


		if(a[N][N])//先判断它是否符合对角条件 
		{
				for(c=1;c<7;c++)
			{
				k=a[1][c];
				a[1][c]=a[N][c];
				a[N][c]=k;//替换 
			}
		}	
		else
			for(m=1;m<4;m++)
			{
				if(a[m][N])//筛选符合对角条件的行 
				{
					for(c=1;c<7;c++)
					{
						k=a[1][c];
						a[1][c]=a[m][c];
						a[m][c]=k;//替换
					}
				}
			}
		//写个列转化的代码吧 
		

		double t;
		for(m=2;m<4;m++)
		{
				while(a[m][N]==0)//如果发现相应位置已为 0的话就跳到下一位置 
					m+=1,M++;
				if(m>3)
					break;//跳出此关于m的for循环 （虽然此break是在if语句下，但要注意不是跳出if语句，因为if语句不是一个循环，而break是跳出循环。
							//应注意此时跳出的应是包含break语句的关于m的for循环（因为break只能跳出一个循环语句（顺便说一下continue，continue是只能跳出一层循环，即一个循环语句中的一层  
					t=a[m][N]*1.000000/a[1][N];//通过与浮点数进行运算，实现数据的隐式转换 
					//double T=(double) a[1][N];
					//t=(double) T/a[m][N];
					//这里要说一下不用浮点数的变通方法
					//double T=a[1][N]*10000/a[m][N];
					//T= T/10 + ((T%10)>4); 
					//print("%d.%d%%",T/10,T%10);(四舍五入
					//还有： 
					//double v=0.000000;
					//v= (double) a[1][N]/(double)a[m][N];
					//格式化为字符串
					//char ret[32]={0};
					//sprintf(ret,"%d.%d%%",r/10,r%10); (sprintf这个函数可以把所得的小数转化成字符串 ，顺带一说atoi可以将字符串中的整型数字和正负号提取出来 (char to int
					for(n=1;n<7;n++)
						(double)a[m][n]=(double)a[m][n]-(double)a[1][n]*t;//[Error] lvalue required as left operand of assignment，即要求左值作为赋值的左操作数
						//(double)a[m][n]实际上是个右值，因为编译器实现是通过将a[m][n]的值分配给一个double类型临时变量后返回临时变量来实现的，而等号的左边不能是右值，所以编译出错
					m-=M;//不跳回来就麻烦了	
		}
		//以上，把第一行第N列变为了最简列 ,同时第N行一行的其他数据也发生了相应的变化 
	
		if(m>4)
			cout << "此矩阵不可逆";
			//众所周知，行交换完后得换回来才行 	
			
			
				for(c=1;c<7;c++)
			{
					k=a[N][c];
					a[N][c]=a[1][c];
					a[1][c]=k;
			}
			//换回来后还得把对角化简为1才行
			 t=1.000000/a[N][N];
			 for(c=1;c<7;c++)
			 a[N][c]=a[N][c]*t;
	} 
			//以上，将前三列列化简，此时此矩阵应为标准型 
	
	
	
			//以下是固定的输出代码，你懂的 
		 for(int x=1;x<4;x++)
			for(int y=4;y<7;y++)
		 {
		 			printf("%lf ",(double)a[x][y]);//将输入的数字输出			
					if(y%6==0)//行结束换行 
					printf("\n");//换个行,换行后默认左对齐 
		}	 
		
	return 0;

}    

