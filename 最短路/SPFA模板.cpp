#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<list>

using namespace std;

/*
这次用前向星建的图 
*/ 

struct Edge
{
    int to,dis;
    //相比于普通边，多加了一个变量next，表示同起点下一条边的下标，若无为-1
    int next;
};

#define MAXM 1000010//最多边数
#define MAXN 100010//最多点数

int Enum;//边的数目
int Pnum;//点的数目
Edge G[MAXM+1];//按边数开
int head[MAXN+1];
int dis[MAXN+1];
int InNum[MAXN+1];//入队次数
bool InQ[MAXN+1];
queue<int> q;

inline void addE(int from,int to,int dis)
{
    ++Enum;
    G[Enum].to=to;
    G[Enum].dis=dis;

    G[Enum].next=head[from];//指向上一次添加的边
    head[from]=Enum;//更新起始边
}

bool SPFA(int beg)
{
    int from,to,i;
    dis[beg]=0;
    ++InNum[beg];
    InQ[beg]=1;
    q.push(beg);
    while(!q.empty())
    {
        from=q.front();
        q.pop();
        InQ[from]=0;//不在队列中了
        for(i=head[from];i!=-1;i=G[i].next)//遍历出边
        {
            to=G[i].to;
            if(dis[from]+G[i].dis<dis[to])//可成功松弛
            {
                dis[to]=dis[from]+G[i].dis;
                if(!InQ[to])
                {
                    q.push(to);//成功松弛，且当前不再队列的点入队
                    InQ[to]=1;
                    ++InNum[to];
                }
                if(InNum[to]>Pnum)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    //初始化
    Enum=0;
    int i,j,a,b,c,m;
    scanf("%d%d",&Pnum,&m);
    memset(head,-1,sizeof(int)*(Pnum+1));
    memset(InNum,0,sizeof(int)*(Pnum+1));
    memset(dis,0x3f,sizeof(int)*(Pnum+1));
    memset(InQ,0,sizeof(bool)*(Pnum+1));
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a!=b)
        {
            addE(a,b,c);
            addE(b,a,c);
        }
    }
    SPFA(1);
    cout<<dis[Pnum];
    return 0;
}
