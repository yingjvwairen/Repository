#include <stdio.h>





int main()


{


    FILE *testFile = NULL;


    int ret = 0;


    char string[200] = {'\0'};





    testFile=fopen("test1.txt", "rb+"); //test1.txt��������abcdefghijklmnopqrstuvwxyz


    if(testFile == NULL)


    {


        return 0;


    }


    ret = fread(string, 1, 10, testFile);


    //ret = fseek(testFile, 0, SEEK_CUR);


    ret = fwrite("hello world", 1, 11, testFile);


    fclose(testFile); //test1.txt�����ݻ���abcdefghijklmnopqrstuvwxyz


    //���fread��fwrite֮�������fseek���ļ����ݱ��abcdefghijhello worldvwxyz





    testFile=fopen("test2.txt", "rb+"); //test2.txt������Ҳ��abcdefghijklmnopqrstuvwxyz


    if(testFile == NULL)


    {


        return 0;


    }


    ret = fwrite("hello world", 1, 11, testFile);


    //ret = fseek(testFile, 0, SEEK_CUR);


    ret = fread(string, 1, 10, testFile);


    fclose(testFile); //test2.txt�����ݱ��hello world??????????vwxyz


    //���fread��fwrite֮�������fseek���ļ����ݱ��hello worldlmnopqrstuvwxyz





    return 0;

/*��Ϊ��д�����õ���ͬһ�黺�棬�ҽ�������ʱ������������������δ��ʼ����4096�ֽڡ����Զ�ȡ֮����д��Ҫ���û��棬д��֮���ٶ�ȡҲҪ���û��档�������ֲ����ᵼ�»���������ݴ��ҡ�������д���������˶�ȡ����



flush(fflush)��������д�����ݵ�ʱ�򣬻��������ж�(fflush�����ֻ��������ϵͳ����_write�����������ļ���д�������ҳ���д���ļ��⣬�������ļ�����ĵ�ǰλ���������õ��ļ��������ʼλ����)��

1.�ж�flush֮ǰ�Ĳ���ֻ��д����

2.�жϻ���Ĵ�С 

3.�жϻ������Ƿ�������û��д�� 

(ע����fclose��fseek������Ҳ�����fflush����)*/ 
 
}

