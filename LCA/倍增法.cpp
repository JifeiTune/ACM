#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

/*
求树上任意两点距离 
*/ 

#define MAXN 100001
#define EXP 20//不小于log2(MAXN)

struct Edge
{
    int to,dis;
    Edge(){}
    Edge(int _to,int _dis):to(_to),dis(_dis){}
};

vector<Edge> Tree[MAXN];
int dep[MAXN];//点的深度
int dis[MAXN];//点到根的距离
int up[MAXN][20];//up[i][j]表示i点出发，向上跳2^j所到的点，0就表示没有

void dfs(int n,int fa)//当前节点，当前节点父节点
{
    int len=Tree[n].size(),i,j;
    Edge to;
    //遍历到了当前节点，就表示已经遍历完了根到该点路径上的点，所以可以直接更新当前点的up
    for(j=1;(1<<j)<=dep[n];j++)//能跳多少取决于其深度
    {
        //当前点跳2^j等于先跳2^(j-1)，再跳2^(j-1)
        up[n][j]=up[up[n][j-1]][j-1];
    }

    for(i=0;i<len;i++)
    {
        to=Tree[n][i];
        if(to.to!=fa)//别搜回去了
        {
            dep[to.to]=dep[n]+1;
            dis[to.to]=dis[n]+to.dis;
			up[to.to][0]=n;//先更新深度和距离，以及up边界
            dfs(to.to,n);
        }
    }
}

int LCA(int a,int b)//求a与b的最近公共祖先
{
    int h,i,j;
    h=dep[a]-dep[b];//为了让a和b处于同一深度所要跳跃的点
    if(dep[a]<dep[b])
    {
        swap(a,b);//让a为深度更大的点
        h=-h;
    }
    i=0;
    while(h>0)//h的二进制上为1的位权都是要跳跃的
    {
        if(h&1)
        {
            a=up[a][i];//当前位权为2^i
        }
		++i;
		h>>=1;//右移1位
    }
    if(a==b)
    {
        return a;//已经为同一点了，说明2点原来在同一条根出发的路径上
    }
    /*
    此时说明原来2点在不同的根出发的路径上，一起向上跳，正好跳到同一点即为LCA
    我们不知道还要向上跳多少，所以只能贪心地构造所跳步数的二进制数
    从高位开始尝试，如果跳该位权正好不会调至相同，就跳
    */
    for(j=EXP-1;j>=0;j--)
    {
        if(up[a][j]!=up[b][j])//不等就跳
        {
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];//还差一步
}

int main()
{
	freopen("dis0.in","r",stdin);
    memset(up,0,sizeof(up));
    int n,q,a,b,c,i,j;
    scanf("%d%d",&n,&q);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Tree[a].push_back(Edge(b,c));
        Tree[b].push_back(Edge(a,c));
    }
    dep[1]=0;
    dis[1]=0;
    dfs(1,-1);//假设以1为根

    while(q--)
    {
        scanf("%d%d",&a,&b);
        c=LCA(a,b);
        printf("%d\n",dis[a]+dis[b]-2*dis[c]);
    }
    return 0;
}
