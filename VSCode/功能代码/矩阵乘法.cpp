#include<iostream>
#include<cstdio>
using namespace std;

int main()
{	
	int x,y;
	printf("����������˾�����к���(�ÿո����\n");
	cin >> x >> y;
	int a[x+100][y+100],i,j;
	for(i=1;i<=x;++i)
	{	
	printf("�������뱻�˾����е�%d�е�����(�ÿո����\n",i);		
		for(j=1;j<=y;++j)
			scanf("%d",&a[i][j]);
	} 	
	printf("����˾��������\n");
		int z;
			cin >> z;	
		 int b[y+100][z+100],c[x+100][z+100],m,n,g;
	for(m=1;m<=y;m++)
	{	
	printf("��������˾����%d�е�����(�ÿո����\n",m);
		for(n=1;n<=z;n++)
			scanf("%d",&b[m][n]); 	
	}		
	
	
	for(m=1;m<=x;m++)
	{										
			for(g=1;g<=z;g++)
			    {
				  	c[m][g]=0;//ע��Ҫ��ֵ��˳���ʼ����ֵ 
						for(n=1;n<=y;n++)						
							c[m][g] = c[m][g] + a[m][n] * b[n][g];																			
				}
	}
	//�����ǹ̶���������룬�㶮�� 
		 for(m=1;m<=x;m++)
			for(g=1;g<=z;g++)
		 {
		 			printf("%d ",c[m][g]);//��������������			
					if(g%z==0)//�н������� 
					printf("\n");//������,���к�Ĭ������� 
		}	
}

 
