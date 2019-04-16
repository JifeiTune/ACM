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
一棵节点为n的无向树，若在某个节点布置一个士兵，则与该点相连的点都能被看到（包括自己）
每个点布置士兵花费不一样
现希望所有点都能被看到，问最少花费
类似放置街灯，边改成了点，所不同的是，考虑到以i为根的子树时
即使i的子节点都不放，i也不一定要放，因为可以让i的父节点放
所以可分为以下几类：
1.i不放，并且整个子树都被看到
2.i不放，并且i的子树都被看到（i能否看到不管）
3.i放，并且整个子树都被看到
具体转移看代码
*/

int dp[1501][3];//以i为根的子树所有点都被看到，i取与不取时的最小花费
int val[1501];
vector<int> Tree[1501];
int n;

void dfs(int now,int fa)
{
    int len,n1,n2,to,i,j,t0=0x3f3f3f3f,t1=0,t2=0,temp;
    bool leaf=1;
    len=Tree[now].size();
    for(i=0;i<len;i++)
    {
        to=Tree[now][i];
        if(to!=fa)//防止搜回去
        {
			leaf=0;
            dfs(to,now);
        }
    }

    for(i=0;i<len;i++)//枚举必须要放的子节点
    {
        n1=Tree[now][i];
        temp=0;
        if(n1!=fa)
		{
			for(j=0;j<len;j++)
	        {
	            n2=Tree[now][j];
	            if(n2!=fa)
	            {
	                if(n2!=n1)//可放可不放的子节点
	                {
	                    temp+=min(dp[n2][0],dp[n2][2]);
	                }
	                else
	                {
	                    temp+=dp[n2][2];
	                }

	            }
	        }
			t0=min(t0,temp);
		}
    }
    for(i=0;i<len;i++)
    {
        n1=Tree[now][i];
        if(n1!=fa)
        {
            t1+=min(dp[n1][0],dp[n1][2]);
            t2+=min(dp[n1][0],min(dp[n1][1],dp[n1][2]));
        }
    }
    if(leaf)
    {
        dp[now][0]=dp[now][2]=val[now];
        dp[now][1]=0;
    }
    else
    {
        t2+=val[now];//本节点放
        dp[now][0]=t0,dp[now][1]=t1,dp[now][2]=t2;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    memset(dp,0x3f,sizeof(dp));//起初置为极大值
    int i,j,fa,MAX=0,p,to,len,from,ans,num,root;
    bool fir=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&from);
        scanf("%d%d",&val[from],&num);
        if(fir)
        {
            fir=0;
            root=from;
        }
        while(num--)
        {
            scanf("%d",&to);
            Tree[from].push_back(to);
            Tree[to].push_back(from);
        }
    }
    dfs(root,-1);
    ans=min(dp[root][0],dp[root][2]);
    printf("%d",ans);
    return 0;
}
