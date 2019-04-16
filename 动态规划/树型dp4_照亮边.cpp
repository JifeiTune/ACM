#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

/*
一棵节点为n的无向树，若在某个节点布置一个士兵，则与该点相连的边都能被看到
现希望所有边都能被看到，问最少布置几个士兵

放置街灯的简化版
dp[i][2]表示以i为根的子树，在选和不选i时，其上的边都能看到时的最小选点数
那么若选i，则子节点选和不选都不会影响i到子节点的边
若不选i，则所有子节点都必须选才能看到所有i到子节点的边
*/

int dp[1501][2];
vector<int> Tree[1501];
int n;

void dfs(int now,int fa)
{
    int len,to,i,t0=0,t1=0;
    len=Tree[now].size();
    for(i=0;i<len;i++)
    {
        to=Tree[now][i];
        if(to!=fa)//防止搜回去
        {
            dfs(to,now);
            t0+=dp[to][1];//本节点不放，那么所有子节点都必须放
            t1+=min(dp[to][0],dp[to][1]);//本节点放，那么子节点放与不放都OK
        }
    }
    dp[now][0]=t0;
    dp[now][1]=t1+1;//加上本节点放的
}

int main()
{
    ios::sync_with_stdio(false);
    memset(dp,0x3f,sizeof(dp));//起初置为极大值
    int i,j,fa,MAX=0,p,to,len,from,ans,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&from,&num);
        while(num--)
        {
            scanf("%d",&to);
            Tree[from].push_back(to);
            Tree[to].push_back(from);
        }
    }
    dfs(0,-1);//以0为根
    printf("%d",min(dp[0][0],dp[0][1]));
    return 0;
}
