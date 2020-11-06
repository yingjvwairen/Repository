#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    cout << "Type a line terminated by 't' " << endl;
    getline(cin, line, 't');
    cout << line << endl;
    cin.clear();//仅有此语句，输入缓存中数据的清理并不完全，应在后面再加上 cin.sync(); 或换成 fflush(stdin); 都行
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
