#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

/*
����һ���и�����ÿ��ѯ��a��b���������ϵ
�ж�a��b���ȣ�����b��a���ȣ������������ϵ

������LCA���ж�dfsʱ���򼴿�
�ڶ�������dfsʱ����¼ÿ����Ľ���ʱ��be[i]���뿪ʱ��ed[i] 
���Է��֣����ȱض������Ƚ��룬�����ĵ�
�����ȵ�ʱ���������ʱ��������м� 
*/ 

vector<int> G[40001];
int be[40001]={0};//��Сʱ����
int ed[40001]={0};//���ʱ����
int Time;

void dfs(int n,int fa)//��ǰ�ڵ�ࡢ��ǰ�ڵ㸸�ڵ�
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
        if(be[a]<be[b]&&ed[a]>ed[b])//a��b���� 
        {
            printf("1\n");
        }
        else if(be[b]<be[a]&&ed[b]>ed[a])//b��a���� 
        {
            printf("2\n");
        }
        else//ƽ����ϵ 
        {
            printf("0\n");
        }
    }
	return 0;
}
