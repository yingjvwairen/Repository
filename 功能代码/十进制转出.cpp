#include<iostream>
using namespace std;
void show2bit(int num)      //10进制转换2进制
{
    int p[32],n;        //int型最大值为2147483647,即2^32-1
    for(int i=0;i<32;i++)
    {
        n=num%2;
        p[i]=n;
        num=num/2;
    }
    for(int i=31;i>=0;i--)
    {
        cout<<p[i];
        if(i%4==0)      //2进制每4个数隔一个空格
            cout<<" ";
    }
}
void show8bit(int num)      //10进制转换8进制
{
    int p[32],n;
    for(int i=0;i<32;i++)
    {
        n=num%8;
        p[i]=n;
        num=num/8;
    }
    for(int i=31;i>=0;i--)
    {
        cout<<p[i];
        if(i%4==0)      //8进制每4个数隔一个空格
            cout<<" ";
    }
}
void show16bit(int num)      //10进制转换16进制
{
    int p[32];
    int n;
    for(int i=0;i<32;i++)
    {
        n=num%16;
        p[i]=n;
        num=num/16;
    }
    for(int i=31;i>=0;i--)
    {
        switch(p[i])        //大于9的用A,B,C,D,E,F表示
        {
        case 10:
            cout<<"A";
            break;
        case 11:
            cout<<"B";
            break;
        case 12:
            cout<<"C";
            break;
        case 13:
            cout<<"D";
            break;
        case 14:
            cout<<"E";
            break;
        case 15:
            cout<<"F";
            break;
        default:
            cout<<p[i];
        }
        if(i%2==0)      //16进制每2个数隔一个空格
            cout<<" ";
    }
}
	//以上是循环加选择（十六进制，实现不同进制数的相互转化
	//以下是用递归加选择（十六进制，实现 
/*
void show2bit(int num)
{
    if(num>1)                   //num>1时递归调用show2bit
    {
        show2bit(num/2);
        cout<<" ";
    }
    cout<<num%2;                //num<=1时输出
}
void show8bit(int num)
{
    if(num>7)                   //num>7时递归调用show8bit
    {
        show8bit(num/8);
        cout<<" ";
    }
    cout<<num%8;                //num<=7时输出
}
void show16bit(int num)
{
    if(num>15)                   //num>15时递归调用show16bit
    {
        show16bit(num/16);
        cout<<" ";
    }
    switch(num%16)              //num<=15时输出,//大于9的用A,B,C,D,E,F表示
    {
    case 10:
        cout<<"A";
        break;
    case 11:
        cout<<"B";
        break;
    case 12:
        cout<<"C";
        break;
    case 13:
        cout<<"D";
        break;
    case 14:
        cout<<"E";
        break;
    case 15:
        cout<<"F";
        break;
    default:
        cout<<num%16;
    }
}
*/
void change(int n,int num)      //调用转换进制函数
{
    switch(n)
    {
    case 2:
        cout<<"10进制数"<<num<<"转换成2进制为:"<<endl;
        show2bit(num);
        cout<<endl;
        break;
    case 8:
        cout<<"10进制数"<<num<<"转换成8进制为:"<<endl;
        show8bit(num);
        cout<<endl;
        break;
    case 16:
        cout<<"10进制数"<<num<<"转换成16进制为:"<<endl;
        show16bit(num);
        cout<<endl;
        break;
    }
}
int main()
{
    int num,n,i=0;
    while(1)
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"最多可提供4次进制转化，输入转化的进制(2,8,16)"<<endl;
        cin>>n;
        if(n!=2&&n!=8&&n!=16)
        	cout<<"输入转换进制有误，请重新输入"<<endl;
        else
        {
            cout<<"输入需要转换的数:";
            cin>>num;       //int型最大值为2147483647,输入值不能大于这个数
            change(n,num);
            i++;
        }
        if(i==4)        //控制转换次数，大于4次退出
        {
            cout<<"---------------------------------------------------"<<endl;
            break;
        }
        else
        	continue;
    }
}

