#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    cout << "Type a line terminated by 't' " << endl;
    getline(cin, line, 't');
    cout << line << endl;
    cin.clear();//���д���䣬���뻺�������ݵ���������ȫ��Ӧ�ں����ټ��� cin.sync(); �򻻳� fflush(stdin); ����
    cout << "Type a line terminated by 't' again" << endl;
    char ch;
    string str = "";
    while ((ch = cin.get()) != 't')
    {
        str = str + ch;
    }
    cout << str << endl;
    return 0;
}
