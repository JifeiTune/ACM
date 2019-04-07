#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

/*
给定一棵有根树，每次询问a、b两点祖孙关系
判断a是b祖先，还是b是a祖先，还是无祖孙关系

无需求LCA，判断dfs时间序即可
在对树进行dfs时，记录每个点的进入时间be[i]和离开时间ed[i] 
可以发现，祖先必定是最先进入，最后出的点
即祖先的时间序将子孙的时间序夹在中间 
*/ 

vector<int> G[40001];
int be[40001]={0};//最小时间序
int ed[40001]={0};//最大时间序
int Time;

void dfs(int n,int fa)//当前节点编、当前节点父节点
{
    int len=G[n].size(),i,to;
    ++Time;
    be[n]=Time;
    for(i=0;i<len;i++)
    {
        to=G[n][i];
        if(to!=fa)
        {
            dfs(to,n);
        }
    }
    ++Time;
    ed[n]=Time;
}

int main()
{
    int n,m,i,j,beg,a,b,q;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if(b==-1)
        {
            beg=a;
        }
        else
        {
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
    Time=0;
    dfs(beg,beg);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        if(be[a]<be[b]&&ed[a]>ed[b])//a是b祖先 
        {
            printf("1\n");
        }
        else if(be[b]<be[a]&&ed[b]>ed[a])//b是a祖先 
        {
            printf("2\n");
        }
        else//平辈关系 
        {
            printf("0\n");
        }
    }
	return 0;
}
