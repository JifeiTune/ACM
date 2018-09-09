#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<queue>
#include<vector>
/*
邀请n个人，每个人只有在已邀请人数大于等于L且小于等于R才愿意去
问最多能请到几个人
每次选L满足条件且R最小的（将R更大的留到后面还可能有机会
当前已选ans个人时，下一步只在所有L<=ans的人中选，使用优先队列动态添加 
*/
using namespace std;

struct Node
{
	int L,R,i;
	bool operator<(const Node &r) const//注意，为了从大到小排序，将<意义变反 
	{
		if(R==r.R)
		{
			return L>r.L;	
		}
		return R>r.R;
	}	
}x[100001]; 

bool vis[100001];

bool CMP(Node x,Node y)
{
	return x.L<y.L;
}

vector<int> man;

int main()
{
	int i,j,ans,n,tem,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			x[i].i=i;
			scanf("%d",&x[i].L);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x[i].R);
		}
		sort(x+1,x+1+n,CMP);
		priority_queue<Node> pq;
		i=1;
		ans=0;
		man.clear();
		while(1)
		{
			for(;i<=n;i++)
			{
				if(x[i].L==ans)
				{
					pq.push(x[i]);
				}
				else
				{
					break;
				}
			}
			if(pq.empty())//接下来都不可能了 
			{
				break;
			}
			else
			{
				while(!pq.empty())
				{
					if(pq.top().R>=ans)
					{
						man.push_back(pq.top().i);
						ans++;
						pq.pop();
						break;
					}
					pq.pop();
				}
			}
		}
		memset(vis,0,sizeof(bool)*(n+1));
		printf("%d\n",ans);
		for(i=1;i<=ans;i++)
		{
			printf("%d ",man[i-1]);
			vis[man[i-1]]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				printf("%d ",i);//无效的统一最后输出 
			}
		}
		putchar('\n');
	}
	return 0; 
}
/*
1 2 3 4 5 6 7 8
4 1 3 2 2 1 0 3
5 3 6 4 2 1 7 6
*/

