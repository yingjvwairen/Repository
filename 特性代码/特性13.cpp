#include<stdio.h>
#define N 1024
long func1(char *s)
{
	int i,t; 
	long ans =0;
	for(i=0;s[i];++i)//δ��ֵ���ַ��ͱ����ĳ�ֵȫΪ'\0'��ASCII����Ϊ0
	{
		if(s[i]>='0'&&s[i]<='9')
		t=s[i]-'0';//ע���ַ��ͱ������ַ����ڴ�ռ��е�ʵ�ʴ�����ʽ��ʵ����ASCII���ֵ����һ���������Կ��Խ������� 
		if(s[i]>='A'&&s[i]<='Z')
		t=s[i]-'A'+10;//A����10�������ü�ȥA��ASCII��ֵ�ټ�ʮ�ķ������Եõ�ԭ��
		if(s[i]>='a'&&s[i]<='z')
		t=s[i]-'a'+10;//ʵ����ʮ�������е���ĸ��ASCII������Ļ�Ҳ���ֻ�ܵ���f 
		ans=ans*16+t;
	}
	return ans;
 } 
long func2(int m,int n)
{	
	float ans=0,num=0;
	while(m)//�������m/10����һ��ѭ�� 
		ans=float(ans+m%10)/n,++num,m/=10;
	for(int i=0;i!=num;++i)//�������int i=1����һ��ѭ�� 
		ans=ans*8;
	return ans;
}
int main()
{
	int m,n;
	char s[N];//�ַ������ַ��������ϵķ�ʽ�����ַ�������
	printf("���������\n");
	scanf("%d",&n); 
	if(n==16) 
	{
	printf("��������ֵ\n");
	scanf("%s",s);//ע��˴�Ҫ��%s����һ���ַ�������������%c����һ���ַ�
	m=func1(s),printf("%d",m);
	return 0x0UL;//U��L�ֱ�����ֵ�ĺ�׺��U��u������ǰ��ֵ���޷����ͣ�unsigned��L��l������ǰ��ֵ�ǳ����ͣ�long����0x�Ǵ��������ֵ��16���Ƶ�ǰ׺ 
				//�����return����ֹ��������֮�ã�˳����ֹ�˿���������Ķ������ִ�� 
	}
	printf("��������ֵ\n");
	scanf("%d",&m);
	m=func2(m,n),printf("%d",m);
}
