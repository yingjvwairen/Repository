#include <stdlib.h>
int compare_ints_function(void*A,void*B)
{
    return*((int*)(A))<*((int*)(B));
}
void sort(void*first_item,size_t item_size,void*last_item,int(*cmpfunc)(void*,void*)){
};//ʹ�ú���ָ����ʵ�ֻص�����
class compare_class{
public:
    bool operator()(int A, int B)const{return A < B;}//ͨ����һ��������������������ķ���ʹ��һ���������������һ����ͨ�������˺��������Ϊ�º��� 
};
template<class ComparisonFunctor>
    void sort_ints(int* begin_items, int num_items, ComparisonFunctor c){};
int main(void)
{
    int items[]={4,3,1,2};
    sort((void*)(items),sizeof(int),(void*)(items +3), compare_ints_function);
    compare_class functor;
    sort_ints(items, sizeof(items)/sizeof(items[0]), functor);
    return 0;
}
