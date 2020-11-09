#include <iostream>
using namespace std;

template <class T>
class linearList
{
public:
    virtual ~linearList(){};
    virtual bool empty() const = 0;
    //�����Ϊ���򷵻�true�����򷵻�false
    virtual int size() const = 0;
    //���ر�Ĵ�С(������Ԫ�ظ���)
    virtual T &get(int theIndex) const = 0;
    //���ر�������ΪtheIndex��Ԫ��
    virtual int indexOf(const T &theElement) const = 0;
    //���ر���theElementԪ�ص�һ�γ���ʱ�����������theElement���ڱ��У��򷵻�-1
    virtual void erase(int theIndex) = 0;
    //ɾ����������ΪtheIndex��Ԫ�أ���������theIndex��Ԫ��������ֵ��1
    virtual void insert(int theIndex, T &theElement) = 0;
    //��theElement���뵽��������ΪtheIndex��λ���ϣ��������ڵ���theIndex��Ԫ��������ֵ��1
    virtual void Output(out) const = 0;
    //�����Ҳ������Ԫ�ص������out
};

template <class T>
class arrayList : public linearList<T>
{
public:
    //���캯�������ƹ��캯������������
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &);
    ~arrayList() { delete[] element; }
    //ADT����
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(ostream &out) const;
    //��������
    int capacity() const { return arrayLength; }

    //����������
    iterator begin() { return iterator(element); }
    //����ָ�����Ա���Ԫ��element[0]��ָ��
    iterator end() { return iterator(element + listSize); }
    //����ָ�����Ա�βԪ�ص���һ��λ��element[listSize]��ָ��

protected:
    void checkIndex(int theIndex) const;
    //������theIndex��Ч�����׳��쳣
    void changeLength1Doubling(T *&address, int former, int latter);
    //��������������
    T *element;      //�洢���Ա�Ԫ�ص�һά����
    int arrayLength; //һά���������
    int listSize;    //���Ա��Ԫ�ظ���

public:
    //������
    class iterator;
};

template <class T>
class arrayList<T>::iterator //arrayList�ĵ�����
{                            //ΪarrayList����һ��˫�������iterator
public:
    //��C++��typedefʵ��˫�������
    typedef bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer_type;
    typedef T &reference_type;

    //���캯��
    iterator(T *thePosition = 0) { position = thePosition; }
    //�����ò�����*����õ�������ָ������
    T &operator*() const { return *position; }
    //->����������õ�������ָ���ݵĵ�ַ
    T *operator->() const { return &*position; }
    //��������ֵ���ӣ��������Ƶ���һ��Ԫ��
    iterator &operator++() //ǰ++
    {
        ++position;
        return *this;
    }
    iterator operator++(int) //��++
    {
        iterator old = *this;
        ++position;
        return old;
    }
    //��������ֵ���٣��������Ƶ�ǰһ��Ԫ��
    iterator &operator--() //ǰ--
    {
        --position;
        return *this;
    }
    iterator operator--(int) //��--
    {
        iterator old = *this;
        --position;
        return old;
    }
    //�ж��Ƿ���Ȳ���
    bool operator!=(const iterator right) const
    {
        return position != right.position;
    }
    bool operator==(const iterator right) const
    {
        return position == right.position;
    }

protected:
    T *position; //ָ���Ԫ�ص�ָ��
};

template <class T>
arrayList<T>::arrayList(int initialCapacity)
{ //���캯��
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "initialCapacity =" << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
} //ʱ�临���ԣ�O(1)����T���û��Զ�������ʱ����O(initialCapacity);

template <class T>
arrayList<T>::arrayList(const arrayList<T> &theList)
{ //���ƹ��캯��
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
} //ʱ�临���ԣ�O(n) n�����Ƶ����Ա�Ĵ�С

template <class T>
void arrayList<T>::checkIndex(int theIndex) const //����checkIndex
{                                                 //ȷ������theIndex��0��listSize-1֮��
    if (theIndex < 0 || theIndex >= listSize)
    //����theIndex��Ч
    {
        ostringstream s;
        s << "index=" << theIndex << "size =" << listSize;
        throw illegalindex(s.str());
    }
} //ʱ�临���ԣ���(1)

template <class T>
void arrayList<T>::changeLength1Doubling(T *&address, int former, int latter) //����changeLength1Doubling
{                                                                             //�����鳤�������Ϊԭ��������
    /*
    if (latter < 0)
        throw illegalParameterValue("new capacity must be >= 0");
    */
    //int number = min(former, latter); //��Ҫ���Ƶ�Ԫ�ظ���
    T *temp = new T[latter]; //������
    copy(address, address + latter, temp);
    delete[] address; //�ͷ���������ڴ�ռ�
    address = temp;
}

template <class T>
T &arrayList<T>::get(int theIndex) const //����get
{                                        //��������ΪtheIndex��Ԫ��
    //����Ԫ�ز����ڣ����׳��쳣
    checkIndex(theIndex);
    return element[theIndex];
} //ʱ�临���ԣ���(1)

template <class T>
int arrayList<T>::indexOf(const T &theElement) const //����indexOf
{                                                    //����Ԫ��theElement��һ�γ���ʱ������
    //���theElement�����ڣ��򷵻�-1
    //����Ԫ��theElement
    for (int i = 0; i < listSize; i++)
        if (element[i] == theElement)
            return i;
    return -1; //û���ҵ�
    /*
    int theIndex = (int)(find(element, element + listSize, theElement) - element);
    //ȷ��Ԫ��theElement�Ƿ��ҵ�
    if (theIndex ==listSize)
        return -1; //û���ҵ�
    else
        return theIndex;
    */
} //ʱ�临���ԣ�O(listSize)

template <class T>
void arrayList<T>::erase(int theIndex) //����erase
{                                      //ɾ����������ΪtheIndex��Ԫ�أ���������theIndex��Ԫ��������ֵ��1
    //�������ΪtheIndexԪ�ز����ڣ����׳��쳣�����������ΪtheIndex+1,...,listSize-1��Ԫ����ǰ�ƶ�һ��λ�á�listSize��1
    checkIndex(theIndex);
    //��������theIndex��Ԫ����ǰ�ƶ�һ��λ��
    for (int i = theIndex + 1; i < listSize; i++)
        element[i - 1] = element[i];
    /*
    copy(element + theIndex + 1, element + listSize,
         element + theIndex);
    */
    element[--listSize].~T();
} //ʱ�临����: O(listSize-theIndex)

template <class T>
void arrayList<T>::insert(int theIndex, const T &theElement) //����insert
{                                                            //������theIndex������Ԫ��theElement;
    //���theIndex��Ч���������쳣
    if (theIndex < 0 || theIndex > listSize)
    {
        ......
    }
    //������������������鳤�ȱ���
    if (listSize == arrayLength)
    {
        changeLength1Doubling(element��arrayLength��2 * arrayLength);
        arrayLength *= 2;
    }
    //�������ڵ���theIndex��Ԫ������ƶ�һ��λ��
    for (int i = listSize - 1; i >= theIndex; i--)
        element[i + 1] = element[i];
    /*
    copy_backward(element + theIndex��element + listSize;
                  element + listSize + 1);
    */
    //��Ԫ�ز��뵽theIndexλ�ô�
    element[theIndex] = theElement;
    //listSize��1
    listSize++;
} //ʱ�临���ԣ�O(listSize)

template <class T>
void arrayList<T>::output(ostream &out) const //����output
{                                             //�����Ա���������
    for (int i = 0; i < listSize; i++)
        out << element[i] << ' ';
    /*
    copy(element, element + listSize,
         ostream_iterator<T>(cout, " "));
    */
} //ʱ�临���ԣ���(listSize)

//����<<
template <class T>
ostream &operator<<(ostream &out,
                    const arrayList<T> &x)
{
    x.Output(out);
    return out;
}

//arraylistʵ����
/*
//������������Ϊ100�����Ա�
linearList*x=(linearList) new arrayList<int> (100);
arrayList<double> y(100);
//����������ȱʡֵ����һ�����Ա�
arrayList <char> z;
//�����Ա�y���ƴ���һ�����Ա�
arrayList <double> w(y);
*/
//����������ʵ������ʼ��
/*
arrayList<int>::iterator x = y.begin();
*/
