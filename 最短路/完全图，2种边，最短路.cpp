#include<bits/stdc++.h>
using namespace std;

/*
一个完全无向图（点达1e5），有两种边，分别长为a和b
长为a的将给定（达5e5），其他都是长为b的
问节点1到n的最短路长度

既然是完全图，所以必然任意2点间都有路径，并且长度非a即b
如果说1到n的边是较小的，那直接输出即可，因为不可能再小了
所以只要当1到n的边时较大的时，才可能走其他路到n能更小
并且，走的路中，肯定只走更小的边，否则不如直接从1到n
也就是说，只留下图中边长更小的边，来一遍bfs，到了n后的距离，和直接1到n，输出较小值即可
但是较小边可能是长为b，也就是未给定的，会有非常非常多，当然不可能去存下来
想想我们bfs，遍历过的点不会再遍历，所以我们可以从点的角度出发
用一个set记录当前未遍历到的点，并且从当前点尝试走向set中的点（至于边是否为较小边，根据给定的边和a、b大小判断即可）
遍历后的点及时删除，这样复杂度就不会太高 
*/ 

int n,m,a,b;

struct Edge
{
    int from,to;//注意让from<=to
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
            //按MIN来bfs到n
            que.push(Node(1,0));
            notVis.erase(1);
            bool toN=0;//是否能到n
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
                //从now出发到未遍历点，且为最小边
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

