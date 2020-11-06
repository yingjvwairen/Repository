#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <complex>
using namespace std;

typedef complex<double> cd; //复数类的定义
const int maxl = 2094153;   //nlogn的最大长度
const double PI = acos(-1); //圆周率

cd a[maxl], b[maxl]; //用于储存变换的中间结果
int rev[maxl];       //用于储存自然数按比特位逆序置换后的结果
void getrev(int bit)
{
    for (int i = 0; i < (1 << bit); i++)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    } //能保证(x>>1)<x，满足递推性质
}

void fft(cd *a, int n, int opt)
{
    for (int i = 0; i < n; i++)
    {                   //按照二进制反转
        if (i < rev[i]) //保证只把前面的数和后面的数交换，否则数组会被翻回来
            swap(a[i], a[rev[i]]);
    }
    for (int step = 1; step < n; step <<= 1)  //for(int dep = 1; dep <= log2(n); ++dep){int step = 1 << dep;，dep为当前层数，step为合并后数组元素的数量
    {                                         //从第0层子问题开始对每个子问题进行合并。先枚举当前数组的前一半，并让另一半用蝴蝶变换求得
        cd W_n = exp(cd(0, opt * PI / step)); //计算此层的主n次单位根，通过观察可以发现当前层主单位根的n和合并后的数组元素数目相同，而元素数目为2的层数次幂
        //也可：cd W_n = complex(cos(2.0 * PI / step), opt * sin(2.0 * PI / step));
        for (int j = 0; j < n; j += step << 1)
        {                  //对每一组内的数据进行操作
            cd W_nk(1, 0); //即：cd W_nk = complex(1, 0);，主n次单位根的k次方，处理子问题时的旋转因子。每次合并时都需要一个旋转因子，且每一层的旋转因子都是从零次方开始的，且当k为0时，值为1
            for (int k = j; k < j + step; k++)
            { //蝴蝶变换。k的递增和代入各个k后的多项式值也是在这里实现的
                cd x = a[k];
                cd y = W_nk * a[k + step];
                a[k] = x + y;
                a[k + step] = x - y; //每一次的蝴蝶操作，根据上一次变换所合并出的结果，k就可随着数组数量的成倍增加而总数翻倍，这相当于代入了更多的k值
                W_nk *= W_n;         //将旋转因子乘以该层的主n次单位根，相当于每一次循环都给旋转因子中的k加了一，这样就适应了k的数量，保证第k次执行时旋转因子为主n次单位根的k次方
            }
        }
    }

    if (opt == -1)
    { //如果是逆变换（IFFT，则将序列各项除以n，并把单位复根换成其倒数即可。即逆变换时除了要将变换结果乘以1/n之外，逆变换中主n次单位根的次数还是负的。可以用范德蒙德行列式证明
        for (int i = 0; i < n; i++)
            a[i] /= n;
    }
}
/*
void FFT(cd *a, int opt)
{
    for (int i = 0; i < s; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int dep = 1; dep <= log2(s); ++dep)
    {
        int m = 1 << dep;
        cd wn = cd(cos(2.0 * PI / m), opt * sin(2.0 * PI / m));
        for (int k = 0; k < s; k += m)
        {
            cd w = cd(1, 0);
            for (int j = 0; j < m / 2; ++j)
            {
                cd t = w * a[k + j + m / 2];
                cd u = a[k + j];
                a[k + j] = u + t;
                a[k + j + m / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (opt == -1)
        for (int i = 0; i < s; ++i)
            a[i] /= s;
}
*/
int output[maxl];
char s1[maxl], s2[maxl];
int main()
{

    scanf("%s%s", s1, s2);                //读入两个十进制数，并看作是多项式的系数向量。每一个数字视作向量分量
    int l1 = strlen(s1), l2 = strlen(s2); //存储系数数目，亦即多项式次数减一
    int bit = 1, s = 2;                   //bit代表能存下所有系数所需的比特数量。可以看出系数的数量（即bit中能存下的最大值，就是多项式的最高次数
    for (bit = 1; (1 << bit) < l1 + l2 - 1; bit++)
    {            //注意次数为n-1和m-1的两个多项式相乘，结果的次数最大为n+m-2。即长度为n和m的两个多项式的乘积，长度为n+m-1
                 //这点和数字相乘不同，n位和m位的数字相乘结果的位数最大可以到n+m，所以FFT算法并未生成最终数，只表示出了数目的多项式形式，还需对系数作进一步判断以进位
        s <<= 1; //s存储两个多项式乘积的最高次数，因为FFT是严格分治的，所以s需要是2的整数次幂。因为循环中s滞后于bit，所以s的初值为2
    }
    for (int i = 0; i < l1; i++)
    { //第一个多项式系数向量装入a
        a[i] = (double)(s1[l1 - i - 1] - '0');
    }
    for (int i = 0; i < l2; i++)
    { //第二个多项式的系数向量存入b
        b[i] = (double)(s2[l2 - i - 1] - '0');
    }
    getrev(bit);
    fft(a, s, 1);
    fft(b, s, 1);
    for (int i = 0; i < s; i++)
        a[i] *= b[i]; //对应相乘
    fft(a, s, -1);    //IFFT
    for (int i = 0; i < s; i++)
    {                                          //还原成十进制数
        output[i] += (int)(a[i].real() + 0.5); //注意精度误差
        output[i + 1] += output[i] / 10;
        output[i] %= 10;
    }
    int i;
    for (i = l1 + l2; !output[i] && i >= 0; i--)
        ; //去掉前导零
    if (i == -1)
        printf("0"); //特判长度为0的情况
    for (; i >= 0; i--)
    { //输出这个十进制数
        printf("%d", output[i]);
    }
    putchar('\n');
    return 0;

    /*
    int power1, power2; scanf("%d %d", &power1, &power2);
    for(int i=0; i <= n; ++i)scanf("%d", &a[i].r);
    for(int i=0; i <= m; ++i)scanf("%d", &b[i].r);
    s = 1; while(s <= n + m) s <<= 1, bit++;//直接将s左移至大于两数组的长度和，数组多出的部分默认用0来补齐，不会影响结果
    for (int i =0; i < s; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    fft(a, s, 1); fft(b, s, 1);
    for(int i =0; i <= s; ++i) a[i] = a[i] * b[i];
    fft(a, s, -1);
    for(int i = 0; i <= n + m; ++i){
        printf("%d ", (int)(a[i].r+0.5));
    }
    */
}