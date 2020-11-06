//û�ж��幹�캯�����಻�ܶ������Ķ������飨�������ͳ���

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
//û��Ĭ�Ϲ��캯�������ڶ��������ʱ�򣬻�������⣬��Ϊ�����޷����г�ʼ��
//Ĭ�Ϲ��캯�����ǰ����������Զ����ɵ��Ǹ����캯�����ڣ��ڵ���ʱ����Ҫ��ʽ�ش���ʵ�εĹ��캯��

int main()
{
    //A vecs[10];   //compile failed
    //Method 1: placement new
    void *raw = operator new[](3 * sizeof(A));//����һ��operator new
    A *pa = static_cast<A *>(raw);
    for (int i = 0; i < 3; ++i)
        new (&pa[i]) A(i); //placement new

    //destructor + deallocate
    for (int i = 0; i < 3; ++i)
        pa[i].~A();        //ֻ����ÿ��λ�ô���������������������û���ͷ��ڴ棬ע������Ҫ��ʽ������������
    operator delete[](raw); //ͨ��operator delete��ɾ��operator new����Ŀռ����ͷ��ڴ�
    //delete [] pa;   //�˾���������ڴ�й©����Ϊdelete�Ŀռ���ܺ���operator new����Ŀռ��С��һ��

    //��������ķ������Ƿ��幹�캯��û�й�ϵ
    void *raw2 = operator new(sizeof(int));
    int *p = static_cast<int *>(raw2);
    new (p) int(3);
    cout << *p << endl;
    delete p; //��������û������������ֱ��delete����

    void *raw3 = operator new[](sizeof(int) * 3);
    int *pInts = static_cast<int *>(raw3);
    for (int i = 0; i < 3; ++i)
        new (&(pInts[i])) int(i); //placement new

    for (int i = 0; i < 3; ++i)
        cout << pInts[i] << endl;

    operator delete[](pInts);

    return 0;
}