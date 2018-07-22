#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;

/*
POJ - 1182
食物链 
*/
inline int trans(int a)
{
	if(a==0)
	{
		return 0;	
	}
	else
	{
		return (a%2+1);
	}
} 

int x[50001]; 
int rel[50001];//0为同类，1为吃父，2为被父吃

int findX(int n)
{
	if(n!=x[n])
	{
		int tem=findX(x[n]);
		rel[n]=(rel[n]+rel[x[n]])%3;//此处仍需深刻理解，是有方向的 
		return x[n]=tem;
	}
	return n;
}

int main()
{
	int N,K,i,j,tem,t,a,b,p1,p2,num=0,r;
	scanf("%d %d",&N,&K);
	for(i=1;i<=N;i++)
	{
		x[i]=i;	
	}
	memset(rel,0,sizeof(rel));
	while(K--)
	{
		scanf("%d",&t);
		scanf("%d %d",&a,&b);
		if(a>N||b>N)
		{
			num++;
			continue;
		}
		if(t==1)//合并同类，肯定不会错 
		{
			p1=findX(a);
			p2=findX(b);
			if(p1==p2)
			{
				if(rel[a]!=rel[b])//已经合并过，但是a和b不是同类 
				{
					num++;
					continue;
				}
			}
			else//重新合并 
			{
				x[p2]=p1;
				rel[p2]=(trans(rel[b])+rel[a])%3;
			}
		}
		else//增加或判断关系 
		{
			p1=findX(a);
			p2=findX(b);
			if(p1==p2)//已合并，判断关系对错 
			{
				if( ( rel[a]+trans(rel[b]) )%3!=1 )//非捕食关系 
				{
					num++;
				}
			}
			else//未合并，添加捕食关系 
			{
				x[p2]=p1;
				rel[p2]=(trans(rel[b])+rel[a]+2)%3;
			}
		}
	}
	cout<<num;
	return 0; 
}









