#include <iostream>
using namespace std;
#define TRUE false  //true��false�Ǵ�Сд���е�
#define true false
#define true false  //�˾��true�ض��壬��Ϊ��ǰ������ͬ�Ķ��壬���Ա�����ֻ�����һ�ζ���
#define false true  //��ʱ�˾��൱��#undef true����Ϊ�����γ�ѭ�����滻���ԣ��滻ֻ��ѭ��һ��
#define true false+100  //�˾��true�ض��壬���������������һ�ε��ض���
int main()
{
    cout << true << endl;   //true-->false+100-->true+100��ֻ�����һ��ѭ��
    cout << TRUE << endl;   //TRUE-->false-->true-->false+100���γ�һ��ѭ��
    cout << NULL << endl;   //NULLҲ�����ִ�Сд��
    cout << __null << endl; //Ԥ�������ὫNULL�滻Ϊ__null��������������ʵ�ǵȼ۵�
    return 0;
}

