#include <stdio.h>

#include <string.h>

#include <windows.h>

#include <stdlib.h>

#include <conio.h>

#include <iomanip>

#include <math.h>

#include <iostream>

#define SIZE 100

using namespace std;

typedef struct student {

	int num;

	char name[30];

	int score[4];

} STU;

int Menu(void);

void Read_data(STU stu[],int n);

void Read_data1(STU stu[],int &n);

void Change_data(STU stu[],int n);

void Change_data1(STU stu[],int n);

void Delete_data(STU stu[],int &n);

void Delete_data1(STU stu[],int &n);

void Sortbynum(STU stu[],int n);

void Sortbyname(STU stu[],int n);

void Count_data(STU stu[],int n);

void Score_data(STU stu[],int n);

void Count_pass(STU stu[],int n);

void Count_average(STU stu[],int n);

void Show_data(STU stu[],int n);

void Write_data(STU stu[],int n);

int main() {

	STU stu[SIZE]= {0};

	int n,a,b;

	char ch;

	int oh;

	while(1)

	{

		ch = Menu();

		fflush(stdin);


		if(ch==0) {

			printf("\t\t********************************************\n");

			printf("\t\t\t* ��лʹ�� * \n");

			printf("\t\t\t* ѧ���Ծ����ͳ��ϵͳ * \n");

			printf("\t\t********************************************\n");

			exit(0);

		}

		printf("������ѧ��������n(n<=%d):", SIZE);

		scanf("%d", &n);

		switch (ch)

		{

			case 1:

				printf("���������������Ծ�����ķ�ʽ��\n***1.�ֶ������Ծ����(��׷��д��student.txt��,û�оʹ���)\t2.��student.txt�ļ��е����Ծ����***\n");

				scanf("%d",&oh);

				switch (oh)

				{

					case 1:

						Read_data(stu,n);

						system("pause");

						break;

					case 2:

						Read_data1(stu,n);

						system("pause");

						break;

					default:

						printf("����˵���Ŵ���!");

						system("pause");

						break;

				}

				break;

			case 2:

				printf("���������ֲ���ѧ���ķ�ʽ��\n***1.��ѧ�Ų���\t2.�����ֲ���***\n");

				scanf("%d",&oh);

				switch (oh)

				{

					case 1:

						Read_data1(stu,n);

						Change_data(stu,n);

						system("pause");

						break;

					case 2:

						Read_data1(stu,n);

						Change_data1(stu,n);

						system("pause");

						break;

					default:

						printf("����˵���Ŵ���!");

						system("pause");

						break;

				}

				break;

			case 3:

				printf("���������ֲ���ѧ���ķ�ʽ��\n***1.��ѧ�Ų���\t2.�����ֲ���***\n");

				scanf("%d",&oh);

				switch (oh)

				{

					case 1:

						Read_data1(stu,n);

						Delete_data(stu,n);

						system("pause");

						break;

					case 2:

						Read_data1(stu,n);

						Delete_data1(stu,n);

						system("pause");

						break;

					default:

						printf("����˵���Ŵ���!");

						system("pause");

						break;

				}

				break;

			case 4:

				printf("���������ֲ���ѧ���ķ�ʽ��\n***1.��ѧ�Ų���\t2.�����ֲ���***\n");

				scanf("%d",&oh);

				switch (oh)

				{

					case 1:

						Read_data1(stu,n);

						Sortbynum(stu,n);

						system("pause");

						break;

					case 2:

						Read_data1(stu,n);

						Sortbyname(stu,n);

						system("pause");

						break;

					default:

						printf("����˵���Ŵ���!");

						system("pause");

						break;

				}

				break;

			case 5:

				printf("���ɼ���:\n***1.���ѧ����������ٷֱ�\t2.�����Щѧ������Ϣ***\n");

				scanf("%d",&oh);

				switch (oh)

				{

					case 1:

						Read_data1(stu,n);

						Count_data(stu,n);

						system("pause");

						break;

					case 2:

						Read_data1(stu,n);

						Score_data(stu,n);

						system("pause");

						break;

					default:

						printf("����˵���Ŵ���!");

						system("pause");

						break;

				}

				break;

			case 6:

				Read_data1(stu,n);

				Count_pass(stu,n);

				system("pause");

				break;

			case 7:

				Read_data1(stu,n);

				Count_average(stu,n);

				system("pause");

				break;

			case 8:

				Read_data1(stu,n);

				Show_data(stu,n);

				system("pause");

				break;

			case 9:

				Read_data1(stu,n);

				Write_data(stu,n);

				system("pause");

				break;

			default:

				printf("����˵���Ŵ���!");

				system("pause");

				break;

		}

	}

	return 0;

}

/* �������ܣ���ʾ�˵�������û����������ѡ�� */

int Menu(void)

{
	system("cls");

	for(int i=0; i<10; i++)

	{

		cout<<endl;

	}

	cout<<setw(20);

	for(int i=0; i<35; i++)

	{

		cout<<'*';

	}

	cout<<endl;

	cout<<'\n';

	cout<<setw(46)<<"��ӭ����ѧ������ϵͳ"<<endl;

	cout<<'\n';

	cout<<setw(20);

	for(int i=0; i<30; i++) {
		cout<<' ';
	}

	cout<<endl;

	int itemSelected;

	cout<<setw(46)<<"\t���˵���\n";

	cout<<setw(46)<<"\t1.¼��ɼ�\n";

	cout<<setw(46)<<"\t2.�޸ĳɼ�\n";

	cout<<setw(46)<<"\t3.ɾ���ɼ�\n";

	cout<<setw(46)<<"\t4.��ѯѧ���ɼ�\n";

	cout<<setw(46)<<"\t5.��ѯ�ɼ���\n";

	cout<<setw(46)<<"\t6.����ѧ�������ʺ�������\n";

	cout<<setw(46)<<"\t7.����ѧ��ƽ���ֺͱ�׼��\n";

	cout<<setw(46)<<"\t8.�ɼ��б�\n";

	cout<<setw(46)<<"\t9.�����ļ�(ע��ÿ�ε��붼��ˢ�´��ļ�)\n";

	cout<<setw(46)<<"\t0.�˳�\n";

	cout<<setw(41)<<"\t���������ѡ��:";

	cout<<setw(20);

	scanf("%d", &itemSelected); /* �����û����� */

	system("cls");

	return itemSelected;

}

/* �������ܣ��ֶ�������� */

void Read_data(STU stu[],int n)

{

	int i=0,j,t;

	FILE *fp;

	if((fp=fopen("student.txt","r"))!=NULL)

	{

		printf("��ע��student.txt�е�ѧ���������ó���%d��\n",SIZE);
		
		while( !feof(fp))

		{

			fscanf(fp,"%d",&stu[i].num);

			fscanf(fp,"%s",stu[i].name);

			fscanf(fp,"%d",&stu[i].score[0]);

			fscanf(fp,"%d",&stu[i].score[1]);

			fscanf(fp,"%d",&stu[i].score[2]);

			j=0;

			while(j!=i)

			{

				if(stu[j].num==stu[i].num)

				{

					i--;

					break;
				}

				j++;

			}

			i++;

		}

			i--;//ע���������Լ�����Ϊfeof������ʵ���ڶ����ļ�ĩβʱ���������һ�ο��ַ���Ż᷵�ط���ֵ��ԭ�����£�  
			
			/*
			ʹ��feof������Ϊ�ж��ļ��Ƿ����ʱ��Ҫ�ر�ע��ĵط���
			�ڶ�ȡ�����з�ʱ��feof��������Ϊ���ļ���δ������
			���������ͼ��feof������Ϊѭ������ж������Ļ�������fread��fscanf�Ⱥ������ļ����еĶ�ȡ��������ʱ��feof�������ȡ���ļ�ĩβ�Ļ��з���ո��/t�ַ�������еĻ�����
			����Ϊ���ļ���δ���������ǻ����������һ��ѭ����
			���¶������һ��ѭ�������ȡ����һЩ���ַ�
			*/

				//����Ҳ�ɿ����ɼ��б���Ӧ�û��з���β 

	}

	printf("����student.txt��ѧ������Ϊ%d������ѧ��������n>%dʱ��¼�����\n������ѧ����ѧ�š���������ѧ�ɼ���Ӣ��ɼ��ͼƵ��ɼ�(�ÿո�������ҳ��������������봿���֣���������)\n",i,SIZE-i);

	for(t=i; t<n+i; t++)

	{

		scanf("%d %s %d %d %d",&stu[t].num,&stu[t].name,&stu[t].score[0],&stu[t].score[1],&stu[t].score[2]);

		j=0;

		while(j!=t) {

			if(stu[j].num==stu[t].num) {

				printf("ѧ���ظ�,���������룡\n");

				t--;

				break;
			}

			j++;

		}

	}

	if((fp=fopen("student.txt","a"))==NULL)

	{

		printf("¼���ļ�student.txtʧ�ܣ�\n");

		exit(0);

	}

	for(t=i; t<n+i; t++)

	{

		fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[t].num,stu[t].name,stu[t].score[0],stu[t].score[1],stu[t].score[2]);

	}

	fclose(fp);

	printf("��¼��\n");

}

/* �������ܣ����ı�student.txt�е����Ծ���� */

void Read_data1(STU stu[],int &n)

{

	int i,j;

	FILE *fp;

	if((fp=fopen("student.txt","r"))==NULL)

	{

		printf("���ļ�student.txtʧ�ܣ�\n");

		exit(0);

	}

	for(i=0; !feof(fp); i++)

	{

		fscanf(fp,"%d",&stu[i].num);

		fscanf(fp,"%s",stu[i].name);

		fscanf(fp,"%d",&stu[i].score[0]);

		fscanf(fp,"%d",&stu[i].score[1]);

		fscanf(fp,"%d",&stu[i].score[2]);

		j=0;

		while(j!=i) {

			if(stu[j].num==stu[i].num) {

				n--,i--;

				break;
			}

			j++;

		}

	}
	
	fclose(fp);


}


/* �������ܣ���ѧ�Ų�ѯѧ���Ծ�ĳɼ� */

void Sortbynum(STU stu[],int n)

{

	int number,i;

	printf("������Ҫ���ҵ�ѧ��ѧ��:");

	scanf("%d",&number);

	for(i=0; i<n; i++)

	{

		if(stu[i].num==number)

		{

			printf("ѧ��:%d\t����:%s\t��ѧ�ɼ�:%d\tӢ��ɼ�:%d\t�Ƶ��ɼ�:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			return;

		}

	}

	printf("��Ǹ,û���ҵ�,���Խ��ļ�ĩβ�Ļ��з���ո�ȥ�������ԣ�\n");

}

/* �������ܣ���������ѯѧ���Ծ�ĳɼ� */

void Sortbyname(STU stu[],int n)

{

	char named[10];

	int i;

	printf("������Ҫ���ҵ�ѧ��������");

	scanf("%s",named);

	for(i=0; i<n; i++)

	{

		if(strcmp(named,stu[i].name)==0)

		{

			printf("ѧ��:%d\t����:%s\t��ѧ�ɼ���%d\tӢ��ɼ���%d\t�Ƶ��ɼ�:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			return;

		}

	}

	printf("��Ǹ,û���ҵ�,���Խ��ļ�ĩβ�Ļ��з���ո�ȥ�������ԣ�\n");

}

/* �������ܣ�����ȫ��ѧ���ɼ��ļ����ʺ������ʣ����������в����ѧ������ */

void Count_pass(STU stu[],int n)

{

	int i,pass_num,t[4];

	float passrate;

	memset(t,0,sizeof(t));

	for(int j=0; j<3; j++) {

		for(i=0; i<n; i++)

		{

			if(stu[i].score[j]<60) t[0]++;

			else if(stu[i].score[j]<=80) t[1]++;

			else if(stu[i].score[j]<=90) t[2]++;

			else if(stu[i].score[j]<=100) t[3]++;

			pass_num=t[1]+t[2]+t[3];

			passrate=(float)(t[1]+t[2]+t[3])/n;

		}

		if(j==0) {

			printf("��ѧ��������:%d\n",pass_num);

			printf("��:%d\t��:%d\t��:%d\t��:%d\n",t[3],t[2],t[1],t[0]);

			printf("��ѧ�ɼ�������:%.2f\n",passrate);

			printf("��ѧ�ɼ�������:%.2f\n",(float)t[3]/n);

			t[0]=0,t[1]=0,t[2]=0,t[3]=0;

		}

		if(j==1) {

			printf("Ӣ�Ｐ������:%d\n",pass_num);

			printf("��:%d\t��:%d\t��:%d\t��:%d\n",t[3],t[2],t[1],t[0]);

			printf("Ӣ��ɼ�������:%.2f\n",passrate);

			printf("Ӣ��ɼ�������:%.2f\n",(float)t[3]/n);

			t[0]=0,t[1]=0,t[2]=0,t[3]=0;

		}

		if(j==2) {

			printf("�Ƶ���������:%d\n",pass_num);

			printf("��:%d\t��:%d\t��:%d\t��:%d\n",t[3],t[2],t[1],t[0]);

			printf("�Ƶ��ɼ�������:%.2f\n",passrate);

			printf("�Ƶ��ɼ�������:%.2f\n",(float)t[3]/n);

			t[0]=0,t[1]=0,t[2]=0,t[3]=0;

		}

	}

}

/* �������ܣ�����ѧ���ɼ���ƽ���ֺͱ�׼�� */

void Count_average(STU stu[],int n)

{

	int i;

	double sum=0,aver,temp=0,standard;

	for(int j=0; j<3; j++) {

		for(i=0; i<n; i++)

		{

			sum=stu[i].score[j]+sum;

		}

		aver=(float)sum/n;

		for(i=0; i<n; i++)

		{

			temp=(stu[i].score[j]-aver)*(stu[i].score[j]-aver)+temp;

		}

		standard=sqrt(temp/n);

		if(j==0)

		{

			printf("��ѧ�ɼ�ƽ����:%.2f\t�Ƶ��ɼ���׼��:%.2lf\n",aver,standard);

		}

		if(j==1)

		{

			printf("Ӣ��ɼ�ƽ����:%.2f\t�Ƶ��ɼ���׼��:%.2lf\n",aver,standard);

		}

		if(j==2)

		{

			printf("�Ƶ��ɼ�ƽ����:%.2f\t�Ƶ��ɼ���׼��:%.2lf\n",aver,standard);

		}
		
		sum=0;

	}

}

/* �������ܣ����ȫ��ѧ�������гɼ� */

void Show_data(STU stu[],int n)

{

	int i;

	for(i=0; i<n; i++)

	{

		printf("ѧ��:%d\t����:%s\t��ѧ�ɼ�:%d\tӢ��ɼ�:%d\t�Ƶ��ɼ�:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

	}

}

/* �������ܣ���ѧ�����гɼ����б������ı�score.txt�� */

void Write_data(STU stu[],int n)

{

	FILE *fp;

	int i;

	if((fp=fopen("score.txt","w"))==NULL)

	{

		printf("���ļ�ʧ�ܣ�\n");

		exit(0);

	}

	fprintf(fp,"���¸���ֱ��Ӧѧ�š���������ѧ�ɼ���Ӣ��ɼ��ͼƵ��ɼ�:\n");

	for(i=0; i<n; i++)

	{

		fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

	}

	fclose (fp);

	printf("�ѵ���\n");

}

/* �������ܣ���ѧ�Ų��Ҹ���ѧ���ĳɼ� */

void Change_data(STU stu[],int n)

{

	int number,i;

	printf("������Ҫ���ҵ�ѧ��ѧ��:");

	scanf("%d",&number);

	for(i=0; i<n; i++)

	{

		if(stu[i].num==number)

		{

			printf("ѧ��:%d\t����:%s\t��ѧ�ɼ�:%d\tӢ��ɼ�:%d\t�Ƶ��ɼ�:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			printf("��������Ҫ���ĵĿ�Ŀ���\n(��ѧΪ0,Ӣ��Ϊ1,�Ƶ�Ϊ2)\n");

			int j;

			scanf("%d",&j);

			if(j!=0 && j!=1 && j!=2)

			{

				printf("�����������");

			}

			else

			{

				int new_score;

				printf("��������ĺ�ĳɼ�");

				scanf("%d",&new_score);

				stu[i].score[j]=new_score;

				FILE *fp;

				if((fp=fopen("student.txt","w"))==NULL)

				{

					printf("����ʧ�ܣ�\n");

					exit(0);

				}

				for(i=0; i<n; i++)

				{

					fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

				}

				fclose (fp);

				printf("���ĳɹ�\n");

			}

			return;

		}

	}

	printf("��Ǹ,û���ҵ�,���Խ��ļ�ĩβ�Ļ��з���ո�ȥ�������ԣ�\n");

}

/* �������ܣ������ֲ��Ҹ���ѧ���ĳɼ� */

void Change_data1(STU stu[],int n)

{

	char named[10];

	int i;

	printf("������Ҫ���ҵ�ѧ��������");

	scanf("%s",named);

	for(i=0; i<n; i++)

	{

		if(strcmp(named,stu[i].name)==0)

		{

			printf("ѧ��:%d\t����:%s\t��ѧ�ɼ���%d\tӢ��ɼ���%d\t�Ƶ��ɼ�:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			printf("��������Ҫ���ĵĿ�Ŀ���\n(��ѧΪ0,Ӣ��Ϊ1,�Ƶ�Ϊ2)\n");

			int j;

			scanf("%d",&j);

			if(j!=0 && j!=1 && j!=2)

			{

				printf("�����������");

			}

			else

			{

				int new_score;

				printf("��������ĺ�ĳɼ�");

				scanf("%d",&new_score);

				stu[i].score[j]=new_score;

				FILE *fp;

				if((fp=fopen("student.txt","w"))==NULL)

				{

					printf("����ʧ�ܣ�\n");

					exit(0);

				}

				for(i=0; i<n; i++)

				{

					fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

				}

				fclose (fp);

				printf("���ĳɹ�\n");

			}

			return;

		}

	}

	printf("��Ǹ,û���ҵ�,���Խ��ļ�ĩβ�Ļ��з���ո�ȥ�������ԣ�\n");

}

/* �������ܣ���ѧ�Ų���ɾ��ѧ���ĳɼ� */

void Delete_data(STU stu[],int &n)

{

	int number,i,j;

	printf("������Ҫ���ҵ�ѧ��ѧ��:");

	scanf("%d",&number);

	for(i=0; i<n; i++)

	{

		if(stu[i].num==number)

		{

			j=i;
			
			stu[i].num=stu[n-1].num;

			strcpy(stu[i].name,stu[n-1].name);
			
			stu[i].score[0]=stu[n-1].score[0];

			stu[i].score[1]=stu[n-1].score[1];

			stu[i].score[2]=stu[n-1].score[2];
			
			stu[n-1]= {0};

			n--;
			
			FILE *fp;

			if((fp=fopen("student.txt","w"))==NULL)

			{

				printf("ɾ��ʧ�ܣ�\n");
		
				exit(0);

			}

			for(i=0; i<n; i++)

			{

				if(stu[i].num==stu[j].num) continue;

				fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			}
			
				if(j!=n) fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[j].num,stu[j].name,stu[j].score[0],stu[j].score[1],stu[j].score[2]);

			fclose (fp);

			printf("ɾ���ɹ�\n");

			return;

		}
		
		}

	printf("��Ǹ,û���ҵ�,���Խ��ļ�ĩβ�Ļ��з���ո�ȥ�������ԣ�\n");

}

/* �������ܣ������ֲ���ɾ��ѧ���ĳɼ� */

void Delete_data1(STU stu[],int &n)

{

	char named[30];

	int i,j;

	printf("������Ҫ���ҵ�ѧ������:");

	scanf("%s",named);

	for(i=0; i<n; i++)

	{

		if(strcmp(named,stu[i].name)==0)

		{

			j=i;

			stu[i].num=stu[n-1].num;

			strcpy(stu[i].name,stu[n-1].name);

			stu[i].score[0]=stu[n-1].score[0];

			stu[i].score[1]=stu[n-1].score[2];

			stu[i].score[2]=stu[n-1].score[2];
			
			stu[n-1]= {0};
			
			n--;
			
			FILE *fp;

			if((fp=fopen("student.txt","w"))==NULL)

			{

				printf("ɾ��ʧ�ܣ�\n");
		
				exit(0);

			}

			for(i=0; i<n; i++)

			{

				if(strcmp(stu[i].name,stu[j].name)==0) continue;

				fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			}
			
				if(j!=n) fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[j].num,stu[j].name,stu[j].score[0],stu[j].score[1],stu[j].score[2]);
			
			fclose (fp);

			printf("ɾ���ɹ�\n");

			return;

		}

	}

	printf("��Ǹ,û���ҵ�,���Խ��ļ�ĩβ�Ļ��з���ո�ȥ�������ԣ�\n");

}

/* �������ܣ����ɼ������ѧ�������Ͱٷֱ� */

void Count_data(STU stu[],int n)

{

	int i,t=0,low,high;

	float passrate;

	printf("������ɼ������ֵ");

	scanf("%d",&low);

	printf("������ɼ������ֵ");

	scanf("%d",&high);

	for(int j=0; j<3; j++) {

		for(i=0; i<n; i++)

		{

			if(low<=stu[i].score[j] && stu[i].score[j]<=high) t++;

		}

		if(j==0) {

			printf("��ѧ�ɼ��ﴦ�ڴ˳ɼ����е�����:%d\n",t);

			printf("��ѧ�ɼ��ﴦ�ڴ˳ɼ����е�����ռ��:%.2f\n",(float)t/n);

			t=0;

		}

		if(j==1) {

			printf("Ӣ��ɼ��ﴦ�ڴ˳ɼ����е�����:%d\n",t);

			printf("Ӣ��ɼ��ﴦ�ڴ˳ɼ����е�����ռ��:%.2f\n",(float)t/n);

			t=0;

		}

		if(j==2) {

			printf("�Ƶ��ɼ��ﴦ�ڴ˳ɼ����е�����:%d\n",t);

			printf("�Ƶ��ɼ��ﴦ�ڴ˳ɼ����е�����ռ��:%.2f\n",(float)t/n);

			t=0;

		}

	}

}

/* �������ܣ����ɼ������ѧ����Ϣ */

void Score_data(STU stu[],int n)

{

	int i,j,low,high,t;

	printf("������ɼ������ֵ");

	scanf("%d",&low);

	printf("������ɼ������ֵ");

	scanf("%d",&high);

	for(int j=0; j<3; j++)

	{
		for(i=0; i<n; i++)

		{

			if(low<=stu[i].score[j] && stu[i].score[j]<=high)

			{

				t++;

				if(j==0)

					printf("ѧ��:%d\t����:%s\t��ѧ�ɼ�:%d\n",stu[i].num,stu[i].name,stu[i].score[j]);

				if(j==1)

					printf("ѧ��:%d\t����:%s\tӢ��ɼ�:%d\n",stu[i].num,stu[i].name,stu[i].score[j]);

				if(j==2)

					printf("ѧ��:%d\t����:%s\t�Ƶ��ɼ�:%d\n",stu[i].num,stu[i].name,stu[i].score[j]);

			}

		}

	}

}
