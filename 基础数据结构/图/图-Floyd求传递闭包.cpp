#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<list>
#include<cmath>
#include<stack>
#include<regex>

using namespace std;

/*
传递闭包，即求出每个点所能达到的所有点
Floyd求传递闭包，A->B，B->C，则A->C，枚举中间点B，类比求最短路，略加修改

有奇数个珍珠，现在知道其中若干对的重量关系，即其中哪个更重，问有多少个珍珠不可能具有中间重量
不可能有中间重量，即通过所给关系，能判断有超过总数/2个珍珠比它重，或比它轻

将珍珠作为节点，A->B表示B比A重，则求好传递闭包后，统计每个点能到达的节点数，为比之重的珍珠数
统计能到达该点的节点数，为比之轻的节点数，与总数/2比较即可
*/

int G[101][101];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,n,m,a,b,ans=0;
    memset(G,0,sizeof(G));//起初设为任意2点不可达
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        G[b][a]=1;//b到a添加一条边
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(G[i][k]&&G[k][j])
                {
                    G[i][j]=1;
                }
            }
        }
    }
    m=n/2;
    for(k=1;k<=n;k++)//统计每个几点对应行和列的和
    {
        a=0,b=0;
        for(j=1;j<=n;j++)//行，即比k重的
        {
            a+=G[k][j];
        }
        for(i=1;i<=n;i++)//列，即比k轻的
        {
            b+=G[i][k];
        }
        if(a>m||b>m)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
