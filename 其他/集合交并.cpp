#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<list>
#include<cmath>
#include<stack>
using namespace std;

/*
��N����50���������ϣ�ÿ������Ԫ�ش�1e4���д�2000��ѯ��
ÿ�����ѯ�ʵ��������ϣ�����Ԫ�ظ����벢��Ԫ�ص���

ֱ����setģ�⵱Ȼ�ᳬʱ���󽻼��Ͳ����ܼ򵥣��ؼ���Ҫ����������Ԫ������
�Ƚ�ÿ������Ԫ��ȥ�أ��ٴӴ�С����Ȼ����ȹ鲢����ĺϲ�����
�����൱����2���������У�ÿ��ȡ��ͷ�Ƚϣ�����ȣ���ȡ�������ڽ����Ͳ���
�����ȣ�ȡ��Сֵ�����ڲ���
ע�������ܻ���һ��ȡ��һ����ûȡ�꣬ʣ�µ�Ԫ�����ڲ��� 
*/ 

vector<int> x[51];
int ele[10001];

double getN(int a,int b)//��ȥ���ڲ��ظ�
{
    vector<int> &v1=x[a],&v2=x[b];
    int i,j,len1=v1.size(),len2=v2.size(),inte=0,uni=0;
    i=j=0;
    while(i<len1&&j<len2)
    {
        if(v1[i]<v2[j])
        {
            ++uni,++i;
        }
        else if(v1[i]>v2[j])
        {
			++uni,++j;
        }
        else
        {
            ++uni;
            ++inte;//���߹��У����ڽ���
			++i,++j;
        }
    }
    //ע������ı�©�ˣ�ʣ�µ��Ƕ��е�
    while(i<len1)
    {
        ++uni,++i;
    }
    while(j<len2)
    {
        ++uni,++j;
    }
    return (double)inte/uni;
}

int main()
{
    int n,m,len,i,k,temp,a,b,last,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&len);
        for(j=1;j<=len;j++)
        {
            scanf("%d",&ele[j]);
        }
        sort(ele+1,ele+1+len);
        last=ele[1]-1;
        for(j=1;j<=len;j++)
        {
            if(ele[j]!=last)//ȥ��
            {
                last=ele[j];
                x[i].push_back(ele[j]);
            }
        }
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        printf("%.2f%\n",getN(a,b)*100.0);
    }
    return 0;
}





