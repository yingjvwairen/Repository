#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void) {
	char file[80];
	printf("׼��ɾ�����ļ������룺\n");
	char s[1024];
	gets(s);
	int err = remove(s);
//remove()��C�����еĺ�����һ��������ɾ�����顢����������е�Ԫ�أ�Ҳ��������ɾ��ָ�����ļ�������ԭ����int remove��char*filename��
//filenameΪҪɾ�����ļ���������ΪһĿ¼���������filename Ϊһ�ļ��������unlink()����������filename ΪһĿ¼�������rmdir()������
//�ɹ��򷵻�0��ʧ���򷵻�-1������ԭ�����errno
	if( err < 0 ) {
		printf("%s\n",strerror(errno));
	}
	return 0;
}
/*����������
EROFS ��д����ļ�Ϊֻ���ļ�
EFAULT ����filename ָ�볬���ɴ�ȡ�ڴ�ռ�
ENAMETOOLONG ����filename ̫��
ENOMEM �����ڴ治��
ELOOP ����filename �й��������������
EIO I/O ��ȡ����
*/
