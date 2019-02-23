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
�����޻�ͼ�����·�����·�������·��
�������·������Ϊ��Ȩ��

���ü��仯������vis[i]��¼��i��������·����
Ȼ��ö����㣨Ҳ����ͳ�����Ϊ0�Ľڵ���Ϊ��㣩����dfs
�õ������·���У���ȡ�����¼��һ���ڵ㣬�������·�� 
*/ 

int x[201];//��Ȩ 
vector<int> G[201];
int dis[201];//��ĳ����������ֵ
int nextP[201];//ĳ������·������һ��
int MAX,p;//�����͸���ʼ��

int dfs(int from)
{
    if(dis[from]!=-1)//���仯������
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
            nextP[from]=G[from][i];//���±�������������һ��
        }
    }
    dis[from]=x[from]+ans;
    if(dis[from]>MAX)
    {
        MAX=dis[from];//�����ܵ������ 
        p=from;//�����ܵ��������� 
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
