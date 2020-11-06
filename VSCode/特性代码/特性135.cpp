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

    T &operator*() const { return node.element; } //ʵ����ʱ�ᱨ����Ϊֻ���޸�ָ������ñ������ֵ

    T *operator->() const { return &node.element; } //ʵ����ʱ�ᱨ����Ϊֻ���޸�ָ����������ͳ�Ա�е�ֵ

protected:
    chainNode<T> node;
    //����������д�ᱻ�ж�Ϊ�Ǵ����һ���֣����Բ������ڳ���Ա�������޸ġ�������˱�����ָ����������͵Ļ���ᱻ��Ϊ�����õ�����ı��������Կ����޸�
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