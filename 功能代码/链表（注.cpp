#include<iostream>
#include<algorithm>
using namespace std;
struct data     //在C++中data是重载函数，已被实现。所以将变量命名为data会导致冲突，所表示的含义不明确。解决办法之一是把文件后缀名改为.c
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
    sort(a,a+m);//快速排序 
    data *head=new data();//创建头指针并指向为之创建的空间 
    head->next=NULL;//头指针下一个节点指针设为空 
    data *tail=new data();//创建尾指针并指向为之创建的空间，注意此时未设该指针下一个节点指针为空，因为注意到其实该语句执行完毕后tail->next所提取出来的数据为head->next=NULL 
    tail=head;//tail指针的值等于head指针的值，所以此时指向同一个名为data的结构体类型的数据（因head也是以data为基类型的指针 
    data *p[m]={NULL};//创建指针组并将所有元素置空，但用大括号赋值有每循环一次组内成员就全都赋值一次的风险（原来数值被清为空，所以考虑置于循环体前（外 
    p[0]=new data();//创建从节点（也就是单链表的第一个节点 所指向的空间并将地址赋予它 
    for(i=0; i!=m; ++i)
    { 
		p[i+1]=new data();//创建此时循环到的指针的下一个指针所指向的空间并将地址赋给下一个指针 
        p[i]->n=a[i];
        p[i]->next=p[i+1];//将轮到的指针的下一个指针的数值赋给轮到的指针 
        tail->next=p[i+1];//head->next=p[i+1]; 
        tail=p[i+1];//将循环轮到的指针的下一个指针的值赋给尾指针，此时尾指针已不再指向头指针所指向的空间 
        if(!i)
    	head->n=a[i],head=p[i];//head->n=a[0],head=p[0];
    	if(i==1)
    	head->next=p[1];//head->next=p[1];
    }
	output(head);
}
