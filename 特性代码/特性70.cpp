#include<iostream>
using namespace std;
class a {
	public:
		void GetValue() {
			cout<<k<<endl;
		}
	private:
		int k;
};
class b {
	public:
		int i;
		void setJ(int _j) {
			j = _j;
		};
		int getJ() const {
			return j;
		};
	private:
		int j;
};
int main() {
	a x;
	a *p=&x;
	*((int *)p)=100;
	cout<<&x<<endl;
	x.GetValue();//ʵ��ԭ�������ַ���ǵ�һ����Ա�����ĵ�ַ
	//C++�����������ݺͳ���ηֿ������е�������ᰴ������˳�����δ������ݶΣ����ԣ����֪���˵�һ�������ĵ�ַ����ô����ĵ�ַҲ�������ۼ� ������һ����ˡ����˱�����ַ����ôҲ�Ϳ��Զ�����ֵ�����޸���
	b c;
	c.setJ(2);
	printf("�޸�ǰj��ֵ��%d\n",c.getJ());//��ӡ�޸�ǰj��ֵ
	int *P = (int *)((int*)(&c)+sizeof(c.i));
	*P = 10;
	printf("�޸ĺ�j��ֵ��%d\n",c.getJ()); //��ӡ�޸ĺ�j��ֵ
	return 0;
}

