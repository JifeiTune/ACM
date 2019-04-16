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
n���ڵ�Ķ�������ÿ������һ��Ȩֵ
�����ȥһЩ�ߣ�ʹ��ʣ�µ�������m����
��ʣ�µ�����Ȩ�����Ϊ����

����ÿ����Ҷ�ڵ�i��������֮Ϊ��������j����
��ô��j���߿��Դӵ����������ıߣ��Լ�����������������ȡ
��3�������ȫ����ߺ�������ȡ��ȫ���ұߺ�������ȡ����ȡ
��ȡʱ�����Ѿ�ȡ��2���ߵ�����£�Ҫö��������ȡ���٣�������ȡ����
dp���
*/

struct Node
{
    int to,dis;
    Node(){}
    Node(int _to,int _dis):to(_to),dis(_dis){}
};

vector<Node> Tree[101];
int dp[101][101];//�ڵ�iΪ��������������j���߱��������ƻ��
int n,m;

void dfs(int now,int fa)//��ǰ�ڵ���丸�ڵ�
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
    if(L!=-1)//��Ҷ�ӽڵ�
    {
        for(i=1;i<=m;i++)//ö��Ҫ�����ı���
        {
            t1=dp[L][i-1]+dL;//ֻ��������
            t2=dp[R][i-1]+dR;//ֻ��������
            t3=0;//��������������
            if(i>=2)
            {
                for(j=0;j<=i-2;j++)//ö�������������ı���
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




