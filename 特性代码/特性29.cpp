#include<iostream>
using namespace std;
int main()
{
    FILE *fp;
    fp = fopen("C:\\nosuchfile.sys","r");//打开一个不存在的文件
    printf("fp = 0x%X\n",fp);
    if (fp == NULL)
    {
        printf("Open file failed.\n");
    }
    else
    {
        printf("Open file succeed.\n");
    }
    fclose(fp);//这里将引发异常
}

