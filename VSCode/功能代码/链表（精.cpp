#include<iostream>
#include<algorithm>
using namespace std;
/*说明下，这儿传入的参数是头节点的地址，而不是头节点，这点主要是针对当插入的数时最小的情况，当插入的值比已有链表中所有的值都小时，就得修改头节点，这时就只有传入指针的指针，也就是头结点的地址。
另外一个就是这里面没移动一次节点，都取了当前节点地址来赋值给t，这也是针对头结点这个特殊节点来的，因为我们插入一个节点，就是要找到插入点的上一个节点的next，而这个next可能是普通节点的next，也有可能是头结点，
headp = &t->next;//这里的headp是头节点的指针 
就是来抽象这两种不同的情况，把这情况的节点的属性都看成一种节点。*/
struct data     //在C++中data是一个库中重载函数的名字。所以命名变量data会导致命名冲突，即变量代表的含义不明确。可以把文件后缀名改为.c来解决
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
