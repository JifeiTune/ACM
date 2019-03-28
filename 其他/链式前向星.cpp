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
链式前向星就是邻接表的一种实现
存图，邻接矩阵就免了，vector实现邻接表虽然很方便，但因为事先不知道某点出发边的条数
在过程中可能会不断重新申请内存复制数据，并且最后会比实际使用大

有没有什么几乎没有空间和时间浪费的数据结构来存图呢？
很容易能想到用边集数组，按照题目数据范围开，就不会有时间和空间的浪费
可是边集数组中，边是乱的，而我们使用的时候经常都需要遍历以某点为起点的所有边
如果我们能知道某点出发的第一条边，通过这条边又能知道下一条边……即表达出某点出发的边的链式关系，就能很方便地遍历了
设head[n]为以n为起点的，第一条边的下标（若无，置为-1）
每个边有一个next变量，指向同点出发下一条边的下标（若无，置为-1）
建好图后怎么遍历知道了，那如何建图呢？
首先head中元素当然要置为-1，因为现在还没有边
那添加一条边时，这条边的next指向上一条边的下标，这个起点的head就换成新的这条边的下标
即建图时时逆序的，后添加的靠近链头，先遍历

其实head就相当于链表的头指针，next也顾名思义，-1相当于NULL
*/

struct Edge
{
    int to,dis;
    //相比于普通边，多加了一个变量next，表示同起点下一条边的下标，若无为-1
    int next;
};

#define MAXN 10000//最多点数 
#define MAXM 100000//最多边数
int Enum;//边的数目
Edge G[MAXM+1];//按边数开
int head[MAXN+1];//按点数开 

inline void addE(int from,int to,int dis)
{
    ++Enum;
    G[Enum].to=to;
    G[Enum].dis=dis;

    G[Enum].next=head[from];//指向上一次添加的边
    head[from]=Enum;//更新起始边
}

int main()
{
    //初始化
    Enum=0;
    memset(head,-1,sizeof(head));
    int i,j;

    addE(1,2,10);
    addE(1,3,20);
    addE(2,5,30);
    addE(3,10,40);
    addE(10,10,100);
    for(i=1;i<=10;i++)
    {
        for(j=head[i];j!=-1;j=G[j].next)//从其实边开始，遍历下一条边，直到-1即无边
        {
            cout<<i<<' '<<G[j].to<<' '<<G[j].dis<<'\n';
        }
    }
    return 0;
}
