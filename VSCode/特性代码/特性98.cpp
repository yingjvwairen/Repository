template<typename T>   
class A {  
public:  
    typedef T a_type;  
};  
template<typename T>  
class B {  
public:  
    typedef typename T::a_type b_type;  //��ΪT��һ��dependent scope������һ��Ҫ����typename��ʽ��ָ��a_type��һ�����������Ǳ���������������
};  
int main() {  
    B<A<int>> b;  //��һЩ�����ᱨ��	[Error] '>>' should be '> >' within a nested template argument list
    return 0;  
}  

/*
����ʹ��typename�Ĺ��򣨿��Բο�MSDN��

typename����������½�ֹʹ�ã�

ģ�嶨��֮�⣬��typenameֻ������ģ��Ķ�����

���޶����ͣ�����ǰ����ܹ���int��vector<int>֮��

�����б��У�����template <class T> class C1 : T::InnerType������T::InnerTypeǰ���typename

���캯���ĳ�ʼ���б���

���������������ģ��������޶�������ô����֮ǰ�����typename(�����ǻ����б���������ĳ�ʼ����Ա�б���)

���������typename�ǿ�ѡ�ģ�Ҳ����˵����һ���������������޶������������ǿ�ѡ�ģ�����vector<int> vi;
*/