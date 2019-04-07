#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

/*
有根树上任意两点间的最短距离，就是各自到二者的最近公共祖先距离之和
如果是二叉树，对树进行中序遍历，记录时间序
显然，任意两点的所有公共祖先的时间序都夹在两点之间
如果不是二叉树呢，每次递归完一棵子树，回溯时都再记录一次当前节点即可
第一次遍历到一个节点时也要记录
最后能记录多少个点呢？每个度都会使得一个点被记录一次，根节点有一个虚拟的入度
所以记录的数组开点数的2倍就足够
当然夹在中间的并非都是公共祖先，其中深度最小的（最靠近根）的就是最近公共祖先
*/
#define MAXN 100001

vector<int> G[MAXN];
int dep[MAXN];//点的深度，设根深度为0
int ord[MAXN];//中序遍历时每个点第一次出现的时间序
int MIN[2*MAXN][20];//RMQ使用，MIN[i][0]表示时间序为i的点的深度
int Time;

void init(int len)//初始化数组后别忘了init！
{
	int i,j;
	for(j=1;(1<<j)<=len;j++)
	{
		for(i=1;i+(1<<j)-1<=len;i++)//注意范围，右坐标未超出数组下标才有计算的意义
		{
			MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);//划分成长度相等的两个子区间
		}
	}
}

int answer(int i,int j)
{
	if(i>j)
	{
		swap(i,j);
	}
	int dis=j-i+1,k=0;
	while((1<<(++k))<=dis);
    --k;
	return min(MIN[i][k],MIN[j-(1<<k)+1][k]);
}

void dfs(int n,int d,int fa)//当前节点、当前深度、当前节点的父节点
{
    int len=G[n].size(),i,to;
    ++Time;
    ord[n]=Time;//记录第一次遍历时的时间序
    dep[n]=d;//记录深度
    MIN[Time][0]=d;
    for(i=0;i<len;i++)
    {
        to=G[n][i];
        if(to!=fa)//别搜回去了
        {
            dfs(to,d+1,n);
            ++Time;
            MIN[Time][0]=d;//每次回溯时都再记录一次本节点
        }
    }
}

int main()
{
    int n,q,i,j,a,b,temp;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    Time=0;
    dfs(1,0,-1);
    init(Time);

    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        temp=answer(ord[a],ord[b]);
        printf("%d\n",dep[a]+dep[b]-2*temp);
    }
	return 0;
}
