#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;
/*
�������
l1:�Ը�����ĸ��y��β����y���i���ټ�es;
l2:��s��x��ch��sh��β����es;
l3:��Ԫ��o��β����es;
l4:�������ͳͳֻ��s; 
*/
string Plurals(string str)
{
	string ans = str;
	int len = str.size();
	if ((str[len - 2] != 'a') && (str[len - 2] != 'e') && (str[len - 2] != 'i') && (str[len - 2] != 'o') && (str[len - 2] != 'u') && (str[len - 1] == 'y'))
		str[len - 1] = 'i',ans = str + "es";
	else if ((str[len - 1] == 'o') || (str[len - 1] == 's') || (str[len - 1] == 'x'))
		ans = str + "es";
	else if (str[len - 1] == 'h')
		if ((str[len - 2] == 'c') || (str[len -2] == 's'))
			ans = str + "es";
		else
			ans = str + "s";
	return ans;
}
int main()
{		
	string str;
	while (cin >> str)//ÿѭ��һ�ξ���Ҫ����һ�����ݳ���Ż����ִ�У��粻�������ݳ���ͻ�������cin�����Ķϵ㴦ֹͣ���������������
						//���仰��˵�������ֻ�����ϵ��ѭ���ж�����ʹ�ó��򲻻�ֹͣ���ж�������ֹ���ڸ��������ϵ�ʹ�ô�ѭ�����޵�ѭ����ȥ 
    		cout << Plurals(str) << '\n';//��Դ�ļ����������֮�����䶼����ִ�� 
    		cout << str << endl; 
	return 0;
} 

