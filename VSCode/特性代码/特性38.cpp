#include<stdio.h>
int main()
{
	char ch,str1[110],str2[110];
	scanf("%s",str1);
	scanf("%s",str2);
	FILE* pfr = fopen(str1, "r");	
	FILE* pfw = fopen(str2, "r");
		if (NULL == pfr)
			{
			perror("open file failed");//显示出编译器展现的错误信息 
				return EOF;
			}
		if (NULL != pfw)
		{
			printf("是否覆盖？");
			char c[3],d[3]="是";//定义字符串时空间需多给\0字符留一个，但是要注意，不同的编码方式下存储同一个汉字所需的字节数是不同的 
			getchar();//作用是防止回车键被下一条输入语句所捕捉，也可以用清空缓冲区（指输入流 相关的语句来实现 
			gets(c);//上一条输入语句中输入的回车键容易被此语句所捕捉，所以注意在之前进行与清空回车键相关的操作 
			if(*c==*d)//要注意这里只是取了字符数组中首字符所占空间中存储的数值来比较而已，而汉字是占两个字符大小的，即汉字其实是字符串（两个字符 
			//注意不能c==d，因为这就变成了两个指针数值的比较了,但在内存空间中存放的位置不同地址就不会相同，可以用printf("%d\n%d",c,d);来验证 
			//所以注意比较字符串的值时不应用首地址来比较，而是应该取值比较 
			{
				fclose(pfw);//重新打开文件时，需关闭pfw所指向的文件，因为重复使用fopen()操作一个文件时只有第一次fopen()会生效 
				pfw = fopen(str2, "w");//这两条语句也可以用reopen()函数来替换掉 
			}
			else
				return NULL;
		}
		if (NULL == pfw)
			perror("open file failed");//输出编译器显示的错误信息	
		while ((ch=fgetc(pfr))!=EOF)//EOF是文件结束标志，位于文件末尾，值为-1	
			fputc(ch,pfw);//不断的从源文件中读取字符并写入目的文件中，直到遇到EOF结束这个过程
			fclose(pfr);	
			fclose(pfw);//关闭流，使用完流后记得关闭，避免占用资源	
			pfr = NULL;//fclose()时指针并不会被释放
			pfw = NULL;//将未被释放的指针置空	
			return 0; 
}

