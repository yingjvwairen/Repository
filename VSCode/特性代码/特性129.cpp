#include <iostream>
using namespace std;
class CA
{
    int k;

public:
    void f() { cout << "CA::f" << endl; }
};
class CB : public CA
{
};
class CC : public CA
{
};
class CD : public CB, public CC
{
}; //��C++�У����ؼ̳��ǲ��Ƽ��ģ���һ���뿪�˶��ؼ̳У�����̳о���ȫʧȥ�˴��ڵı�Ҫ����Ϊ����ֻ�ή��Ч�ʺ�ռ�ø���Ŀռ�
int main()
{
    CD d;
    //d.f();//request for member 'f' is ambiguous
}
/*
fֻ������һ����Ϊʲô�޷�ȷ����
�ڶ��ؼ̳��£��������̳еĳ�Ա���Ǵӻ����б��������еĳ�Ա�̳ж�����
��Ϊ���������뵽���������ô�ʱ��Ҫȷ�������ú����Ķ���
����CD::fʱ������f����CA�б�����ģ�CB��CC�ڼ̳�fʱ�ͻ�̳�CA�е�f���壬���ڱ��������﷨��������CB::f��CC::f��ʶ��Ϊ���
��������CD::f��ʱ�����ڱ�CD�̳еĻ���CB��CC������CA�̳�����һ������f����ʱ��CD����ͼ�̳�������f����͵��±�ʶCD::f����ȷ��
�����ǲ�ʹ��CD::f��ʱ�����ϱ�ʶ�����ᱻ���ɡ����ԣ����ȥ��d.f()һ�䣬��һ�α��벻���д�
Ҫ���������⣬����������������
1����д����f()��
��ʱ����������ȷ������CD::f����������鵽CD::f()����ʱ��������������һ��ȥ������CD::f��ʶ��
��ʱCD��Ԫ�ؽṹ���£�
|CB(CA)|
|CC(CA)|
�ʴ�ʱ��sizeof(CD) = 8;��CB��CC����һ��Ԫ��k��
2��ʹ������̳У�
����̳��ֳ�������̳У����ֹ�����ʵҲ�Ǳ����ڼ�ʵ�ֵ�
class CA
{
int k;
public:
void f() {cout << "CA::f" << endl;}
};
class CB : virtual public CA //Ҳ��д����public virtual CA
{ 
};
class CC : virtual public CA
{
};
class CD : public CB, public CC
{
};
int main()
{
CD d;
d.f();
}
��ʱ����������ȷ��d.f()���õľ��庬��ʱ�����������µ�CD�ṹ��
|CB|
|CC|
|CA|
ͬʱ����CB��CC�ж��ֱ������һ��ָ��CA�������ָ���б�vbptr��virtual base table pointer���������ָ�룩
���м�¼���Ǵ�CB��CC��vbtable���׵�ַ��vbptr����CA��Ԫ��֮���ƫ��������ʱ���������ɸ�����ĺ���f��ʶ������������д�˸ú������Ӷ��ﵽ�����Ŀ��
VS2010�У���Project Properties->C++->Command Line->Additional Options�������/d1reportSingleClassLayoutX�����Բ鿴��X�Ķ��󲼾�
Ҳ����ˣ���ʱ��sizeof(CD) = 12��vbptrCB + vbptrCC + sizeof(int)����32λ����ָ��ռ4���ֽڣ�
��ע��
���CB��CC�и�����һ��int�ͱ�������sizeof(CD)�ͱ��20(����vbptr + 3��sizeof(int)
���CA�����һ��virtual void f1(){}��sizeof(CD) = 16��vfptrCA +vbptrCB + vbptrCC + sizeof(int)��;
�����virtual void f2(){}��sizeof(CD) = 16���䡣ԭ�򣺴����麯�����࣬���ڴ沼����ֻ�ð���һ��ָ���麯���б��ָ�루vfptr�����麯����ָ�룩
*/