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
�����ǰ���ǽ���ͼ 
*/ 

struct Edge
{
    int to,dis;
    //�������ͨ�ߣ������һ������next����ʾͬ�����һ���ߵ��±꣬����Ϊ-1
    int next;
};

#define MAXM 1000010//������
#define MAXN 100010//������

int Enum;//�ߵ���Ŀ
int Pnum;//�����Ŀ
Edge G[MAXM+1];//��������
int head[MAXN+1];
int dis[MAXN+1];
int InNum[MAXN+1];//��Ӵ���
bool InQ[MAXN+1];
queue<int> q;

inline void addE(int from,int to,int dis)
{
    ++Enum;
    G[Enum].to=to;
    G[Enum].dis=dis;

    G[Enum].next=head[from];//ָ����һ����ӵı�
    head[from]=Enum;//������ʼ��
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
        InQ[from]=0;//���ڶ�������
        for(i=head[from];i!=-1;i=G[i].next)//��������
        {
            to=G[i].to;
            if(dis[from]+G[i].dis<dis[to])//�ɳɹ��ɳ�
            {
                dis[to]=dis[from]+G[i].dis;
                if(!InQ[to])
                {
                    q.push(to);//�ɹ��ɳڣ��ҵ�ǰ���ٶ��еĵ����
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
    //��ʼ��
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
