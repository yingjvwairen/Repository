#include<iostream>
#include<cstdio>
using namespace std;

int main()
{	
	int x,y;
	printf("��������к���(�ÿո����\n");
	cin >> x >> y;
	int a[x+100][y+100],i,j;
	for(i=1;i<=x;++i)
	{	
	printf("�������뱻�Ӿ����е�%d�е�����(�ÿո����\n",i);		
		for(j=1;j<=y;++j)
			scanf("%d",&a[i][j]);//�������� 	
	}
		 int b[x+100][y+100],c[x+100][y+100],m,n;
	for(m=1;m<=x;m++)
	{	
	printf("��������Ӿ����%d�е�����(�ÿո����\n",m);
		for(n=1;n<=y;n++)
			{
				scanf("%d",&b[m][n]);//�������� 	
				c[m][n] = a[m][n] + b[m][n];			
			} 
	}		
		 		
		//�����ǹ̶���������룬�㶮�� 
		 for(m=1;m<=x;m++)
			for(n=1;n<=y;n++)
		 {
		 			printf("%d ",c[m][n]);//��������������			
					if(n%y==0)//�н������� 
					printf("\n");//������,���к�Ĭ������� 
		}
}

 
