#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<list>

using namespace std;

/*
N�����У�Ҫ��·ʹ�������������м���ͨ���������м���·�ķ�Ϊŷ����þ���
����һ�λ�������޺ķѵ���ͨ������������x��y
����·�ķ�ΪB��x��y���˿�֮��ΪA��ҪʹA/B������
����·�ķѾ���С���޺ķ���·�����������˿�֮�;�����

Ҫʹ��·�ķѾ���С����Ȼ����С����������������ѡ���������һ����
��ô��ԭ����������һ���߾��γ���һ����������ԭ��������������·����ɾ��Ȩֵ���ı�
���Ǵ�С����������
ö�����㼴�ɣ��ؼ�����ԭ��С�����������������·���ϵ����Ȩֵ
ʹ��dfs+dp��⣬��MaxEdge[i][j]Ϊi�㵽j��·���ϵ�����
dfs��ÿ���±�����һ���ڵ�ʱ���������丸�ڵ�Ϊ�н�
��������Ѿ��������Ľڵ��뵱ǰ�ڵ��MaxEdge
*/

struct Point
{
    int x,y,pop;
};

#define dis(a,b) ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

struct Edge
{
    int from,to,len;
    bool operator<(const Edge &r) const
    {
        return len<r.len;
    }
    Edge(){}
    Edge(int _from,int _to,int _len):from(_from),to(_to),len(_len){}
};

vector<Point> ps;//���е�
vector<Edge> temp;//��������С������
vector<Edge> MST[1001];//��С������

int x[1001];
int N;
int MaxEdge[1001][1001];//MST�����������·���ϵ�����
bool vis[1001];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        x[i]=i;
        vis[i]=0;
        MST[i].clear();
        for(int j=1;j<=n;j++)
        {
            MaxEdge[i][j]=-1;
        }
    }
}

int find(int n)
{
    return x[n]==n?n:(x[n]=find(x[n]));
}

void dfs(int fa,int p,int val)//��ǰ�ڵ�ĸ��ڵ㣬��ǰ�ڵ㣬�͵�ǰ�ڵ㵽���ڵ�ıߵ�Ȩֵ
{
    int i;
    for(i=1;i<=N;i++)
    {
        if(vis[i])
        {
            MaxEdge[i][p]=MaxEdge[p][i]=max(MaxEdge[i][fa],val);
        }
    }
    vis[p]=1;
    for(i=0;i<MST[p].size();i++)
    {
        if(MST[p][i].to!=fa)
        {
            dfs(p,MST[p][i].to,MST[p][i].len);
        }
    }
}

int main()
{
    ps.reserve(1001);
    temp.reserve(1000001);
    int T,i,j,k,len,num,f1,f2;
    long long sum;
    double A,B,ans;
    Point p;
    Edge e;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        ps.clear();
        for(i=1;i<=N;i++)
        {
            scanf("%d%d%d",&p.x,&p.y,&p.pop);
            ps.push_back(p);
        }
        //��������佨��
        temp.clear();
        for(i=0;i<N;i++)
        {
            for(j=i+1;j<N;j++)
            {
                e.from=i+1,e.to=j+1;
                e.len=dis(ps[i],ps[j]);
                temp.push_back(e);
            }
        }
        sort(temp.begin(),temp.end());
        //����С������
        init(N);
        num=0,sum=0;
        len=temp.size();
        for(i=0;i<len&&num!=N-1;i++)
        {
            f1=find(temp[i].from);
            f2=find(temp[i].to);
            if(f1!=f2)
            {
                num++;
                x[f2]=f1;
                sum+=temp[i].len;
                //˫���
                MST[temp[i].from].push_back(Edge(temp[i].from,temp[i].to,temp[i].len));
                MST[temp[i].to].push_back(Edge(temp[i].to,temp[i].from,temp[i].len));
            }
        }
        //dfs+dp�����С�����������������·�������
        vis[1]=1;
        for(i=0;i<MST[1].size();i++)
        {
            dfs(1,MST[1][i].to,MST[1][i].len);
        }
        //��ʼö������
        ans=-1;
        for(i=1;i<=N;i++)
        {
            for(j=i+1;j<=N;j++)
            {
                A=ps[i-1].pop+ps[j-1].pop;
                B=sum-MaxEdge[i][j];
                ans=max(ans,A/B);
            }
        }
        printf("%.2f\n",ans);
        for(i=1;i<=N;i++)
        {
            for(j=0;j<MST[i].size();j++)
            {
                printf("%d %d %d\n",MST[i][j].from,MST[i][j].to,MST[i][j].len);
            }
        }
    }
    return 0;
}

