#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<list>
#include<cstdlib>
#include<cmath>
using namespace std;

/*
n个人，其中m对人可相互转账，各需缴纳一定比例手续费
现在a要最终转给b一百元，可以间接转，问最少花费多少

将边权设为单位货币转账后还剩多少
则边的连接用乘而不是加，求一条最长路即可
求最长路，修改一下dij松弛操作即可
*/

struct Edge//既表示边，又表示当前某节点到起始点的最短距离
{
    int to;
    double dis;//dis表示还剩多少
    bool operator<(const Edge& r) const
    {
        return dis<r.dis;
    }
};

#define inf 0;
double dis[2001];
bool vis[2001];
vector<Edge> x[2001];
priority_queue<Edge> pq;

int main()
{
    ios::sync_with_stdio(false);
    memset(vis,0,sizeof(vis));
    int n,m,i,j,k,a,b,c,len;
    Edge eg,temp;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        dis[i]=0;
    }
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        eg.to=b,eg.dis=1-0.01*c;
        x[a].push_back(eg);
        eg.to=a;
        x[b].push_back(eg);
    }
    cin>>a>>b;
    eg.to=a,eg.dis=1;
    pq.push(eg);
    while(!pq.empty())
    {
        eg=pq.top();
        pq.pop();
        if(!vis[eg.to])
        {
            if(eg.to==b)
            {
                printf("%.8f",100/eg.dis);
                return 0;
            }
            vis[eg.to]=1;
            dis[eg.to]=eg.dis;
            len=x[eg.to].size();
            for(i=0;i<len;i++)
            {
                if(!vis[x[eg.to][i].to]&&dis[eg.to]*x[eg.to][i].dis>dis[x[eg.to][i].to])//注意是大于，且是乘
                {
                    dis[x[eg.to][i].to]=dis[eg.to]*x[eg.to][i].dis;
                    temp.to=x[eg.to][i].to;
                    temp.dis=dis[x[eg.to][i].to];
                    pq.push(temp);
                }
            }
        }
    }
    return 0;
}
