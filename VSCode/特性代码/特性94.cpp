class base{};
class base2{};
class derived:public base,base2{};//base2为private
derived *pd = new derived();
void *pv = pd;	//将derived指针转换为void指针
base2 *pb = static_cast<base2 *>(pv);//转换后pb与pd有相同的地址，而正常的转换下应有一个偏移量。有void指针参与的转换，兼容性规则不适用，应尽量避免这样用
derived d;
base2 b;
//base2 b=static_cast<base2 >(d);   //derived中的base2为private，访问受限无法转换
//derived d=static_cast<derived >(b);  //转换原类型和目标类型只能是指针或引用，且derived中的base2为private，访问受限无法转换
int main(){}