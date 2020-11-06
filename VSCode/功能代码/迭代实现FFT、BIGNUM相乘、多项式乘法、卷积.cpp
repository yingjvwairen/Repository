#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <complex>
using namespace std;

typedef complex<double> cd; //������Ķ���
const int maxl = 2094153;   //nlogn����󳤶�
const double PI = acos(-1); //Բ����

cd a[maxl], b[maxl]; //���ڴ���任���м���
int rev[maxl];       //���ڴ�����Ȼ��������λ�����û���Ľ��
void getrev(int bit)
{
    for (int i = 0; i < (1 << bit); i++)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    } //�ܱ�֤(x>>1)<x�������������
}

void fft(cd *a, int n, int opt)
{
    for (int i = 0; i < n; i++)
    {                   //���ն����Ʒ�ת
        if (i < rev[i]) //��ֻ֤��ǰ������ͺ��������������������ᱻ������
            swap(a[i], a[rev[i]]);
    }
    for (int step = 1; step < n; step <<= 1)  //for(int dep = 1; dep <= log2(n); ++dep){int step = 1 << dep;��depΪ��ǰ������stepΪ�ϲ�������Ԫ�ص�����
    {                                         //�ӵ�0�������⿪ʼ��ÿ����������кϲ�����ö�ٵ�ǰ�����ǰһ�룬������һ���ú����任���
        cd W_n = exp(cd(0, opt * PI / step)); //����˲����n�ε�λ����ͨ���۲���Է��ֵ�ǰ������λ����n�ͺϲ��������Ԫ����Ŀ��ͬ����Ԫ����ĿΪ2�Ĳ�������
        //Ҳ�ɣ�cd W_n = complex(cos(2.0 * PI / step), opt * sin(2.0 * PI / step));
        for (int j = 0; j < n; j += step << 1)
        {                  //��ÿһ���ڵ����ݽ��в���
            cd W_nk(1, 0); //����cd W_nk = complex(1, 0);����n�ε�λ����k�η�������������ʱ����ת���ӡ�ÿ�κϲ�ʱ����Ҫһ����ת���ӣ���ÿһ�����ת���Ӷ��Ǵ���η���ʼ�ģ��ҵ�kΪ0ʱ��ֵΪ1
            for (int k = j; k < j + step; k++)
            { //�����任��k�ĵ����ʹ������k��Ķ���ʽֵҲ��������ʵ�ֵ�
                cd x = a[k];
                cd y = W_nk * a[k + step];
                a[k] = x + y;
                a[k + step] = x - y; //ÿһ�εĺ���������������һ�α任���ϲ����Ľ����k�Ϳ��������������ĳɱ����Ӷ��������������൱�ڴ����˸����kֵ
                W_nk *= W_n;         //����ת���ӳ��Ըò����n�ε�λ�����൱��ÿһ��ѭ��������ת�����е�k����һ����������Ӧ��k����������֤��k��ִ��ʱ��ת����Ϊ��n�ε�λ����k�η�
            }
        }
    }

    if (opt == -1)
    { //�������任��IFFT�������и������n�����ѵ�λ���������䵹�����ɡ�����任ʱ����Ҫ���任�������1/n֮�⣬��任����n�ε�λ���Ĵ������Ǹ��ġ������÷����ɵ�����ʽ֤��
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

    scanf("%s%s", s1, s2);                //��������ʮ���������������Ƕ���ʽ��ϵ��������ÿһ������������������
    int l1 = strlen(s1), l2 = strlen(s2); //�洢ϵ����Ŀ���༴����ʽ������һ
    int bit = 1, s = 2;                   //bit�����ܴ�������ϵ������ı������������Կ���ϵ������������bit���ܴ��µ����ֵ�����Ƕ���ʽ����ߴ���
    for (bit = 1; (1 << bit) < l1 + l2 - 1; bit++)
    {            //ע�����Ϊn-1��m-1����������ʽ��ˣ�����Ĵ������Ϊn+m-2��������Ϊn��m����������ʽ�ĳ˻�������Ϊn+m-1
                 //����������˲�ͬ��nλ��mλ��������˽����λ�������Ե�n+m������FFT�㷨��δ������������ֻ��ʾ������Ŀ�Ķ���ʽ��ʽ�������ϵ������һ���ж��Խ�λ
        s <<= 1; //s�洢��������ʽ�˻�����ߴ�������ΪFFT���ϸ���εģ�����s��Ҫ��2���������ݡ���Ϊѭ����s�ͺ���bit������s�ĳ�ֵΪ2
    }
    for (int i = 0; i < l1; i++)
    { //��һ������ʽϵ������װ��a
        a[i] = (double)(s1[l1 - i - 1] - '0');
    }
    for (int i = 0; i < l2; i++)
    { //�ڶ�������ʽ��ϵ����������b
        b[i] = (double)(s2[l2 - i - 1] - '0');
    }
    getrev(bit);
    fft(a, s, 1);
    fft(b, s, 1);
    for (int i = 0; i < s; i++)
        a[i] *= b[i]; //��Ӧ���
    fft(a, s, -1);    //IFFT
    for (int i = 0; i < s; i++)
    {                                          //��ԭ��ʮ������
        output[i] += (int)(a[i].real() + 0.5); //ע�⾫�����
        output[i + 1] += output[i] / 10;
        output[i] %= 10;
    }
    int i;
    for (i = l1 + l2; !output[i] && i >= 0; i--)
        ; //ȥ��ǰ����
    if (i == -1)
        printf("0"); //���г���Ϊ0�����
    for (; i >= 0; i--)
    { //������ʮ������
        printf("%d", output[i]);
    }
    putchar('\n');
    return 0;

    /*
    int power1, power2; scanf("%d %d", &power1, &power2);
    for(int i=0; i <= n; ++i)scanf("%d", &a[i].r);
    for(int i=0; i <= m; ++i)scanf("%d", &b[i].r);
    s = 1; while(s <= n + m) s <<= 1, bit++;//ֱ�ӽ�s����������������ĳ��Ⱥͣ��������Ĳ���Ĭ����0�����룬����Ӱ����
    for (int i =0; i < s; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    fft(a, s, 1); fft(b, s, 1);
    for(int i =0; i <= s; ++i) a[i] = a[i] * b[i];
    fft(a, s, -1);
    for(int i = 0; i <= n + m; ++i){
        printf("%d ", (int)(a[i].r+0.5));
    }
    */
}