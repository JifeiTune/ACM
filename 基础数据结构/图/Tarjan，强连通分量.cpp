#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<stack>
/*
Tarjan算法可用于求强连通分量，即极大强连通子图
强连通指图中任意两点都相互可达
将每个强连通分量缩成一个点，构成一个有向无环图
在简化的新图上能很方便地处理传递型关系，传向一个点等价于传向该点代表的所有点 

假设B与A相互可达，C也与A相互可达，那么B与C也相互可达
当对图进行dfs时，记录某个点的搜索序num，以及与该点双向连通的点中，最小的搜索序root
怎么判断双向连通以更新root呢，dfs的过程中用栈记录遍历到的节点（当然并非只会往里加，见后面）
栈内保存的是可以到达当前点的元素，若从该点出发的点，又在栈内，则说明相互可达，这时更新root即可 
如果dfs结束的时候，root[B]==root[A]，说明B与A相互可达，处于同一个强连通分量中 
而当对一个强连通分量进行dfs，假设起始点为A
那么dfs结束时必然遍历了其中的所有点，并且搜到某点i后还能继续搜回A ，因为图中任意两点都相互可达
所以其中所有点的root都等于root[A] 
当dfs结束，若A==B，说明从该点出发无法到达之前搜索到的点，也就是以该点为入口
搜完了一个强连通分量（注意可能只包含该点），此时整个强连通分量的点都在栈中，不断弹出
直到元素的root==num，即为入口点 

实际实现：
设num[]表示某个点被搜索的次序（起初设为-1表示未被搜索）
root[]为与该点连通且最先被搜到的点的被搜索次序（搜到某点时先置为自己的次序）
从从图中每一点出发进行dfs（防止图不连通，确保遍历每一个点）
搜到一个点就入栈，并递归搜索与之连通且未搜过（num[i]==-1）的点 
回溯到这个点时，根据所有与之连通的点（该点可达，且在栈内）的root更新自己的root，保留最小值
若此时root[i]==num[i]表示遍历完成一个强连通分量
出栈直到最后出栈元素为这个点，所有出栈元素即为一个强连通分量中所有点 

可给每个点设color值为该连强通分量的代表元，代表元从1开始hash
*/
using namespace std;

#define MAXN (int)(1e5+1) 

int num[MAXN];//某个点被搜索的次序
int root[MAXN];//与该点连通且最先被搜到的点的被搜索次序
bool InS[MAXN];//是否在栈中 
vector<int> G[MAXN];//图 
int ord;//当前次序 
stack<int> st;
int NUM; 

void dfs(int x)//从x节点开始dfs
{
	num[x]=++ord;
	root[x]=num[x];//起初置为自己
	InS[x]=1;
	st.push(x);//入栈 
	int i,tem,n;
	for(i=0;i<G[x].size();i++)
	{
		if(num[G[x][i]]==-1)//相邻节点未被访问 
		{
			dfs(G[x][i]);
			//root[x]=root[x]<=root[G[x][i]]?root[x]:root[G[x][i]];//更新root为较小值	
		}
		if(InS[G[x][i]])
		{
			root[x]=root[x]<=root[G[x][i]]?root[x]:root[G[x][i]];
		}
	}
	if(root[x]==num[x])//回溯
	{
		n=0;
		do
		{
			n++;
			tem=st.top(),st.pop();
			InS[tem]=0;
			//tem为该强连通分量中一点，此处可染色 
			//printf("%d ",tem); 
		}while(tem!=x);
		if(n>=2)
		{
			NUM++;
		}
		//putchar('\n');
	} 
}

void Tarjan(int n)
{
	NUM=0;
	memset(num,-1,sizeof(num));//所有节点置为未访问
	memset(InS,0,sizeof(InS));
	ord=0;
	for(int i=1;i<=n;i++)//假设节点编号从1开始 
	{
		if(num[i]==-1)//i点还未被搜索 
		{
			dfs(i);	
		} 
	}
}

int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
	}
	Tarjan(n);
	printf("%d",NUM);
	return 0; 
}











