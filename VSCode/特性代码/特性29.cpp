#include<iostream>
using namespace std;
int main()
{
    FILE *fp;
    fp = fopen("C:\\nosuchfile.sys","r");//��һ�������ڵ��ļ�
    printf("fp = 0x%X\n",fp);
    if (fp == NULL)
    {
        printf("Open file failed.\n");
    }
    else
    {
        printf("Open file succeed.\n");
    }
    fclose(fp);//���ｫ�����쳣
}

