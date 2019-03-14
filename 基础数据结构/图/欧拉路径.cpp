#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

/*
打印欧拉路径或欧拉回路，欧拉路径是能能恰好走所有边一次的路径，若为回路称为欧拉回路
具有欧拉路径，且为回路则为欧拉图，否则为半欧拉图

判断是否为欧拉图或半欧拉图：
首先判断连通性，必须任意两点间联通，可通过并查集
然后统计每个点的度数，所有点度数都为偶数则为欧拉图，只有恰好2个奇数度的点则为半欧拉图
无向图类似，考虑入度和出度

建图，因为遍历过程中已经走过的边需要标记，而边是双向且多重的
这时候拿二维矩阵标记也行不通，可以给每一条边一个编号
将走过的边的编号记录到set里即可

打印路径时，若为回路，任意一点开始，否则需从奇数点开始
打印过程是一个dfs的过程，输出路径时应该回溯的时候在输出而不是一开始，输出的也是个逆序的路径
为什么要回溯时输出呢，首先应该知道搜索到某个点就输出肯定不对
比如“8”字型的路，假设从底部开始dfs，到了中间连接点，先往左下dfs，再往上面dfs，路径就是乱的
如果没有这种连接点，就算先输出也行
也就是说对于连接了多个圈的连接点，dfs的顺序若不对，输出结果就不对
但是回溯输出，无论怎么dfs，输出的都是对的，因为连接点后输出的路径
第一个点正为连接点，可以把之前输出的路径串起来，具体画图理解
*/

struct Node
{
    int to;
    int num;//编号
};

int n,m;
vector<Node> G[100001];
set<int> vis;

void out(int p)
{
    int i,len=G[p].size();
    for(i=0;i<len;i++)
    {
        if(vis.find(G[p][i].num)==vis.end())
        {
            vis.insert(G[p][i].num);
            out(G[p][i].to);
            //cout<<G[p][i].to<<' '<<p<<'\n';//打印边路径，注意要反过来
        }
    }
    cout<<p<<' ';//打印点路径
    //注意路径都要递归完再打印
}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,a,b,p;
    Node temp;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        temp.num=i;
        temp.to=b;
        G[a].push_back(temp);
        temp.to=a;
        G[b].push_back(temp);
    }
    p=1;
    for(i=1;i<=n;i++)
    {
        if(G[i].size()&1)
        {
            p=i;
            break;
        }
    }
    out(p);
    return 0;
}
/*
7 8
1 2
1 7
2 3
3 7
3 4
3 6
5 4
5 6
*/
