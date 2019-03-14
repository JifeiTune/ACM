#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<ctime>
#include<list>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
/*
偏序关系：集合内元素部分可相互比较
全序关系：集合内元素任意2个都可相互比较
拓扑排序就是将给定的偏序关系转换为一组全序关系

简单点理解，暂将关系定义为先后关系，A->B，说明A比B先
要实现拓扑排序，原图需为DAG，否则有环就无法比较环内谁先谁后
判断是否有环，可以先以入度为0的点开始进行拓扑排序，最后输出点数小于总点数则有环
或者在dfs的过程中直接判断
拓扑排序2种算法：
一、取点删边：
1.每次取入度为0的点，这代表没有任何一个点比它先，所以可以输出
2.然后删除从它出发的所有边，即消除已输出点的影响，然后重复1
二、dfs：
和输出欧拉回路一样，都是在dfs结束时再输出当前节点，最后输出为逆序，可用栈记录并转换为正序
为什么要搜完再输出呢？因为基于这个事实：该点必定比从该点出发所能搜到的点先
所以先不管该点出发搜到的所有点内部的顺序，该点和从该点出发所能搜到的点的相对顺序肯定是对的
所以保证好这个顺序，而从该点出发所能搜到的点内部的顺序，则在递归搜索的时候解决，最后总的顺序就是对的
因为是递归结束才输出，所以是更先的在后面，用栈记录转换一下顺序即可

而为什么dfs时先输出是错的呢？因为先输出就代表认为该点比当前未搜索到的点都更先
这显然是错误的，因为可能有其他还未搜到的点指向这个点，应该比它先输出

此种算法没必要从入度为0的点开始，至于判断环，环的特征就是搜了一遍又会回来
所以增加一个点的状态，共有：未遍历、遍历完成、正在遍历3中，如果从一点出发的某点处于正在遍历状态
说明就有环

以下算法为dfs算法，假设无环
*/
vector<int> G[101];
stack<int> ans;
bool vis[101];

void dfs(int p)
{
    int i,len;
    vis[p]=1;
    len=G[p].size();
    for(i=0;i<len;i++)
    {
        if(!vis[G[p][i]])
        {
            dfs(G[p][i]);
        }
    }
    ans.push(p);//递归结束时记录
}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,temp,len,n,m,f1,f2;
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>temp;
        while(temp!=0)
        {
            G[i].push_back(temp);
            cin>>temp;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])//递归入度为0的点
        {
            dfs(i);
        }
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<' ';
        ans.pop();
    }
    return 0;
}
