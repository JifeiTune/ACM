#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

/*
����������������� 
*/ 

#define MAXN 100001
#define EXP 20//��С��log2(MAXN)

struct Edge
{
    int to,dis;
    Edge(){}
    Edge(int _to,int _dis):to(_to),dis(_dis){}
};

vector<Edge> Tree[MAXN];
int dep[MAXN];//������
int dis[MAXN];//�㵽���ľ���
int up[MAXN][20];//up[i][j]��ʾi�������������2^j�����ĵ㣬0�ͱ�ʾû��

void dfs(int n,int fa)//��ǰ�ڵ㣬��ǰ�ڵ㸸�ڵ�
{
    int len=Tree[n].size(),i,j;
    Edge to;
    //�������˵�ǰ�ڵ㣬�ͱ�ʾ�Ѿ��������˸����õ�·���ϵĵ㣬���Կ���ֱ�Ӹ��µ�ǰ���up
    for(j=1;(1<<j)<=dep[n];j++)//��������ȡ���������
    {
        //��ǰ����2^j��������2^(j-1)������2^(j-1)
        up[n][j]=up[up[n][j-1]][j-1];
    }

    for(i=0;i<len;i++)
    {
        to=Tree[n][i];
        if(to.to!=fa)//���ѻ�ȥ��
        {
            dep[to.to]=dep[n]+1;
            dis[to.to]=dis[n]+to.dis;
			up[to.to][0]=n;//�ȸ�����Ⱥ;��룬�Լ�up�߽�
            dfs(to.to,n);
        }
    }
}

int LCA(int a,int b)//��a��b�������������
{
    int h,i,j;
    h=dep[a]-dep[b];//Ϊ����a��b����ͬһ�����Ҫ��Ծ�ĵ�
    if(dep[a]<dep[b])
    {
        swap(a,b);//��aΪ��ȸ���ĵ�
        h=-h;
    }
    i=0;
    while(h>0)//h�Ķ�������Ϊ1��λȨ����Ҫ��Ծ��
    {
        if(h&1)
        {
            a=up[a][i];//��ǰλȨΪ2^i
        }
		++i;
		h>>=1;//����1λ
    }
    if(a==b)
    {
        return a;//�Ѿ�Ϊͬһ���ˣ�˵��2��ԭ����ͬһ����������·����
    }
    /*
    ��ʱ˵��ԭ��2���ڲ�ͬ�ĸ�������·���ϣ�һ������������������ͬһ�㼴ΪLCA
    ���ǲ�֪����Ҫ���������٣�����ֻ��̰�ĵع������������Ķ�������
    �Ӹ�λ��ʼ���ԣ��������λȨ���ò��������ͬ������
    */
    for(j=EXP-1;j>=0;j--)
    {
        if(up[a][j]!=up[b][j])//���Ⱦ���
        {
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];//����һ��
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
    dfs(1,-1);//������1Ϊ��

    while(q--)
    {
        scanf("%d%d",&a,&b);
        c=LCA(a,b);
        printf("%d\n",dis[a]+dis[b]-2*dis[c]);
    }
    return 0;
}
