#include <iostream>
#pragma comment(linker,"/Entry:doublemain::main")
#define Conn(x,y) x##y
using namespace std;
namespace doublemain{
    void main(){
        cout << "extra main";
    }
}
int main()
{
int  n = Conn(123,456);
char* str = "Conn(asdf,adf)";
char* s = "Conn(asdf,adf)";
cout << n << str;
}
