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

			printf("\t\t\t* ???? * \n");

			printf("\t\t\t* ?????????? * \n");

			printf("\t\t********************************************\n");

			exit(0);

		}

		printf("????????n(n<=%d):", SIZE);

		scanf("%d", &n);

		switch (ch)

		{

			case 1:

				printf("???????????????\n***1.????????(?????student.txt?,?????)\t2.?student.txt?????????***\n");

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

						printf("????????!");

						system("pause");

						break;

				}

				break;

			case 2:

				printf("?????????????\n***1.?????\t2.?????***\n");

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

						printf("????????!");

						system("pause");

						break;

				}

				break;

			case 3:

				printf("?????????????\n***1.?????\t2.?????***\n");

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

						printf("????????!");

						system("pause");

						break;

				}

				break;

			case 4:

				printf("?????????????\n***1.?????\t2.?????***\n");

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

						printf("????????!");

						system("pause");

						break;

				}

				break;

			case 5:

				printf("????:\n***1.???????????\t2.?????????***\n");

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

						printf("????????!");

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

				printf("????????!");

				system("pause");

				break;

		}

	}

	return 0;

}

/* ????????????????????? */

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

	cout<<setw(46)<<"??????????"<<endl;

	cout<<'\n';

	cout<<setw(20);

	for(int i=0; i<30; i++) {
	
		cout<<' ';
		
	}

	cout<<endl;

	int itemSelected;

	cout<<setw(46)<<"\t????\n";

	cout<<setw(46)<<"\t1.????\n";

	cout<<setw(46)<<"\t2.????\n";

	cout<<setw(46)<<"\t3.????\n";

	cout<<setw(46)<<"\t4.??????\n";

	cout<<setw(46)<<"\t5.?????\n";

	cout<<setw(46)<<"\t6.???????????\n";

	cout<<setw(46)<<"\t7.???????????\n";

	cout<<setw(46)<<"\t8.????\n";

	cout<<setw(46)<<"\t9.????(?????????????)\n";

	cout<<setw(46)<<"\t0.??\n";

	cout<<setw(41)<<"\t???????:";

	cout<<setw(20);

	scanf("%d", &itemSelected); /* ?????? */

	system("cls");

	return itemSelected;

}

/* ??????????? */

void Read_data(STU stu[],int n)

{

	int i=0,j,t;

	FILE *fp;

	if((fp=fopen("student.txt","r"))!=NULL)

	{

		printf("???student.txt??????????%d?\n",SIZE);
		
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

	}

	printf("??student.txt??????%d????????n>%d??????\n??????????????????????????(??????????????????????????)\n",i-1,SIZE-i+1);
	
	//??????i-1???i???feof????????????????????????????????????? 
	
	/*
		??feof???????????????????????
		?????????feof?????????????
		???????feof?????????????????fread?fscanf?????????????????feof??????????????????/t??????????
		????????????????????????
		?????????????????????
	*/

	for(t=i-1; t<n+i-1; t++)

	{

		scanf("%d %s %d %d %d",&stu[t].num,&stu[t].name,&stu[t].score[0],&stu[t].score[1],&stu[t].score[2]);

		j=0;

		while(j!=t) {

			if(stu[j].num==stu[t].num) {

				printf("????,??????\n");

				t--;

				break;
			}

			j++;

		}

	}

	if((fp=fopen("student.txt","a"))==NULL)

	{

		printf("????student.txt???\n");

		exit(0);

	}

	for(t=i-1; t<n+i-1; t++)

	{

		fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[t].num,stu[t].name,stu[t].score[0],stu[t].score[1],stu[t].score[2]);

	}

	fclose(fp);

	printf("???\n");

}

/* ????????student.txt??????? */

void Read_data1(STU stu[],int &n)

{

	int i,j;

	FILE *fp;

	if((fp=fopen("student.txt","r"))==NULL)

	{

		printf("????student.txt???\n");

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

				n--,i--;//?????? n,i-- ??????????????????????? 

				break;
			}

			j++;

		}

	}

	fclose(fp);

	
}


/* ????????????????? */

void Sortbynum(STU stu[],int n)

{

	int number,i;

	printf("???????????:");

	scanf("%d",&number);

	for(i=0; i<n; i++)

	{

		if(stu[i].num==number)

		{

			printf("??:%d\t??:%s\t????:%d\t????:%d\t????:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			return;

		}

	}

	printf("????????????????????????????\n");

}

/* ????????????????? */

void Sortbyname(STU stu[],int n)

{

	char named[30];

	int i;

	printf("????????????");

	scanf("%s",named);

	for(i=0; i<n; i++)

	{

		if(strcmp(named,stu[i].name)==0)

		{

			printf("??:%d\t??:%s\t?????%d\t?????%d\t????:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			return;

		}

	}

	printf("????????????????????????????\n");

}

/* ?????????????????????????????????? */

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

			printf("??????:%d\n",pass_num);

			printf("?:%d\t?:%d\t?:%d\t?:%d\n",t[3],t[2],t[1],t[0]);

			printf("???????:%.2f\n",passrate);

			printf("???????:%.2f\n",(float)t[3]/n);

			t[0]=0,t[1]=0,t[2]=0,t[3]=0;

		}

		if(j==1) {

			printf("??????:%d\n",pass_num);

			printf("?:%d\t?:%d\t?:%d\t?:%d\n",t[3],t[2],t[1],t[0]);

			printf("???????:%.2f\n",passrate);

			printf("???????:%.2f\n",(float)t[3]/n);

			t[0]=0,t[1]=0,t[2]=0,t[3]=0;

		}

		if(j==2) {

			printf("??????:%d\n",pass_num);

			printf("?:%d\t?:%d\t?:%d\t?:%d\n",t[3],t[2],t[1],t[0]);

			printf("???????:%.2f\n",passrate);

			printf("???????:%.2f\n",(float)t[3]/n);

			t[0]=0,t[1]=0,t[2]=0,t[3]=0;

		}

	}

}

/* ??????????????????? */

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

			printf("???????:%.2f\t???????:%.2lf\n",aver,standard);

		}

		if(j==1)

		{

			printf("???????:%.2f\t???????:%.2lf\n",aver,standard);

		}

		if(j==2)

		{

			printf("???????:%.2f\t???????:%.2lf\n",aver,standard);

		}
		
			sum=0;

	}

}

/* ???????????????? */

void Show_data(STU stu[],int n)

{

	int i;

	for(i=0; i<n; i++)

	{

		printf("??:%d\t??:%s\t????:%d\t????:%d\t????:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

	}

}

/* ????????????????????score.txt? */

void Write_data(STU stu[],int n)

{

	FILE *fp;

	int i;

	if((fp=fopen("score.txt","w"))==NULL)

	{

		printf("???????\n");

		exit(0);

	}

	fprintf(fp,"????????????????????????????:\n");

	for(i=0; i<n; i++)

	{

		fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

	}

	fclose (fp);

	printf("???\n");

}

/* ????????????????? */

void Change_data(STU stu[],int n)

{

	int number,i;

	printf("???????????:");

	scanf("%d",&number);

	for(i=0; i<n; i++)

	{

		if(stu[i].num==number)

		{

			printf("??:%d\t??:%s\t????:%d\t????:%d\t????:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			printf("????????????\n(???0,???1,???2)\n");

			int j;

			scanf("%d",&j);

			if(j!=0 && j!=1 && j!=2)

			{

				printf("??????");

			}

			else

			{

				int new_score;

				printf("?????????");

				scanf("%d",&new_score);

				stu[i].score[j]=new_score;

				FILE *fp;

				if((fp=fopen("student.txt","w"))==NULL)

				{

					printf("?????\n");

					exit(0);

				}

				for(i=0; i<n; i++)

				{

					fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

				}

				fclose (fp);

				printf("????\n");

			}

			return;

		}

	}

	printf("????????????????????????????\n");

}

/* ????????????????? */

void Change_data1(STU stu[],int n)

{

	char named[30];

	int i;

	printf("????????????");

	scanf("%s",named);

	for(i=0; i<n; i++)

	{

		if(strcmp(named,stu[i].name)==0)

		{

			printf("??:%d\t??:%s\t?????%d\t?????%d\t????:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			printf("????????????\n(???0,???1,???2)\n");

			int j;

			scanf("%d",&j);

			if(j!=0 && j!=1 && j!=2)

			{

				printf("??????");

			}

			else

			{

				int new_score;

				printf("?????????");

				scanf("%d",&new_score);

				stu[i].score[j]=new_score;

				FILE *fp;

				if((fp=fopen("student.txt","w"))==NULL)

				{

					printf("?????\n");

					exit(0);

				}

				for(i=0; i<n; i++)

				{

					fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

				}

				fclose (fp);

				printf("????\n");

			}

			return;

		}

	}

	printf("????????????????????????????\n");

}

/* ????????????????? */

void Delete_data(STU stu[],int &n)

{

	int number,i,j;

	printf("???????????:");

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
			
			stu[n-1]= {0};//???????? stu[n-1]= {0}; ??????????????????????????0????????0?n-2?stu?????0

			n--;
			
			FILE *fp;

			if((fp=fopen("student.txt","w"))==NULL)

			{

				printf("?????\n");
		
				exit(0);

			}

			for(i=0; i<n; i++)

			{

				if(stu[i].num==stu[j].num) continue;

				fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			}
			
				if(j!=n) fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[j].num,stu[j].name,stu[j].score[0],stu[j].score[1],stu[j].score[2]);

			fclose (fp);

			printf("????\n");

			return;

		}
		
		}

	printf("????????????????????????????\n");

}

/* ????????????????? */

void Delete_data1(STU stu[],int &n)

{

	char named[30];

	int i,j;

	printf("???????????:");

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
			
			stu[n-1]= {0};//???????? stu[n-1]= {0}; ??????????????????????????0????????0?n-2?stu?????0
			
			n--;
			
			FILE *fp;

			if((fp=fopen("student.txt","w"))==NULL)

			{

				printf("?????\n");
		
				exit(0);

			}

			for(i=0; i<n; i++)

			{

				if(strcmp(stu[i].name,stu[j].name)==0) continue;

				fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			}
			
				if(j!=n) fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[j].num,stu[j].name,stu[j].score[0],stu[j].score[1],stu[j].score[2]);
			
			fclose (fp);

			printf("????\n");

			return;

		}

	}

	printf("????????????????????????????\n");

}

/* ??????????????????? */

void Count_data(STU stu[],int n)

{

	int i,t=0,low,high;

	float passrate;

	printf("?????????");

	scanf("%d",&low);

	printf("?????????");

	scanf("%d",&high);

	for(int j=0; j<3; j++) {

		for(i=0; i<n; i++)

		{

			if(low<=stu[i].score[j] && stu[i].score[j]<=high) t++;

		}

		if(j==0) {

			printf("???????????????:%d\n",t);

			printf("?????????????????:%.2f\n",(float)t/n);

			t=0;

		}

		if(j==1) {

			printf("???????????????:%d\n",t);

			printf("?????????????????:%.2f\n",(float)t/n);

			t=0;

		}

		if(j==2) {

			printf("???????????????:%d\n",t);

			printf("?????????????????:%.2f\n",(float)t/n);

			t=0;

		}

	}

}

/* ??????????????? */

void Score_data(STU stu[],int n)

{

	int i,j,low,high,t;

	printf("?????????");

	scanf("%d",&low);

	printf("?????????");

	scanf("%d",&high);

	for(int j=0; j<3; j++)

	{
		for(i=0; i<n; i++)

		{

			if(low<=stu[i].score[j] && stu[i].score[j]<=high)

			{

				t++;

				if(j==0)

					printf("??:%d\t??:%s\t????:%d\n",stu[i].num,stu[i].name,stu[i].score[j]);

				if(j==1)

					printf("??:%d\t??:%s\t????:%d\n",stu[i].num,stu[i].name,stu[i].score[j]);

				if(j==2)

					printf("??:%d\t??:%s\t????:%d\n",stu[i].num,stu[i].name,stu[i].score[j]);

			}

		}

	}

}
