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
	return Power<N>::value(v);//�����˱��룬��ΪPowerģ�����ڱ���ʱ�ô���������ֵ��ʵ�����ģ���������еļ������е�ֵ����ȷ�����޷�ʵ����
}
*/
int main()
{
	Power<4>::value(5);
	power<4>(5);
}