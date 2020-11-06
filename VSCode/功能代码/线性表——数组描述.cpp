#include <iostream>
using namespace std;

template <class T>
class linearList
{
public:
    virtual ~linearList(){};
    virtual bool empty() const = 0;
    //如果表为空则返回true，否则返回false
    virtual int size() const = 0;
    //返回表的大小(即表中元素个数)
    virtual T &get(int theIndex) const = 0;
    //返回表中索引为theIndex的元素
    virtual int indexOf(const T &theElement) const = 0;
    //返回表中theElement元素第一次出现时的索引；如果theElement不在表中，则返回-1
    virtual void erase(int theIndex) = 0;
    //删除表中索引为theIndex的元素，索引大于theIndex的元素其索引值减1
    virtual void insert(int theIndex, T &theElement) = 0;
    //把theElement插入到表中索引为theIndex的位置上，索引大于等于theIndex的元素其索引值加1
    virtual void Output(out) const = 0;
    //从左到右插入表中元素到输出流out
};

template <class T>
class arrayList : public linearList<T>
{
public:
    //构造函数、复制构造函数、析构函数
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &);
    ~arrayList() { delete[] element; }
    //ADT方法
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(ostream &out) const;
    //其他方法
    int capacity() const { return arrayLength; }

    //迭代器方法
    iterator begin() { return iterator(element); }
    //返回指向线性表首元素element[0]的指针
    iterator end() { return iterator(element + listSize); }
    //返回指向线性表尾元素的下一个位置element[listSize]的指针

protected:
    void checkIndex(int theIndex) const;
    //若索引theIndex无效，则抛出异常
    void changeLength1Doubling(T *&address, int former, int latter);
    //将数组容量倍增
    T *element;      //存储线性表元素的一维数组
    int arrayLength; //一维数组的容量
    int listSize;    //线性表的元素个数

public:
    //迭代器
    class iterator;
};

template <class T>
class arrayList<T>::iterator //arrayList的迭代器
{                            //为arrayList定义一个双向迭代器iterator
public:
    //用C++的typedef实现双向迭代器
    typedef bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer_type;
    typedef T &reference_type;

    //构造函数
    iterator(T *thePosition = 0) { position = thePosition; }
    //解引用操作符*，获得迭代器所指的数据
    T &operator*() const { return *position; }
    //->操作符，获得迭代器所指数据的地址
    T *operator->() const { return &*position; }
    //迭代器的值增加，迭代器移到后一个元素
    iterator &operator++() //前++
    {
        ++position;
        return *this;
    }
    iterator operator++(int) //后++
    {
        iterator old = *this;
        ++position;
        return old;
    }
    //迭代器的值减少，迭代器移到前一个元素
    iterator &operator--() //前--
    {
        --position;
        return *this;
    }
    iterator operator--(int) //后--
    {
        iterator old = *this;
        --position;
        return old;
    }
    //判断是否相等测试
    bool operator!=(const iterator right) const
    {
        return position != right.position;
    }
    bool operator==(const iterator right) const
    {
        return position == right.position;
    }

protected:
    T *position; //指向表元素的指针
};

template <class T>
arrayList<T>::arrayList(int initialCapacity)
{ //构造函数
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "initialCapacity =" << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
} //时间复杂性：O(1)；当T是用户自定义类型时，是O(initialCapacity);

template <class T>
arrayList<T>::arrayList(const arrayList<T> &theList)
{ //复制构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
} //时间复杂性：O(n) n：复制的线性表的大小

template <class T>
void arrayList<T>::checkIndex(int theIndex) const //方法checkIndex
{                                                 //确定索引theIndex在0和listSize-1之间
    if (theIndex < 0 || theIndex >= listSize)
    //索引theIndex无效
    {
        ostringstream s;
        s << "index=" << theIndex << "size =" << listSize;
        throw illegalindex(s.str());
    }
} //时间复杂性：Θ(1)

template <class T>
void arrayList<T>::changeLength1Doubling(T *&address, int former, int latter) //方法changeLength1Doubling
{                                                                             //将数组长度扩大成为原来的两倍
    /*
    if (latter < 0)
        throw illegalParameterValue("new capacity must be >= 0");
    */
    //int number = min(former, latter); //需要复制的元素个数
    T *temp = new T[latter]; //新数组
    copy(address, address + latter, temp);
    delete[] address; //释放老数组的内存空间
    address = temp;
}

template <class T>
T &arrayList<T>::get(int theIndex) const //方法get
{                                        //返回索引为theIndex的元素
    //若此元素不存在，则抛出异常
    checkIndex(theIndex);
    return element[theIndex];
} //时间复杂性：Θ(1)

template <class T>
int arrayList<T>::indexOf(const T &theElement) const //方法indexOf
{                                                    //返回元素theElement第一次出现时的索引
    //如果theElement不存在，则返回-1
    //查找元素theElement
    for (int i = 0; i < listSize; i++)
        if (element[i] == theElement)
            return i;
    return -1; //没有找到
    /*
    int theIndex = (int)(find(element, element + listSize, theElement) - element);
    //确定元素theElement是否找到
    if (theIndex ==listSize)
        return -1; //没有找到
    else
        return theIndex;
    */
} //时间复杂性：O(listSize)

template <class T>
void arrayList<T>::erase(int theIndex) //方法erase
{                                      //删除表中索引为theIndex的元素，索引大于theIndex的元素其索引值减1
    //如果索引为theIndex元素不存在，则抛出异常。否则把索引为theIndex+1,...,listSize-1的元素向前移动一个位置。listSize减1
    checkIndex(theIndex);
    //索引大于theIndex的元素向前移动一个位置
    for (int i = theIndex + 1; i < listSize; i++)
        element[i - 1] = element[i];
    /*
    copy(element + theIndex + 1, element + listSize,
         element + theIndex);
    */
    element[--listSize].~T();
} //时间复杂性: O(listSize-theIndex)

template <class T>
void arrayList<T>::insert(int theIndex, const T &theElement) //方法insert
{                                                            //在索引theIndex处插入元素theElement;
    //如果theIndex无效，则引发异常
    if (theIndex < 0 || theIndex > listSize)
    {
        ......
    }
    //如果数组已满，则数组长度倍增
    if (listSize == arrayLength)
    {
        changeLength1Doubling(element，arrayLength，2 * arrayLength);
        arrayLength *= 2;
    }
    //索引大于等于theIndex的元素向后移动一个位置
    for (int i = listSize - 1; i >= theIndex; i--)
        element[i + 1] = element[i];
    /*
    copy_backward(element + theIndex，element + listSize;
                  element + listSize + 1);
    */
    //新元素插入到theIndex位置处
    element[theIndex] = theElement;
    //listSize加1
    listSize++;
} //时间复杂性：O(listSize)

template <class T>
void arrayList<T>::output(ostream &out) const //方法output
{                                             //把线性表插入输出流
    for (int i = 0; i < listSize; i++)
        out << element[i] << ' ';
    /*
    copy(element, element + listSize,
         ostream_iterator<T>(cout, " "));
    */
} //时间复杂性：Θ(listSize)

//重载<<
template <class T>
ostream &operator<<(ostream &out,
                    const arrayList<T> &x)
{
    x.Output(out);
    return out;
}

//arraylist实例化
/*
//创建两个容量为100的线性表
linearList*x=(linearList) new arrayList<int> (100);
arrayList<double> y(100);
//利用容量的缺省值创建一个线性表
arrayList <char> z;
//用线性表y复制创建一个线性表
arrayList <double> w(y);
*/
//创建迭代器实例及初始化
/*
arrayList<int>::iterator x = y.begin();
*/
