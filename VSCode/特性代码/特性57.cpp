#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void) {
	char file[80];
	printf("准备删除的文件名输入：\n");
	char s[1024];
	gets(s);
	int err = remove(s);
//remove()是C语言中的函数，一般作用是删除数组、链表对象所有的元素，也可以用来删除指定的文件，函数原型是int remove（char*filename）
//filename为要删除的文件名，可以为一目录。如果参数filename 为一文件，则调用unlink()处理；若参数filename 为一目录，则调用rmdir()来处理
//成功则返回0，失败则返回-1，错误原因存于errno
	if( err < 0 ) {
		printf("%s\n",strerror(errno));
	}
	return 0;
}
/*函数错误码
EROFS 欲写入的文件为只读文件
EFAULT 参数filename 指针超出可存取内存空间
ENAMETOOLONG 参数filename 太长
ENOMEM 核心内存不足
ELOOP 参数filename 有过多符号连接问题
EIO I/O 存取错误
*/
