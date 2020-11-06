#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	cout << fclose(fopen("f.txt","w")) << endl;
	if(!fclose(fopen("f.txt","w")))
	cout << fopen("f.txt","w");
	exit(0);
}

