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
给一棵N个点的数，树上两点间容量为两点路径上边权最小值（流量受最小边限制）
现在让你选择一个点，使得从该点出发到其他所有点的容量之和最大，输出容量之和

使用最大生成树算法，将边从大到小排序，这样能保证目前选的边必然比之前的小
每当合并两棵树时，计算以哪棵树的根作为总体的根，权值最小
*/

typedef long long LL;

int x[200010];
int num[200010];//每棵子树的节点数
LL value[200010];//每棵子树当前的容量之和

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
            t1=value[f1]+(LL)egs[i].val*num[f2];//以f1为根合并的新权值和
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

