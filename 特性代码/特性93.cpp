class base{};
class derived://private base{}; //private��protected�ͼ̳����ڷ������ޣ������޷������ͼ���ת������ʵʩ�����ൽ�������ൽ�������ת��
//virtual public base{};  //��������޷�ͨ��static_cast����ת��Ϊ�������ָ�루��Ϊ��̳��µĶ����ڴ沼�ֺͷ���̳в�ͬ���ڴ�ֲ����������ģ����������л��ж����ָ��������ָ��
public base{};
base *pb = new derived();
derived *pd = static_cast<derived *>(pd);
derived d;
base &rb = d;
derived &rd = static_cast<derived &>(rb);
base b;
derived d2=static_cast<derived &>(b);
int main(){}
