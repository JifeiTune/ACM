#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<ctime>
#include<list>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

/*
如果A->B，B->C，那么给了A一份资料，B和C都能共享得到
现在给定一组传递关系，问起初至少给多少人资料，才能使最终所有人都有一份

一个强连通分量内，一个人得到，所有人都能得到
问题转换问，将所有的强连通分量缩点后，入度为0的点的个数
缩点用Tarjan，最后将同一个强连通分量染色成一种即可

要注意的是，统计入度时，先要确保两点处于不同强连通分量里 
*/

vector<int> G[1001];
int MIN[1001];
int NUM[1001];
bool InS[1001];
int color[1001];
int Cnum;
int num;//当前搜索序
int n;//节点数

stack<int> st;

void dfs(int p)
{
    int i,len,temp,ans;
    NUM[p]=++num;
    MIN[p]=NUM[p];
    st.push(p);
    InS[p]=1;
    len=G[p].size();
    for(i=0;i<len;i++)
    {
        if(NUM[G[p][i]]==-1)//下一个点未遍历过
        {
            dfs(G[p][i]);
        }
        if(InS[G[p][i]])
        {
            MIN[p]=min(MIN[p],MIN[G[p][i]]);
        }

    }
    if(MIN[p]==NUM[p])
    {
        ++Cnum;
        do
        {
            temp=st.top();
            st.pop();
            InS[temp]=0;
            color[temp]=Cnum;
        }
        while(temp!=p);
    }
}

void Tarjan()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(NUM[i]==-1)
        {
            dfs(i);
        }
    }
}

map<int,int> mp;

int main()
{
    ios::sync_with_stdio(false);
    int i,j,temp,len,ans=0;
    memset(InS,0,sizeof(InS));
    memset(NUM,-1,sizeof(NUM));
    num=0,Cnum=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>temp;
        while(temp!=0)
        {
            G[i].push_back(temp);
            cin>>temp;
        }
    }
    Tarjan();
    for(i=1;i<=n;i++)
    {
        mp[color[i]]=0;//入度
    }
    for(i=1;i<=n;i++)
    {
        len=G[i].size();
        for(j=0;j<len;j++)
        {
            if(color[i]!=color[G[i][j]])//不在同一个分量才计数
            {
                ++mp[color[G[i][j]]];
            }
        }
    }
    map<int,int>::iterator it=mp.begin();
    while(it!=mp.end())
    {
        if(it->second==0)
        {
            ans++;
        }
        ++it;
    }
    cout<<ans;
    return 0;
}
