#include<iostream>
using namespace std;
void show2bit(int num)      //10����ת��2����
{
    int p[32],n;        //int�����ֵΪ2147483647,��2^32-1
    for(int i=0;i<32;i++)
    {
        n=num%2;
        p[i]=n;
        num=num/2;
    }
    for(int i=31;i>=0;i--)
    {
        cout<<p[i];
        if(i%4==0)      //2����ÿ4������һ���ո�
            cout<<" ";
    }
}
void show8bit(int num)      //10����ת��8����
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
        if(i%4==0)      //8����ÿ4������һ���ո�
            cout<<" ";
    }
}
void show16bit(int num)      //10����ת��16����
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
        switch(p[i])        //����9����A,B,C,D,E,F��ʾ
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
        if(i%2==0)      //16����ÿ2������һ���ո�
            cout<<" ";
    }
}
	//������ѭ����ѡ��ʮ�����ƣ�ʵ�ֲ�ͬ���������໥ת��
	//�������õݹ��ѡ��ʮ�����ƣ�ʵ�� 
/*
void show2bit(int num)
{
    if(num>1)                   //num>1ʱ�ݹ����show2bit
    {
        show2bit(num/2);
        cout<<" ";
    }
    cout<<num%2;                //num<=1ʱ���
}
void show8bit(int num)
{
    if(num>7)                   //num>7ʱ�ݹ����show8bit
    {
        show8bit(num/8);
        cout<<" ";
    }
    cout<<num%8;                //num<=7ʱ���
}
void show16bit(int num)
{
    if(num>15)                   //num>15ʱ�ݹ����show16bit
    {
        show16bit(num/16);
        cout<<" ";
    }
    switch(num%16)              //num<=15ʱ���,//����9����A,B,C,D,E,F��ʾ
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
void change(int n,int num)      //����ת�����ƺ���
{
    switch(n)
    {
    case 2:
        cout<<"10������"<<num<<"ת����2����Ϊ:"<<endl;
        show2bit(num);
        cout<<endl;
        break;
    case 8:
        cout<<"10������"<<num<<"ת����8����Ϊ:"<<endl;
        show8bit(num);
        cout<<endl;
        break;
    case 16:
        cout<<"10������"<<num<<"ת����16����Ϊ:"<<endl;
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
        cout<<"�����ṩ4�ν���ת��������ת���Ľ���(2,8,16)"<<endl;
        cin>>n;
        if(n!=2&&n!=8&&n!=16)
        	cout<<"����ת��������������������"<<endl;
        else
        {
            cout<<"������Ҫת������:";
            cin>>num;       //int�����ֵΪ2147483647,����ֵ���ܴ��������
            change(n,num);
            i++;
        }
        if(i==4)        //����ת������������4���˳�
        {
            cout<<"---------------------------------------------------"<<endl;
            break;
        }
        else
        	continue;
    }
}

