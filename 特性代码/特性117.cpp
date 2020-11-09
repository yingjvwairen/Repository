#include <iostream>
using namespace std;
class A
{
public:
    A(int)
    {
        cout<<"¹¹Ôì\n";
    }
    A(const A&)
    {
        cout<<"¿½±´\n";
    }
};

int main()
{
    A(0);
    cout<<"------------------------\n";
    A(A(0));
    cout<<"------------------------\n";
    A(A(A(0)));
    cout<<"------------------------\n";
    A(A(A(A(0))));
    cout<<"------------------------\n";
    A(A(A(A(A(0)))));
    cout<<"------------------------\n";
    return 0;
}