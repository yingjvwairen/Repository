#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
using namespace std;
class String {
	private:
		static int times;
	public:
		String():Str(NULL) {}
		vector<char>Str;
		friend ostream& operator << (ostream& os, String& p1) {
			int i = 0;
			for (int i = 0; i < p1.Str.size(); i++)os << p1.Str[i];
			cout<<endl;
			return os;
		}
		friend istream& operator>>(istream& is, String& p2) {
			char str;
			int i = 0;
			while (1) {
				str = getchar();
				p2.Str.push_back(str);
				if (str == ' ' || str == '\r' || str == '\n')break;
				else i++;
			}
			return is;
		}
		void extract(ifstream &ifs) {
			char symble;
			String str;
			vector<String> p;
			while (ifs.get(symble)) {
				if (symble != ' ' && symble != ',' && symble != '\n' && symble != '\r' && symble != '\0' && symble != '.' && symble != '"' && symble != '(' && symble != ')' && symble != '[' && symble != ']' &&  (symble < 48 || symble > 57)) {
					str.Str.push_back(symble);
				} else {
					p.push_back(str);
					str.Str.clear();
				}
			}
			for (int i = 0; i < p.size() ; i++) {
				auto itr = p[i].Str.begin();
				if(itr != p[i].Str.end() )cout << "times:" << p[i].times << "   " << p[i];
			}
		}
		void wordtimes(ifstream& ifs);
};
int main() {
	ifstream ifs;
	ifs.open("C:/Users/q2423/Desktop/E11.txt");
	String p;
	p.extract(ifs);
	ifs.close();
	getchar();
}

