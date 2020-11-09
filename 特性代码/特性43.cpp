#include <stdio.h>





int main()


{


    FILE *testFile = NULL;


    int ret = 0;


    char string[200] = {'\0'};





    testFile=fopen("test1.txt", "rb+"); //test1.txt的内容是abcdefghijklmnopqrstuvwxyz


    if(testFile == NULL)


    {


        return 0;


    }


    ret = fread(string, 1, 10, testFile);


    //ret = fseek(testFile, 0, SEEK_CUR);


    ret = fwrite("hello world", 1, 11, testFile);


    fclose(testFile); //test1.txt的内容还是abcdefghijklmnopqrstuvwxyz


    //如果fread和fwrite之间调用了fseek，文件内容变成abcdefghijhello worldvwxyz





    testFile=fopen("test2.txt", "rb+"); //test2.txt的内容也是abcdefghijklmnopqrstuvwxyz


    if(testFile == NULL)


    {


        return 0;


    }


    ret = fwrite("hello world", 1, 11, testFile);


    //ret = fseek(testFile, 0, SEEK_CUR);


    ret = fread(string, 1, 10, testFile);


    fclose(testFile); //test2.txt的内容变成hello world??????????vwxyz


    //如果fread和fwrite之间调用了fseek，文件内容变成hello worldlmnopqrstuvwxyz





    return 0;

/*因为读写内容用的是同一块缓存，且建立缓存时，这个缓存里的数据是未初始化的4096字节。所以读取之后再写入要重置缓存，写入之后再读取也要重置缓存。否则两种操作会导致缓存里的数据错乱。（比如写入流接上了读取流）



flush(fflush)函数，在写入数据的时候，会做如下判断(fflush函数又会根据条件系统调用_write函数，进行文件的写操作，且除了写入文件外，它还把文件缓存的当前位置重新设置到文件缓存的起始位置了)：

1.判断flush之前的操作只有写操作

2.判断缓存的大小 

3.判断缓存中是否有数据没有写入 

(注意在fclose和fseek函数中也会调用fflush函数)*/ 
 
}

