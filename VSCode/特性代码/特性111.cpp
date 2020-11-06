/*
C���Գ�������main������ʼ��

�������ڵ�ַ�ǿ���ָ���ģ�c���Ա�����Ĭ����main��Ϊ��ڵ�ַ

 __attribute__ ����ؼ��֣����������ú������ԣ��������ԣ���������
*/

#include <stdio.h>
//���ֺ�����main()֮ǰִ��
/*
 * This attribute lead gcc/ld to exec this function 
 * before the "main".
 */
extern "C"
{

    __attribute ((__constructor__))   //��main����֮ǰ�����õĺ��� 
  void pre_func(void) {
        printf("pre_func\n");
}
}
int main( int argc, char ** argv )
{
  printf("%s/n",__FUNCTION__);
  return 0;
}
/*
ͬ����main�����˳�֮��ִ�еĺ���
static void stop() __attribute ((destructor));

ֻ��Ҫ��__attribute ((constructor/destructor)) �ؼ������μ���
*/

/*
vc��֧��attribute�ؼ��֣���vc�У�����ʹ�����·�����
#include <stdio.h>
int
main( int argc, char ** argv )
{
        printf("%s\n",__FUNCTION__);
        return 0;
}

int before_main()
{
        printf("%s\n",__FUNCTION__);
        return 0;
}
int after_main()
{
        printf("%s\n",__FUNCTION__);
        return 0;
}
typedef int func();
#pragma data_seg(".CRT$XIU")
static func * before[] = { before_main };
#pragma data_seg(".CRT$XPU")
static func * after[] = { after_main };
#pragma data_seg()

*/

//���ҿ�����mainǰ����ö����������gcc��ʹ��attribute�������constructor��destructor��vc����before��after��������Ӷ������ָ��