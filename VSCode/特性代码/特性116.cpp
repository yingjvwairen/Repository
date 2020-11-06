//没有定义构造函数的类不能定义该类的对象数组（内置类型除外

//operator new + ctor
//dtor + operator delete

//operator new[] + ctor
//dtor + operator delete []

#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int x;

public:
    A(int _x) : x(_x) {}
    ~A() {}
};
//没有默认构造函数的类在定义数组的时候，会出现问题，因为数组无法进行初始化
//默认构造函数就是包括编译器自动生成的那个构造函数在内，在调用时不需要显式地传入实参的构造函数

int main()
{
    //A vecs[10];   //compile failed
    //Method 1: placement new
    void *raw = operator new[](3 * sizeof(A));//调用一次operator new
    A *pa = static_cast<A *>(raw);
    for (int i = 0; i < 3; ++i)
        new (&pa[i]) A(i); //placement new

    //destructor + deallocate
    for (int i = 0; i < 3; ++i)
        pa[i].~A();        //只是在每个位置处调用了析构函数，但是没有释放内存，注意这里要显式调用析构函数
    operator delete[](raw); //通过operator delete来删除operator new分配的空间以释放内存
    //delete [] pa;   //此句容易造成内存泄漏，因为delete的空间可能和用operator new分配的空间大小不一致

    //但是下面的方法与是否定义构造函数没有关系
    void *raw2 = operator new(sizeof(int));
    int *p = static_cast<int *>(raw2);
    new (p) int(3);
    cout << *p << endl;
    delete p; //内置类型没有析构函数，直接delete即可

    void *raw3 = operator new[](sizeof(int) * 3);
    int *pInts = static_cast<int *>(raw3);
    for (int i = 0; i < 3; ++i)
        new (&(pInts[i])) int(i); //placement new

    for (int i = 0; i < 3; ++i)
        cout << pInts[i] << endl;

    operator delete[](pInts);

    return 0;
}