#include<iostream>
using namespace std; 
int main(){
	cout << "������һ���������������������س���,������"; 
	int array[110]={0},tmp,i,j;
	for(i=1;i<100;++i)
		{
		cin >> array[i];
		if(getchar()=='\n')
		break;
		}
	for(int k=1;k<=i;++k)
		for(j=1;j<=i-k;++j)
			{
			if(array[j]>array[j+1])
			tmp=array[j],array[j]=array[j+1],array[j+1]=tmp;
			}
	for(j=1;j<=i;++j)
		
		cout << array[j] << ' '; 
	cout << "��������Ҫ���ҵ���";
	int key,mid,begin=1,end=i;
	cin >> key;
	while(begin<=end)
	{
		mid=(begin+end)/2;              
		if(key==array[mid])               
			return mid;    
		else if(key>array[mid])             
			begin=mid+1;
		else                                       
			end=mid-1;
	}

}
