#include <iostream>
using namespace std;
 
struct test{
	size_t m;
        //���Աm������ѡ����size_t���ͣ�������int����
	test(){cout << "construct..." << endl;}  
        //���캯��
	~test(){cout << "destructed." << endl;}   
        //�����������Ժ����ע�͵����������
};
 
void test_free_new(){
	int k = 5; 
        //����ĳ��ȣ��������޸ģ��������
 
	test* tp = new test[k]; 
        //��new����һ����������      
	for(int n=0;n<k;n++) tp[n].m = (n+1)*100; 
        //�Գ�Աm���и�ֵ����(n+1)*100������ʽ�������������������Щ
 
	size_t* sp = reinterpret_cast<size_t*>(tp);
        //����һ��size_tָ�룬����ǿ��ת��
	sp --;
        //�Ƶ��洢�ռ�֮ǰ���ڴ�
	for(int n=0;n<k+1;n++) cout << "sp[" << n << "] is : " << sp[n] << endl; 
        //���������������֮ǰ��һ����Ԫ������
	delete[] tp;
}
 
 
int main() {
	test_free_new();
	return 0;
}