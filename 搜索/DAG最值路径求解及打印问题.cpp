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
#include<queue>

using namespace std;

/*
有向无环图，求最长路或最短路，并输出路径
本题求最长路，长度为点权和

采用记忆化搜索，vis[i]记录从i点出发的最长路长度
然后枚举起点（也可先统计入度为0的节点作为起点）进行dfs
该点出发的路径中，再取最长，记录下一个节点，用来输出路径 
*/ 

int x[201];//点权 
vector<int> G[201];
int dis[201];//从某个点出发最大值
int nextP[201];//某点出发最长路径，下一点
int MAX,p;//最长距离和该起始点

int dfs(int from)
{
    if(dis[from]!=-1)//记忆化搜索！
    {
        return dis[from];
    }
    int i,j,len,ans,temp;
    ans=0;
    len=G[from].size();
    for(i=0;i<len;i++)
    {
        temp=dfs(G[from][i]);
        if(temp>ans)
        {
            ans=temp;
            nextP[from]=G[from][i];//更新本点出发最长距离下一点
        }
    }
    dis[from]=x[from]+ans;
    if(dis[from]>MAX)
    {
        MAX=dis[from];//更新总的最长距离 
        p=from;//更新总的最长距离起点 
    }
    return dis[from];
}


int main()
{
    ios::sync_with_stdio(false);
    memset(dis,-1,sizeof(dis));
    int n,i,j,a,b;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
        nextP[i]=i;
    }
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
        {
            break;
        }
        G[a].push_back(b);
    }
    MAX=0;
    for(i=1;i<=n;i++)
    {
        dfs(i);
    }
    while(nextP[p]!=p)
    {
        cout<<p<<'-';
        p=nextP[p];
    }
    cout<<p<<'\n';
    cout<<MAX;
    return 0;
}
