#include <iostream>
#include <cstdio>
using namespace std;
int main()
{	
//�����ǹ��ڶ������ʱconst�����εı����ķ��� 
	const type a,b;// a �� b�ǲ��й�ϵ ��constλ������֮ǰ����const���� a �� b  
 	type const a,b;// a �� b�ǲ��й�ϵ ��constλ������֮ǰ����const���� a �� b 
 	type * const a, * b;// * a �� * b�ǲ��й�ϵ ��constλ��a֮ǰ����const������ a
 	type * const a,b;//  * a �� b�ǲ��й�ϵ ��constλ��a֮ǰ����constֻ���� a  
 	const type * a,b;// * a �� b�ǲ��й�ϵ ��const���� * a �� b 
//���ϣ�const�ھ��в��й�ϵ�Ķ������ǰʱ�������δ��в��й�ϵ�����б��� (��Ȼ��֪����Ҫע����ǣ�ָ������޷����� 
}
