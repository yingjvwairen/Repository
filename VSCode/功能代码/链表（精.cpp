#include<iostream>
#include<algorithm>
using namespace std;
/*˵���£��������Ĳ�����ͷ�ڵ�ĵ�ַ��������ͷ�ڵ㣬�����Ҫ����Ե��������ʱ��С��������������ֵ���������������е�ֵ��Сʱ���͵��޸�ͷ�ڵ㣬��ʱ��ֻ�д���ָ���ָ�룬Ҳ����ͷ���ĵ�ַ��
����һ������������û�ƶ�һ�νڵ㣬��ȡ�˵�ǰ�ڵ��ַ����ֵ��t����Ҳ�����ͷ����������ڵ����ģ���Ϊ���ǲ���һ���ڵ㣬����Ҫ�ҵ���������һ���ڵ��next�������next��������ͨ�ڵ��next��Ҳ�п�����ͷ��㣬
headp = &t->next;//�����headp��ͷ�ڵ��ָ�� 
���������������ֲ�ͬ���������������Ľڵ�����Զ�����һ�ֽڵ㡣*/
struct data     //��C++��data��һ���������غ��������֡�������������data�ᵼ��������ͻ������������ĺ��岻��ȷ�����԰��ļ���׺����Ϊ.c�����
{
    int n;
    data *next;
};
data* insert(data **headp, int N)
{
	register data* t;
	register data* newp;	
	while((t=*headp)!=NULL&&t->n<N)		
		headp = &t->next;
		newp= (data*)malloc(sizeof(data));
	if(newp == NULL)
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
    int f=0;
    while(t->next!=NULL)
    {
        if(f==0)
        {
            cout<<t->next->n;
            f++;
            t=t->next;
        }
        else
        {
            cout<<' '<<t->next->n;
            f++;
            t=t->next;
        }
    }
}
int main()
{
    int i,m,N;
    cin>>m>>N;
    int a[m+100];
    for(i=0; i<m; ++i)
        cin>>a[i];
    sort(a,a+m);
    data *head=new data();
    head->next=NULL;
    data *tail=new data();
    tail=head;
    for(i=0; i!=m; ++i)
    {
        data *p=new data();
        p->n=a[i];
        p->next=NULL;
        tail->next=p;
        tail=tail->next;
    }
	
}
