#include<bits/stdc++.h>
using namespace std;

/*
һ����ȫ����ͼ�����1e5���������ֱߣ��ֱ�Ϊa��b
��Ϊa�Ľ���������5e5�����������ǳ�Ϊb��
�ʽڵ�1��n�����·����

��Ȼ����ȫͼ�����Ա�Ȼ����2��䶼��·�������ҳ��ȷ�a��b
���˵1��n�ı��ǽ�С�ģ���ֱ��������ɣ���Ϊ��������С��
����ֻҪ��1��n�ı�ʱ�ϴ��ʱ���ſ���������·��n�ܸ�С
���ң��ߵ�·�У��϶�ֻ�߸�С�ıߣ�������ֱ�Ӵ�1��n
Ҳ����˵��ֻ����ͼ�б߳���С�ıߣ���һ��bfs������n��ľ��룬��ֱ��1��n�������Сֵ����
���ǽ�С�߿����ǳ�Ϊb��Ҳ����δ�����ģ����зǳ��ǳ��࣬��Ȼ������ȥ������
��������bfs���������ĵ㲻���ٱ������������ǿ��Դӵ�ĽǶȳ���
��һ��set��¼��ǰδ�������ĵ㣬���Ҵӵ�ǰ�㳢������set�еĵ㣨���ڱ��Ƿ�Ϊ��С�ߣ����ݸ����ıߺ�a��b��С�жϼ��ɣ�
������ĵ㼰ʱɾ�����������ӶȾͲ���̫�� 
*/ 

int n,m,a,b;

struct Edge
{
    int from,to;//ע����from<=to
    Edge(){}
    Edge(int _from,int _to):from(_from),to(_to){}
    bool operator<(const Edge &r) const
    {
        if(from==r.from)
        {
            return to<r.to;
        }
        return from<r.from;
    }
};

struct Node
{
    int now,dep;
    Node(){}
    Node(int _now,int _dep):now(_now),dep(_dep){}
};

set<Edge> egs;
set<int> notVis;
queue<Node> que;

inline bool MINEDGE(int from,int to)
{
    if(from>to) swap(from,to);
    if(a<=b&&egs.find(Edge(from,to))!=egs.end() || b<=a&&egs.find(Edge(from,to))==egs.end() )
    {
        return 1;
    }
    return 0;
}

int main()
{
    long long ans1,ans2;
    int i,from,to,MIN,now;
    Edge eg;
    Node nd;
    while(~scanf("%d%d%d%d",&n,&m,&a,&b))
    {
        egs.clear();
        notVis.clear();
        while(!que.empty())
        {
            que.pop();
        }
        ans1=ans2=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&from,&to);
            if(from>to) swap(from,to);
            egs.insert(Edge(from,to));
        }
        for(i=1;i<=n;i++)
        {
            notVis.insert(i);
        }
        eg=Edge(1,n);
        MIN=min(a,b);
        if((egs.find(eg)!=egs.end()&&a<=b) || (egs.find(eg)==egs.end()&&b<=a))
        {
            printf("%d\n",MIN);
        }
        else
        {
            ans1=max(a,b);
            //��MIN��bfs��n
            que.push(Node(1,0));
            notVis.erase(1);
            bool toN=0;//�Ƿ��ܵ�n
            while(!que.empty())
            {
                nd=que.front();
                que.pop();
                now=nd.now;
                if(now==n)
                {
                    ans2=nd.dep*(long long)MIN;
                    printf("%lld\n",min(ans1,ans2));
                    toN=1;
                    break;
                }
                //��now������δ�����㣬��Ϊ��С��
                set<int>::iterator it=notVis.begin();
                while(it!=notVis.end())
                {
                    to=(*it);
                    if(MINEDGE(now,to))
                    {
                        it=notVis.erase(it);
                        que.push(Node(to,nd.dep+1));
                    }
                    else
                    {
                        ++it;
                    }
                }

            }
            if(!toN)
            {
                printf("%lld\n",ans1);
            }
        }
    }
    return 0;
}

