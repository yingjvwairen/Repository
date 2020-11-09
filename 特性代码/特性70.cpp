#include<iostream>
using namespace std;
class a {
	public:
		void GetValue() {
			cout<<k<<endl;
		}
	private:
		int k;
};
class b {
	public:
		int i;
		void setJ(int _j) {
			j = _j;
		};
		int getJ() const {
			return j;
		};
	private:
		int j;
};
int main() {
	a x;
	a *p=&x;
	*((int *)p)=100;
	cout<<&x<<endl;
	x.GetValue();//实现原理：对象地址就是第一个成员变量的地址
	//C++编译器将数据和程序段分开，所有的类变量会按照声明顺序依次存入数据段，所以，如果知道了第一个变量的地址，那么后面的地址也就依次累加 即可逐一求出了。有了变量地址，那么也就可以对它的值进行修改了
	b c;
	c.setJ(2);
	printf("修改前j的值是%d\n",c.getJ());//打印修改前j的值
	int *P = (int *)((int*)(&c)+sizeof(c.i));
	*P = 10;
	printf("修改后j的值是%d\n",c.getJ()); //打印修改后j的值
	return 0;
}

