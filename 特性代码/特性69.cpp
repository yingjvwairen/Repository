#include <stdlib.h>
int compare_ints_function(void*A,void*B)
{
    return*((int*)(A))<*((int*)(B));
}
void sort(void*first_item,size_t item_size,void*last_item,int(*cmpfunc)(void*,void*)){
};//使用函数指针来实现回调函数
class compare_class{
public:
    bool operator()(int A, int B)const{return A < B;}//通过在一个类中重载括号运算符的方法使用一个函数对象而不是一个普通函数，此函数对象称为仿函数 
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
