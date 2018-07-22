#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
POJ - 1703
Find them, Catch them 
*/
using namespace std; 

int x[100001];//存确定的一个个集合 
int y[100001];//存与父节点关系 ，奇数表示对立 

int find(int n)
{
	int t,len=0;
	if(n!=x[n])
	{
		t=find(x[n]);//找到最终代表元 
		y[n]+=y[x[n]];//根据“父节点与代表元关系”，“本节点与父节点关系”更新与代表元的关系 
		y[n]%=2;
		return x[n]=t;//最后更新代表元
	} 
	return n;
}

int main()
{
	int T,a,b,i,j,n,tem,N,M,t1,t2;
	char c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);//N个罪犯，M个语句
		for(i=1;i<=N;i++)
		{
			x[i]=i;
		}
		memset(y,0,sizeof(int)*(N+1));
		while(M--)
		{
			scanf(" %c",&c);
			scanf("%d %d",&a,&b);
			if(c=='A')//回答 
			{
				if(find(a)!=find(b))//不属于同一个集合，不确定 
				{
					printf("Not sure yet.\n");
				}
				else
				{
					if( (y[a]-y[b])&1==1 )
					{
						printf("In different gangs.\n");
					}
					else
					{
						printf("In the same gang.\n");
					}
				}
			}
			else
			{
				t1=find(a);
				t2=find(b);
				x[t2]=t1; 
				if(y[a]==y[b])//更新与父节点的关系 
				{
					y[t2]=1;
				}
				else
				{
					y[t2]=0;
				}
			}
		} 		
	}  
	return 0; 
}


