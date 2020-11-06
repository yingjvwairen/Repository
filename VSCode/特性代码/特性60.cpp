#include<iostream>
using namespace std;
int main()
{
	
	char*a[]={"Tamako","love","story"};
	
	char**s=a;
	
	cout<<"sizeof(a): \t"<<sizeof(a)<<endl;
	
	cout<<"*s: \t\t"<<*s<<endl;
	
	cout<<"*(s+1): \t"<<*(s+1)<<endl;
	
	cout<<"(a[0]+1): \t"<<(a[0]+1)<<endl;
	
	cout<<"a[1]: \t\t"<<a[1]<<endl;
	
	cout<<"*(&a[0]+1): \t"<<*(&a[0]+1)<<endl;
	
	cout<<"sizeof(a[0]): \t"<<sizeof(a[0])<<endl;
	
	cout<<"sizeof(*s): \t"<<sizeof(*s)<<endl;
	
	cout<<"sizeof(s): \t"<<sizeof(s)<<endl;
	
}

