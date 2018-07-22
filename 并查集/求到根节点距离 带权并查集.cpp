#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
UVALive - 3027
Corporative Network 
*/
using namespace std;

int main()
{
	int T,i,j,a,b,n,num,x[20001],t;
	unsigned long long dis[20001],tem;
	char c;
	scanf("%d",&T);
	while(T--)
	{
		memset(dis,0,sizeof(dis));//每个点到父节点初始距离为0 
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			x[i]=i;//父节点初始为自己 
		}
		while(scanf(" %c",&c)&&c!='O')
		{
			if(c=='E')
			{
				scanf("%d",&a);
				tem=0;
				t=a;
				while(x[t]!=t)//寻找b的根节点 
				{
					tem+=dis[t];
					t=x[t];
				}
				x[a]=t;//路径压缩 
				dis[a]=tem;
				
				printf("%llu\n",dis[a]);	
			}
			else
			{
				scanf("%d %d",&a,&b);//b作为a的父节点
				dis[a]=abs(a-b)%1000;
				x[a]=b;
			}
		} 
	}
	return 0; 
}









