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
#include<ctime>

using namespace std;

/*
������������꣬ÿ����ļ��𣬶���Ϊ��֮���·��������������ҵĵ�ĸ���
��ÿ���ȼ��ĵ����Ŀ
���������άǰ׺�ͣ���ĳ�������е㣬ֵ�ͼ�һ�����ͳ��ÿ�������½Ǿ����ڵĺ�
�������귶Χ�󣬶�ά�����ˣ��ֲ�����鷳����ɢ������ô�죿
��ʵ�������ת����һά�ģ��������½ǣ�Ҳ����������������С�ڵ���ʱ��������ҲС�ڵ���
����������㰴�������������У���������ͬʱ����������������
Ȼ����ɨ�裬��ôɨ�赽��ǰ��ʱ������֮ǰ�ĵ��У�������С�ڵ������ĵ�ĸ�������
����ͳ��С�ڡ�������ĵ�ĸ��������������״������
���������Ѿ��ź���һ�߶�һ�߼��㼴�� 
*/

#define lowbit(n) (n&(-n))

int num;//ʵ�ʸ���
int x[100010];
int level[100010];

void add(int p,int n)
{
    while(p<=num)
    {
        x[p]+=n;
        p+=lowbit(p);
    }
}

int sum(int p)
{
    int ans=0;
    while(p>0)
    {
        ans+=x[p];
        p-=lowbit(p);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,op,a,b,i,c;
    num=32010;
    memset(x,0,sizeof(x));
    memset(level,0,sizeof(level));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        ++a;//�±����Ϊ0����1
        ++level[sum(a)];
        add(a,1);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",level[i]);
    }
    return 0;
}




