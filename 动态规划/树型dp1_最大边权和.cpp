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
n个节点的二叉树，每条边有一个权值
现需除去一些边，使得剩下的树保留m条边
问剩下的数边权和最大为多少

对于每个非叶节点i，假设以之为根保留了j条边
那么这j条边可以从到左右子树的边，以及左右子树保留的来取
分3种情况，全从左边和左子树取，全从右边和右子树取，都取
都取时，在已经取了2条边的情况下，要枚举左子树取多少，右子树取多少
dp解决
*/

struct Node
{
    int to,dis;
    Node(){}
    Node(int _to,int _dis):to(_to),dis(_dis){}
};

vector<Node> Tree[101];
int dp[101][101];//节点i为根的子树，保留j根边保留的最多苹果
int n,m;

void dfs(int now,int fa)//当前节点和其父节点
{
    int to,i,j,len=Tree[now].size(),L=-1,R=-1,dis,dL,dR,t1,t2,t3;
    for(i=0;i<len;i++)
    {
        to=Tree[now][i].to;
        dis=Tree[now][i].dis;
        if(to!=fa)
        {
            if(L==-1) L=to,dL=dis;
            else R=to,dR=dis;
            dfs(to,now);
        }
    }
    if(L!=-1)//非叶子节点
    {
        for(i=1;i<=m;i++)//枚举要保留的边数
        {
            t1=dp[L][i-1]+dL;//只留左子树
            t2=dp[R][i-1]+dR;//只留右子树
            t3=0;//左右子树都保留
            if(i>=2)
            {
                for(j=0;j<=i-2;j++)//枚举左子树保留的边数
                {
                    t3=max(t3,dp[L][j]+dp[R][i-2-j]);
                }
				t3+=dL+dR;
            }

            dp[now][i]=max(t1,t2);
            dp[now][i]=max(dp[now][i],t3);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    memset(dp,0,sizeof(dp));
    int i,from,to,dis;
    scanf("%d%d",&n,&m);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&from,&to,&dis);
        Tree[from].push_back(Node(to,dis));
        Tree[to].push_back(Node(from,dis));
    }
    dfs(1,-1);
    printf("%d",dp[1][m]);
    return 0;
}




