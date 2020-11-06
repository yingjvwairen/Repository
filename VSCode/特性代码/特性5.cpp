#include <iostream>
#include <cstdio>
using namespace std;
int main()
{	
//以下是关于定义变量时const所修饰的变量的分析 
	const type a,b;// a 和 b是并列关系 ，const位于它们之前，故const修饰 a 和 b  
 	type const a,b;// a 和 b是并列关系 ，const位于它们之前，故const修饰 a 和 b 
 	type * const a, * b;// * a 和 * b是并列关系 ，const位于a之前，故const仅修饰 a
 	type * const a,b;//  * a 和 b是并列关系 ，const位于a之前，故const只修饰 a  
 	const type * a,b;// * a 和 b是并列关系 ，const修饰 * a 和 b 
//以上，const在具有并列关系的多个变量前时，会修饰带有并列关系的所有变量 (显然易知，需要注意的是，指针变量无法并列 
}
