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
	printf("�������뱻ת�þ����е�%d�е�����(�ÿո����\n",i);		
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
					if(j%x==0)//�н����ж� 
					printf("\n");//�����У����к�Ĭ������� 
		}
}

 
