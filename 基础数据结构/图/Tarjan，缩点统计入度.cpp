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
���A->B��B->C����ô����Aһ�����ϣ�B��C���ܹ���õ�
���ڸ���һ�鴫�ݹ�ϵ����������ٸ����������ϣ�����ʹ���������˶���һ��

һ��ǿ��ͨ�����ڣ�һ���˵õ��������˶��ܵõ�
����ת���ʣ������е�ǿ��ͨ������������Ϊ0�ĵ�ĸ���
������Tarjan�����ͬһ��ǿ��ͨ����Ⱦɫ��һ�ּ���

Ҫע����ǣ�ͳ�����ʱ����Ҫȷ�����㴦�ڲ�ͬǿ��ͨ������ 
*/

vector<int> G[1001];
int MIN[1001];
int NUM[1001];
bool InS[1001];
int color[1001];
int Cnum;
int num;//��ǰ������
int n;//�ڵ���

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
        if(NUM[G[p][i]]==-1)//��һ����δ������
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
        mp[color[i]]=0;//���
    }
    for(i=1;i<=n;i++)
    {
        len=G[i].size();
        for(j=0;j<len;j++)
        {
            if(color[i]!=color[G[i][j]])//����ͬһ�������ż���
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
