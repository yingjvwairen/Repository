template<typename T>   
class A {  
public:  
    typedef T a_type;  
};  
template<typename T>  
class B {  
public:  
    typedef typename T::a_type b_type;  //因为T是一个dependent scope，所以一定要加上typename显式地指明a_type是一个类名而不是变量名来避免歧义
};  
int main() {  
    B<A<int>> b;  //有一些环境会报错：	[Error] '>>' should be '> >' within a nested template argument list
    return 0;  
}  

/*
附：使用typename的规则（可以参考MSDN：

typename在下面情况下禁止使用：

模板定义之外，即typename只能用于模板的定义中

非限定类型，比如前面介绍过的int，vector<int>之类

基类列表中，比如template <class T> class C1 : T::InnerType不能在T::InnerType前面加typename

构造函数的初始化列表中

如果类型是依赖于模板参数的限定名，那么在它之前必须加typename(除非是基类列表，或者在类的初始化成员列表中)

其它情况下typename是可选的，也就是说对于一个不是依赖名的限定名，该名称是可选的，例如vector<int> vi;
*/