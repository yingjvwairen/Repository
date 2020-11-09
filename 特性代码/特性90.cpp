template <unsigned N>
struct Power
{
	template <class T>
	static T value(T x)
	{
		return x * Power<N - 1>::value(x);
	}
};
template <>
struct Power<1>
{
	template <class T>
	static T value(T x)
	{
		return x;
	}
};
template <unsigned N, class T>
inline T power(T v)
{
	return Power<N>::value(v);
}
/*
template <class T>
inline T power(unsigned N, T v)
{
	return Power<N>::value(v);//过不了编译，因为Power模板是在编译时用代码中所给值来实例化的，而此语句中的尖括号中的值并不确定，无法实例化
}
*/
int main()
{
	Power<4>::value(5);
	power<4>(5);
}