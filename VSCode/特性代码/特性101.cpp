#include<iostream>
using namespace std;
//����do{}while(0)���Ե��÷�

bool Execute()
{

   int *p = new int;

   bool bOk(true);
   //����do{}while(0)��������
   do
   {
      //ִ�в����д�����ʱ���ɽ���ִ�д��������do���{}�У����������ô������ѭ�����������ڣ���ʱ�Ϳ�����break����ѭ�������������������
      bOk = -1;
      if(!bOk) break;

      bOk = 0;
      if(!bOk) break;

      bOk = 1;
      if(!bOk) break;

      // ..........

   }while(0);

    //����ѭ��ṹ���������д���������������ʱ��ִ�еĴ���
    delete p;   
    p = NULL;
    return bOk;
   
}

//#define SAFE_DELETE(p) do{ delete p; p = NULL;} while(0)

//��������ȥ��do...while(0)

#define SAFE_DELETE(p) {delete p; p = NULL;}

int main(){

    int*p=new int;

    //if(NULL != p){};else return 0;//else���������벻��ͨ������Ϊ�����ź�ķֺŴ�����һ������䣬����elseǰ�Ͳ���if�����

    //if(NULL != p)SAFE_DELETE(p);else return 0;//���Դ˾����ͨ��������Ϊ�൱��ִ���������������֮����ִ����һ�������֮�����else���

    /*

����һ����䱻����Ϊ��

    if(NULL != p){
        delete p; 
        p = NULL;
    }
        ;               //�����
    else                //[Error] 'else' without a previous 'if'
        return 0;
   
    */
//���Կ����������;ֱ��λ�ڴ����ĺ��棬�����������Ƕ��do...while(0)����Խ����������

#undef SAFE_DELETE

#define SAFE_DELETE(p) do{ delete p; p = NULL;} while(0)    //ע�����û�зֺ�;

if(NULL != p)SAFE_DELETE(p);else return 0;

/*
�������һ���취������ѭ����淶��

if (NULL != p)
{
    SAFE_DELETE(p);
}
else
{
    return 0;
}

*/
//�����Ͳ���������ˣ�����������д�ĺ��ʹ�ô��������������Ծͼ����ˣ�Ҳ�Ͳ�����ͨ���Ժͽ�׳���ˡ���Ϊ���������жԺ�ʹ���ߵļ����ˣ��������淶������ˮƽ�ȡ� 

}