#include<iostream>
using namespace std;
int main() {
	int j=0;
	for(int i=0; i<10; i++) {
		j=(j++);//j=j++;
	}
	cout << j;
}

