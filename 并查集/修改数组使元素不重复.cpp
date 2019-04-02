#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

/*
����һ�����飬Ҫ�����·�����֮�ĳ�һ��û���ظ�Ԫ�ص����飺
������ɨ��Ԫ�أ������ǰԪ����֮ǰ�ù����Ͳ��ϼ�һ֪��û�г��ֹ�

������Ȼ���ˣ���Ҫ�����������ǣ������ǰԪ���ظ��ˣ���Ҫ�������ٶ��ٲ��ܲ��ظ�
���ò��鼯������ʹ�õ�Ԫ�ط���ͬһ���ţ�ά��ÿ��Ԫ�������ŵ����ֵ+1
�´���Ԫ��������Ԫ���ظ�ʱ��ֱ����Ϊ�Ǹ�ֵ���ϲ�����¸�ֵ
�����º��ֵ��������������ٸ���һ��
*/

int x[1000001];
int MAX[1000001];//ÿ��Ԫ�����������ֵ

int Find(int n)
{
    return x[n]=(x[n]==n?n:Find(x[n]));
}

int main()
{
    ios::sync_with_stdio(false);
    int len,i,f1,f2,temp,m;
    cin>>len;
    for(i=1;i<=1000001;i++)
    {
        x[i]=i;
        MAX[i]=i;
    }
    for(i=1;i<=len;i++)
    {
        cin>>temp;
        f1=Find(temp);
        m=MAX[f1];
        cout<<m<<' ';
        x[m]=f1;//�ϲ���m�϶��Ƕ�����
        f2=Find(m+1);
        x[f1]=f2;
    }
    return 0;
}
