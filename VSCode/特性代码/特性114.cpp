#include <iostream>
using namespace std;
 
struct test{
	size_t m;
        //类成员m，这里选择了size_t类型，而不是int类型
	test(){cout << "construct..." << endl;}  
        //构造函数
	~test(){cout << "destructed." << endl;}   
        //析构函数，稍后可以注释掉，看看结果
};
 
void test_free_new(){
	int k = 5; 
        //数组的长度，可任意修改，看看结果
 
	test* tp = new test[k]; 
        //用new建立一个对象数组      
	for(int n=0;n<k;n++) tp[n].m = (n+1)*100; 
        //对成员m进行赋值，用(n+1)*100这个表达式可以让输出结果看得清楚些
 
	size_t* sp = reinterpret_cast<size_t*>(tp);
        //定义一个size_t指针，进行强制转换
	sp --;
        //移到存储空间之前的内存
	for(int n=0;n<k+1;n++) cout << "sp[" << n << "] is : " << sp[n] << endl; 
        //输出包括对象数组之前的一个单元的内容
	delete[] tp;
}
 
 
int main() {
	test_free_new();
	return 0;
}