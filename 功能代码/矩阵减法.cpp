#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a[4][4],i,j;
	printf("����������9�����Ҵ����Ҵ��ϵ��´���ӵľ���������Ҹ������ÿո����\n");
	for(i=1;i<4;i++)
	{
		for(j=1;j<4;j++)
			scanf("%d",&a[i][j]);//�������� 	
	}
		for(i=1;i<4;i++)
			for(j=i;j<4;j++)
		 		//�����ǹ̶��Ľ������룬�㶮�� 
				 {
		 				int t;
		 				t=a[j][i];
		 				a[j][i]=a[i][j];
		 				a[i][j]=t;
		 		}
		 int b[4][4],c[4][4],m,n;
	printf("����������9�����Ҵ����Ҵ��ϵ��´����ӵľ���������Ҹ������ÿո����\n");
	for(m=1;m<4;m++)
	{
		for(n=1;n<4;n++)
			{
				scanf("%d",&b[m][n]);//�������� 	
				c[m][n] = a[m][n] - b[m][n];			
			} 
	}		
		 		
		//�����ǹ̶���������룬�㶮�� 
		 for(m=1;m<4;m++)
			for(n=1;n<4;n++)
		 {
		 			printf("%d ",c[m][n]);//��������������			
					if(n%3==0)//�н������� 
					printf("\n");//������,���к�Ĭ������� 
		}
}

 
