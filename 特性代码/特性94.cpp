class base{};
class base2{};
class derived:public base,base2{};//base2Ϊprivate
derived *pd = new derived();
void *pv = pd;	//��derivedָ��ת��Ϊvoidָ��
base2 *pb = static_cast<base2 *>(pv);//ת����pb��pd����ͬ�ĵ�ַ����������ת����Ӧ��һ��ƫ��������voidָ������ת���������Թ������ã�Ӧ��������������
derived d;
base2 b;
//base2 b=static_cast<base2 >(d);   //derived�е�base2Ϊprivate�����������޷�ת��
//derived d=static_cast<derived >(b);  //ת��ԭ���ͺ�Ŀ������ֻ����ָ������ã���derived�е�base2Ϊprivate�����������޷�ת��
int main(){}