#include <iostream>
#include <numeric>
using namespace std;
template <class T>
class chainNode
{
public:
    T element;
    chainNode<T> *next;

    chainNode() {}
    chainNode(const T &element)
    {
        this->element = element;
    }
    chainNode(const T &element, chainNode<T> *next)
    {
        this->element = element;
        this->next = next;
    }

    friend ostream &operator<<(ostream &os, chainNode<int> c);
};

ostream &operator<<(ostream &os, chainNode<int> c)
{
    os << c.element;
    return os;
}

template <class T>
class test
{
public:
    test(chainNode<T> *theNode = NULL)
    {
        node = theNode;
    }

    T &operator*() const { return node->element; }

    T *operator->() const { return &node->element; }

protected:
    chainNode<T> *node;
};

template <class T>
class truth
{
public:
    truth(chainNode<T> &theNode = 0) : node(theNode) {}

    T &operator*() const { return node.element; }

    T *operator->() const { return &node.element; }

protected:
    chainNode<T> &node;
};

template <class T>
class perspective
{
public:
    perspective(chainNode<T> theNode = 0)
    {
        node = theNode;
    }

    T &operator*() const { return node.element; } //实例化时会报错，因为只能修改指针或引用变量里的值

    T *operator->() const { return &node.element; } //实例化时会报错，因为只可修改指针或引用类型成员中的值

protected:
    chainNode<T> node;
    //变量这样子写会被判定为是此类的一部分，所以不允许在常成员函数中修改。而如果此变量是指针或引用类型的话则会被认为是引用的类外的变量，所以可以修改
};
int main()
{
    chainNode<int> c(10);
    test<int> i(&c);
    cout << *i << "  ";
    cout << endl;
    *i += 10;
    cout << *i << "  ";
    cout << endl;

    truth<int> j(c);
    cout << *j << "  ";
    cout << endl;
    *j += 10;
    cout << *j << "  ";
    cout << endl;
    /*  
error:
    perspective<int> p(c);
    cout << *p << "  ";
    cout << endl;
    *p += 10;
    cout << *p << "  ";
    cout << endl;
    */
}