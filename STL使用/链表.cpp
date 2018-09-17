#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<list>
#include<set>

using namespace std;
/*
2018百度之星初赛A 1002
有许多队列，需要支持双端插入，双端访问和连接
list里自带连接函数splice，可以将b连到a的任意位置，并将b清空
*/ 
list<int> ls[150001];

int main()
{
	int N,Q,i,j,k,ans,op,a,b,c;
	while(~scanf("%d%d",&N,&Q))
	{
		while(Q--)
		{
			scanf("%d",&op);
			if(op==1)//加元素 
			{
				scanf("%d%d%d",&a,&b,&c);
				if(b==0)//加前面 
				{
					ls[a].push_front(c);
				}
				else//加后面 
				{
					ls[a].push_back(c);
				}
			}
			else if(op==2)//询问元素并删除 
			{
				scanf("%d%d",&a,&b);
				if(ls[a].empty())
				{
					printf("-1\n");
				}
				else
				{
					if(b==0)//问前面 
					{
						printf("%d\n",ls[a].front());
						ls[a].pop_front();
					}
					else//问后面 
					{
						printf("%d\n",ls[a].back());
						ls[a].pop_back();
					}
				}
			}
			else//连接并清空 
			{
				scanf("%d%d%d",&a,&b,&c);
				if(c==1)//逆序接 
				{
					ls[b].reverse();
				}
				ls[a].splice(ls[a].end(),ls[b],ls[b].begin(),ls[b].end());
			}
		}
		for(i=1;i<=N;i++)
		{
			ls[i].clear();
		}
	}
	return 0; 
}


