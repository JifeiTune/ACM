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
N个城市，要修路使得任意两座城市间联通，两座城市间修路耗费为欧几里得距离
现有一次机会可以无耗费地联通任意两座城市x、y
设修路耗费为B，x与y的人口之和为A，要使A/B尽量大
即修路耗费尽量小，无耗费修路的两座城市人口之和尽量大

要使修路耗费尽量小，显然是最小生成树，现在能任选两点免费连一条边
那么在原生成树上连一条边就形成了一个环，则在原生成树，两点间的路径上删除权值最大的边
就是次小生成树问题
枚举两点即可，关键是求原最小生成树上任意两点间路径上的最大权值
使用dfs+dp求解，设MaxEdge[i][j]为i点到j点路径上的最大边
dfs中每当新遍历到一个节点时，可以以其父节点为中介
求出所有已经遍历过的节点与当前节点的MaxEdge
*/

struct Point
{
    int x,y,pop;
};

#define dis(a,b) ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

struct Edge
{
    int from,to,len;
    bool operator<(const Edge &r) const
    {
        return len<r.len;
    }
    Edge(){}
    Edge(int _from,int _to,int _len):from(_from),to(_to),len(_len){}
};

vector<Point> ps;//所有点
vector<Edge> temp;//用来求最小生成树
vector<Edge> MST[1001];//最小生成树

int x[1001];
int N;
int MaxEdge[1001][1001];//MST上任意两点间路径上的最大边
bool vis[1001];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        x[i]=i;
        vis[i]=0;
        MST[i].clear();
        for(int j=1;j<=n;j++)
        {
            MaxEdge[i][j]=-1;
        }
    }
}

int find(int n)
{
    return x[n]==n?n:(x[n]=find(x[n]));
}

void dfs(int fa,int p,int val)//当前节点的父节点，当前节点，和当前节点到父节点的边的权值
{
    int i;
    for(i=1;i<=N;i++)
    {
        if(vis[i])
        {
            MaxEdge[i][p]=MaxEdge[p][i]=max(MaxEdge[i][fa],val);
        }
    }
    vis[p]=1;
    for(i=0;i<MST[p].size();i++)
    {
        if(MST[p][i].to!=fa)
        {
            dfs(p,MST[p][i].to,MST[p][i].len);
        }
    }
}

int main()
{
    ps.reserve(1001);
    temp.reserve(1000001);
    int T,i,j,k,len,num,f1,f2;
    long long sum;
    double A,B,ans;
    Point p;
    Edge e;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        ps.clear();
        for(i=1;i<=N;i++)
        {
            scanf("%d%d%d",&p.x,&p.y,&p.pop);
            ps.push_back(p);
        }
        //任意两点间建边
        temp.clear();
        for(i=0;i<N;i++)
        {
            for(j=i+1;j<N;j++)
            {
                e.from=i+1,e.to=j+1;
                e.len=dis(ps[i],ps[j]);
                temp.push_back(e);
            }
        }
        sort(temp.begin(),temp.end());
        //求最小生成树
        init(N);
        num=0,sum=0;
        len=temp.size();
        for(i=0;i<len&&num!=N-1;i++)
        {
            f1=find(temp[i].from);
            f2=find(temp[i].to);
            if(f1!=f2)
            {
                num++;
                x[f2]=f1;
                sum+=temp[i].len;
                //双向边
                MST[temp[i].from].push_back(Edge(temp[i].from,temp[i].to,temp[i].len));
                MST[temp[i].to].push_back(Edge(temp[i].to,temp[i].from,temp[i].len));
            }
        }
        //dfs+dp求解最小生成树上任意两点间路径的最长边
        vis[1]=1;
        for(i=0;i<MST[1].size();i++)
        {
            dfs(1,MST[1][i].to,MST[1][i].len);
        }
        //开始枚举两点
        ans=-1;
        for(i=1;i<=N;i++)
        {
            for(j=i+1;j<=N;j++)
            {
                A=ps[i-1].pop+ps[j-1].pop;
                B=sum-MaxEdge[i][j];
                ans=max(ans,A/B);
            }
        }
        printf("%.2f\n",ans);
        for(i=1;i<=N;i++)
        {
            for(j=0;j<MST[i].size();j++)
            {
                printf("%d %d %d\n",MST[i][j].from,MST[i][j].to,MST[i][j].len);
            }
        }
    }
    return 0;
}

