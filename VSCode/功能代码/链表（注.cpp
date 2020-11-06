#include<iostream>
#include<algorithm>
using namespace std;
struct data     //��C++��data�����غ������ѱ�ʵ�֡����Խ���������Ϊdata�ᵼ�³�ͻ������ʾ�ĺ��岻��ȷ������취֮һ�ǰ��ļ���׺����Ϊ.c
{
    int n;
    data *next;
};
data* insert(data **headp, int N)
{
	register data* t;
	register data* newp;	
	while((t=*headp)!=NULL&&t->n<N)		
		headp=&t->next;
		newp=(data*)malloc(sizeof(data));
	if(newp==NULL)
		return t;
		newp->n=N;
		newp->next=t;
		*headp=newp;
		return newp;
}
data* remove(data *head, int N)
{
    data* ptr=head;
    while(ptr->next!=NULL)
    {
        if(ptr->next->n==N)
        {
            ptr->next=ptr->next->next;
            ptr=ptr->next;
            return head;
        }
        else
            ptr=ptr->next;
    }
    return head->next; 
}
void output(data *head)
{
    data *t=head;
    int j=0;
    while(t->next!=NULL)
    {
        if(j==0)
        {
            cout<<t->n;
            ++j;
            t=t->next;
        }
        else
        {
            cout<<' '<<t->n;
            ++j;
            t=t->next;
        }
    }
}
int main()
{
    int i,m,N;
    cin>>m>>N;
    if(m<=1)
    return true,false;
	int a[m+100];
    for(i=0; i<m; ++i)
        cin>>a[i];
    sort(a,a+m);//�������� 
    data *head=new data();//����ͷָ�벢ָ��Ϊ֮�����Ŀռ� 
    head->next=NULL;//ͷָ����һ���ڵ�ָ����Ϊ�� 
    data *tail=new data();//����βָ�벢ָ��Ϊ֮�����Ŀռ䣬ע���ʱδ���ָ����һ���ڵ�ָ��Ϊ�գ���Ϊע�⵽��ʵ�����ִ����Ϻ�tail->next����ȡ����������Ϊhead->next=NULL 
    tail=head;//tailָ���ֵ����headָ���ֵ�����Դ�ʱָ��ͬһ����Ϊdata�Ľṹ�����͵����ݣ���headҲ����dataΪ�����͵�ָ�� 
    data *p[m]={NULL};//����ָ���鲢������Ԫ���ÿգ����ô����Ÿ�ֵ��ÿѭ��һ�����ڳ�Ա��ȫ����ֵһ�εķ��գ�ԭ����ֵ����Ϊ�գ����Կ�������ѭ����ǰ���� 
    p[0]=new data();//�����ӽڵ㣨Ҳ���ǵ�����ĵ�һ���ڵ� ��ָ��Ŀռ䲢����ַ������ 
    for(i=0; i!=m; ++i)
    { 
		p[i+1]=new data();//������ʱѭ������ָ�����һ��ָ����ָ��Ŀռ䲢����ַ������һ��ָ�� 
        p[i]->n=a[i];
        p[i]->next=p[i+1];//���ֵ���ָ�����һ��ָ�����ֵ�����ֵ���ָ�� 
        tail->next=p[i+1];//head->next=p[i+1]; 
        tail=p[i+1];//��ѭ���ֵ���ָ�����һ��ָ���ֵ����βָ�룬��ʱβָ���Ѳ���ָ��ͷָ����ָ��Ŀռ� 
        if(!i)
    	head->n=a[i],head=p[i];//head->n=a[0],head=p[0];
    	if(i==1)
    	head->next=p[1];//head->next=p[1];
    }
	output(head);
}
