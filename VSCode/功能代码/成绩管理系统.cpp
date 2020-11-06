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

			printf("\t\t\t* 感谢使用 * \n");

			printf("\t\t\t* 学生试卷分数统计系统 * \n");

			printf("\t\t********************************************\n");

			exit(0);

		}

		printf("请输入学生总人数n(n<=%d):", SIZE);

		scanf("%d", &n);

		switch (ch)

		{

			case 1:

				printf("以下有两种输入试卷分数的方式：\n***1.手动输入试卷分数(会追加写入student.txt中,没有就创建)\t2.从student.txt文件中导入试卷分数***\n");

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

						printf("输入菜单序号错误!");

						system("pause");

						break;

				}

				break;

			case 2:

				printf("以下有两种查找学生的方式：\n***1.按学号查找\t2.按名字查找***\n");

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

						printf("输入菜单序号错误!");

						system("pause");

						break;

				}

				break;

			case 3:

				printf("以下有两种查找学生的方式：\n***1.按学号查找\t2.按名字查找***\n");

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

						printf("输入菜单序号错误!");

						system("pause");

						break;

				}

				break;

			case 4:

				printf("以下有两种查找学生的方式：\n***1.按学号查找\t2.按名字查找***\n");

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

						printf("输入菜单序号错误!");

						system("pause");

						break;

				}

				break;

			case 5:

				printf("按成绩段:\n***1.输出学生人数及其百分比\t2.输出这些学生的信息***\n");

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

						printf("输入菜单序号错误!");

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

				printf("输入菜单序号错误!");

				system("pause");

				break;

		}

	}

	return 0;

}

/* 函数功能：显示菜单并获得用户键盘输入的选项 */

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

	cout<<setw(46)<<"欢迎进入学生管理系统"<<endl;

	cout<<'\n';

	cout<<setw(20);

	for(int i=0; i<30; i++) {
		cout<<' ';
	}

	cout<<endl;

	int itemSelected;

	cout<<setw(46)<<"\t【菜单】\n";

	cout<<setw(46)<<"\t1.录入成绩\n";

	cout<<setw(46)<<"\t2.修改成绩\n";

	cout<<setw(46)<<"\t3.删除成绩\n";

	cout<<setw(46)<<"\t4.查询学生成绩\n";

	cout<<setw(46)<<"\t5.查询成绩段\n";

	cout<<setw(46)<<"\t6.计算学生及格率和优秀率\n";

	cout<<setw(46)<<"\t7.计算学生平均分和标准差\n";

	cout<<setw(46)<<"\t8.成绩列表\n";

	cout<<setw(46)<<"\t9.导出文件(注意每次导入都会刷新此文件)\n";

	cout<<setw(46)<<"\t0.退出\n";

	cout<<setw(41)<<"\t请输入你的选择:";

	cout<<setw(20);

	scanf("%d", &itemSelected); /* 读入用户输入 */

	system("cls");

	return itemSelected;

}

/* 函数功能：手动输入分数 */

void Read_data(STU stu[],int n)

{

	int i=0,j,t;

	FILE *fp;

	if((fp=fopen("student.txt","r"))!=NULL)

	{

		printf("请注意student.txt中的学生人数不得超过%d人\n",SIZE);
		
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

			i--;//注意这里须自减，因为feof函数事实上在读到文件末尾时还会继续读一次空字符后才会返回非零值，原因如下：  
			
			/*
			使用feof函数作为判断文件是否结束时需要特别注意的地方：
			在读取到换行符时，feof函数会认为此文件还未结束。
			所以如果试图用feof函数作为循环体的判断条件的话，当用fread或fscanf等函数对文件进行的读取操作结束时，feof函数会读取到文件末尾的换行符或空格或/t字符（如果有的话），
			会认为此文件还未结束，于是会继续进行下一次循环，
			导致多进行了一次循环，多读取出了一些空字符
			*/

				//所以也可看出成绩列表中应用换行符结尾 

	}

	printf("由于student.txt中学生人数为%d，所以学生总人数n>%d时会录入出错\n请输入学生的学号、姓名、数学成绩、英语成绩和计导成绩(用空格隔开，且除了姓名外须输入纯数字，否则会出错)\n",i,SIZE-i);

	for(t=i; t<n+i; t++)

	{

		scanf("%d %s %d %d %d",&stu[t].num,&stu[t].name,&stu[t].score[0],&stu[t].score[1],&stu[t].score[2]);

		j=0;

		while(j!=t) {

			if(stu[j].num==stu[t].num) {

				printf("学号重复,请重新输入！\n");

				t--;

				break;
			}

			j++;

		}

	}

	if((fp=fopen("student.txt","a"))==NULL)

	{

		printf("录入文件student.txt失败！\n");

		exit(0);

	}

	for(t=i; t<n+i; t++)

	{

		fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[t].num,stu[t].name,stu[t].score[0],stu[t].score[1],stu[t].score[2]);

	}

	fclose(fp);

	printf("已录入\n");

}

/* 函数功能：从文本student.txt中导入试卷分数 */

void Read_data1(STU stu[],int &n)

{

	int i,j;

	FILE *fp;

	if((fp=fopen("student.txt","r"))==NULL)

	{

		printf("打开文件student.txt失败！\n");

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


/* 函数功能：按学号查询学生试卷的成绩 */

void Sortbynum(STU stu[],int n)

{

	int number,i;

	printf("请输入要查找的学生学号:");

	scanf("%d",&number);

	for(i=0; i<n; i++)

	{

		if(stu[i].num==number)

		{

			printf("学号:%d\t姓名:%s\t数学成绩:%d\t英语成绩:%d\t计导成绩:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			return;

		}

	}

	printf("抱歉,没有找到,可以将文件末尾的换行符或空格去掉再试试！\n");

}

/* 函数功能：按姓名查询学生试卷的成绩 */

void Sortbyname(STU stu[],int n)

{

	char named[10];

	int i;

	printf("请输入要查找的学生姓名：");

	scanf("%s",named);

	for(i=0; i<n; i++)

	{

		if(strcmp(named,stu[i].name)==0)

		{

			printf("学号:%d\t姓名:%s\t数学成绩：%d\t英语成绩：%d\t计导成绩:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			return;

		}

	}

	printf("抱歉,没有找到,可以将文件末尾的换行符或空格去掉再试试！\n");

}

/* 函数功能：计算全班学生成绩的及格率和优秀率，并按优良中差输出学生人数 */

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

			printf("数学及格人数:%d\n",pass_num);

			printf("优:%d\t良:%d\t中:%d\t差:%d\n",t[3],t[2],t[1],t[0]);

			printf("数学成绩及格率:%.2f\n",passrate);

			printf("数学成绩优秀率:%.2f\n",(float)t[3]/n);

			t[0]=0,t[1]=0,t[2]=0,t[3]=0;

		}

		if(j==1) {

			printf("英语及格人数:%d\n",pass_num);

			printf("优:%d\t良:%d\t中:%d\t差:%d\n",t[3],t[2],t[1],t[0]);

			printf("英语成绩及格率:%.2f\n",passrate);

			printf("英语成绩优秀率:%.2f\n",(float)t[3]/n);

			t[0]=0,t[1]=0,t[2]=0,t[3]=0;

		}

		if(j==2) {

			printf("计导及格人数:%d\n",pass_num);

			printf("优:%d\t良:%d\t中:%d\t差:%d\n",t[3],t[2],t[1],t[0]);

			printf("计导成绩及格率:%.2f\n",passrate);

			printf("计导成绩优秀率:%.2f\n",(float)t[3]/n);

			t[0]=0,t[1]=0,t[2]=0,t[3]=0;

		}

	}

}

/* 函数功能：计算学生成绩的平均分和标准差 */

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

			printf("数学成绩平均分:%.2f\t计导成绩标准差:%.2lf\n",aver,standard);

		}

		if(j==1)

		{

			printf("英语成绩平均分:%.2f\t计导成绩标准差:%.2lf\n",aver,standard);

		}

		if(j==2)

		{

			printf("计导成绩平均分:%.2f\t计导成绩标准差:%.2lf\n",aver,standard);

		}
		
		sum=0;

	}

}

/* 函数功能：输出全班学生的所有成绩 */

void Show_data(STU stu[],int n)

{

	int i;

	for(i=0; i<n; i++)

	{

		printf("学号:%d\t姓名:%s\t数学成绩:%d\t英语成绩:%d\t计导成绩:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

	}

}

/* 函数功能：将学生所有成绩的列表导出到文本score.txt中 */

void Write_data(STU stu[],int n)

{

	FILE *fp;

	int i;

	if((fp=fopen("score.txt","w"))==NULL)

	{

		printf("打开文件失败！\n");

		exit(0);

	}

	fprintf(fp,"以下各项分别对应学号、姓名、数学成绩、英语成绩和计导成绩:\n");

	for(i=0; i<n; i++)

	{

		fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

	}

	fclose (fp);

	printf("已导出\n");

}

/* 函数功能：按学号查找更改学生的成绩 */

void Change_data(STU stu[],int n)

{

	int number,i;

	printf("请输入要查找的学生学号:");

	scanf("%d",&number);

	for(i=0; i<n; i++)

	{

		if(stu[i].num==number)

		{

			printf("学号:%d\t姓名:%s\t数学成绩:%d\t英语成绩:%d\t计导成绩:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			printf("请输入需要更改的科目序号\n(数学为0,英语为1,计导为2)\n");

			int j;

			scanf("%d",&j);

			if(j!=0 && j!=1 && j!=2)

			{

				printf("输入序号有误");

			}

			else

			{

				int new_score;

				printf("请输入更改后的成绩");

				scanf("%d",&new_score);

				stu[i].score[j]=new_score;

				FILE *fp;

				if((fp=fopen("student.txt","w"))==NULL)

				{

					printf("更改失败！\n");

					exit(0);

				}

				for(i=0; i<n; i++)

				{

					fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

				}

				fclose (fp);

				printf("更改成功\n");

			}

			return;

		}

	}

	printf("抱歉,没有找到,可以将文件末尾的换行符或空格去掉再试试！\n");

}

/* 函数功能：按名字查找更改学生的成绩 */

void Change_data1(STU stu[],int n)

{

	char named[10];

	int i;

	printf("请输入要查找的学生姓名：");

	scanf("%s",named);

	for(i=0; i<n; i++)

	{

		if(strcmp(named,stu[i].name)==0)

		{

			printf("学号:%d\t姓名:%s\t数学成绩：%d\t英语成绩：%d\t计导成绩:%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			printf("请输入需要更改的科目序号\n(数学为0,英语为1,计导为2)\n");

			int j;

			scanf("%d",&j);

			if(j!=0 && j!=1 && j!=2)

			{

				printf("输入序号有误");

			}

			else

			{

				int new_score;

				printf("请输入更改后的成绩");

				scanf("%d",&new_score);

				stu[i].score[j]=new_score;

				FILE *fp;

				if((fp=fopen("student.txt","w"))==NULL)

				{

					printf("更改失败！\n");

					exit(0);

				}

				for(i=0; i<n; i++)

				{

					fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

				}

				fclose (fp);

				printf("更改成功\n");

			}

			return;

		}

	}

	printf("抱歉,没有找到,可以将文件末尾的换行符或空格去掉再试试！\n");

}

/* 函数功能：按学号查找删除学生的成绩 */

void Delete_data(STU stu[],int &n)

{

	int number,i,j;

	printf("请输入要查找的学生学号:");

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

				printf("删除失败！\n");
		
				exit(0);

			}

			for(i=0; i<n; i++)

			{

				if(stu[i].num==stu[j].num) continue;

				fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			}
			
				if(j!=n) fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[j].num,stu[j].name,stu[j].score[0],stu[j].score[1],stu[j].score[2]);

			fclose (fp);

			printf("删除成功\n");

			return;

		}
		
		}

	printf("抱歉,没有找到,可以将文件末尾的换行符或空格去掉再试试！\n");

}

/* 函数功能：按名字查找删除学生的成绩 */

void Delete_data1(STU stu[],int &n)

{

	char named[30];

	int i,j;

	printf("请输入要查找的学生姓名:");

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

				printf("删除失败！\n");
		
				exit(0);

			}

			for(i=0; i<n; i++)

			{

				if(strcmp(stu[i].name,stu[j].name)==0) continue;

				fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);

			}
			
				if(j!=n) fprintf(fp,"%d\t%s\t%d\t%d\t%d\n",stu[j].num,stu[j].name,stu[j].score[0],stu[j].score[1],stu[j].score[2]);
			
			fclose (fp);

			printf("删除成功\n");

			return;

		}

	}

	printf("抱歉,没有找到,可以将文件末尾的换行符或空格去掉再试试！\n");

}

/* 函数功能：按成绩段输出学生人数和百分比 */

void Count_data(STU stu[],int n)

{

	int i,t=0,low,high;

	float passrate;

	printf("请输入成绩段最低值");

	scanf("%d",&low);

	printf("请输入成绩段最高值");

	scanf("%d",&high);

	for(int j=0; j<3; j++) {

		for(i=0; i<n; i++)

		{

			if(low<=stu[i].score[j] && stu[i].score[j]<=high) t++;

		}

		if(j==0) {

			printf("数学成绩里处于此成绩段中的人数:%d\n",t);

			printf("数学成绩里处于此成绩段中的人数占比:%.2f\n",(float)t/n);

			t=0;

		}

		if(j==1) {

			printf("英语成绩里处于此成绩段中的人数:%d\n",t);

			printf("英语成绩里处于此成绩段中的人数占比:%.2f\n",(float)t/n);

			t=0;

		}

		if(j==2) {

			printf("计导成绩里处于此成绩段中的人数:%d\n",t);

			printf("计导成绩里处于此成绩段中的人数占比:%.2f\n",(float)t/n);

			t=0;

		}

	}

}

/* 函数功能：按成绩段输出学生信息 */

void Score_data(STU stu[],int n)

{

	int i,j,low,high,t;

	printf("请输入成绩段最低值");

	scanf("%d",&low);

	printf("请输入成绩段最高值");

	scanf("%d",&high);

	for(int j=0; j<3; j++)

	{
		for(i=0; i<n; i++)

		{

			if(low<=stu[i].score[j] && stu[i].score[j]<=high)

			{

				t++;

				if(j==0)

					printf("学号:%d\t姓名:%s\t数学成绩:%d\n",stu[i].num,stu[i].name,stu[i].score[j]);

				if(j==1)

					printf("学号:%d\t姓名:%s\t英语成绩:%d\n",stu[i].num,stu[i].name,stu[i].score[j]);

				if(j==2)

					printf("学号:%d\t姓名:%s\t计导成绩:%d\n",stu[i].num,stu[i].name,stu[i].score[j]);

			}

		}

	}

}
