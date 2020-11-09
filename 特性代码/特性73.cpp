#include<iostream>
#include<cstring>
#include<fstream>
#include<ctype.h>
#include<stdlib.h>
using namespace std;
typedef unsigned char BYTE;
inline BYTE toHex(const BYTE &x) {
	return x > 9 ? x + 55 : x + 48;
}
string urlEncoding(string &sIn) {
	cout << "size:" << sIn.size() << endl;
	string sOut;
	for (int ix = 0; ix < sIn.size(); ix++)	{
		BYTE buf[4];
		memset(buf, 0, 4);
		if (isalnum((BYTE)sIn[ix]))	{
			buf[0] = sIn[ix];
		}		else if (isspace((BYTE)sIn[ix])){
			buf[0] = '+';
		}		else		{
			buf[0] = '%';
			buf[1] = toHex((BYTE)sIn[ix] >> 4);
			buf[2] = toHex((BYTE)sIn[ix] % 16);
		}
		sOut += (char *)buf;
	}
	return sOut;
}
int main(int argc, char *argv[]) {
	string src;
	cout << "Please input characters." << endl;
	cin >> src;
	string sOut = urlEncoding(src);
	cout << sOut << endl;

	char*p="Èö¿­Èö";
	string sp="Èö¿­Èö";
	string s1=p;
	string&s2=sp;
	string s3=sp;
}

