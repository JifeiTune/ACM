#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<list>

using namespace std;

/*
��һ��N����������������������Ϊ����·���ϱ�Ȩ��Сֵ����������С�����ƣ�
��������ѡ��һ���㣬ʹ�ôӸõ�������������е������֮������������֮��

ʹ������������㷨�����ߴӴ�С���������ܱ�֤Ŀǰѡ�ı߱�Ȼ��֮ǰ��С
ÿ���ϲ�������ʱ���������Ŀ����ĸ���Ϊ����ĸ���Ȩֵ��С
*/

typedef long long LL;

int x[200010];
int num[200010];//ÿ�������Ľڵ���
LL value[200010];//ÿ��������ǰ������֮��

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        x[i]=i;
        value[i]=0;
        num[i]=1;
    }
}

int find(int n)
{
    return x[n]==n?n:(x[n]=find(x[n]));
}

struct Edge
{
    int from,to,val;
    bool operator<(const Edge &r) const
    {
        return val>r.val;
    }
};

vector<Edge> egs;


int main()
{
    egs.reserve(200010);
    int N,i,j,k,f1,f2;
    LL ans,t1,t2;
    Edge e;
    while(~scanf("%d",&N))
    {
        init(N);
        egs.clear();
        for(i=1;i<N;i++)
        {
            scanf("%d%d%d",&e.from,&e.to,&e.val);
            egs.push_back(e);
        }
        sort(egs.begin(),egs.end());
        for(i=0;i<N-1;i++)
        {
            f1=find(egs[i].from);
            f2=find(egs[i].to);
            t1=value[f1]+(LL)egs[i].val*num[f2];//��f1Ϊ���ϲ�����Ȩֵ��
            t2=value[f2]+(LL)egs[i].val*num[f1];
            if(t1>=t2)
            {
                x[f2]=f1;
                num[f1]+=num[f2];
                value[f1]=t1;
                ans=t1;
            }
            else
            {
                x[f1]=f2;
                num[f2]+=num[f1];
                value[f2]=t2;
                ans=t2;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

