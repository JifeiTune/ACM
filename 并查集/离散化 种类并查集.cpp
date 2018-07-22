#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<map> 
/*
POJ - 1733
Parity game
*/
using namespace std;

map<int,int> mp;
int size=0;
inline int ins(int x)
{
	if(mp.find(x)==mp.end())//不存在 
	{
		return mp[x]=size++;//映射到数组下标
	}
	return mp[x];
} 

int x[10001],y[10001];

int find(int n)
{
	if(x[n]!=n)
	{
		int f=find(x[n]);
		y[n]=(y[n]+y[x[n]])%2;
		return x[n]=f;
	}
	return n;
}

int main()
{
	int a,b,i,j,n,tem,len,m,num=0,f1,f2;
	char ch[5];
	scanf("%d %d",&len,&m);
	memset(y,0,sizeof(y));
	len=len<10000?len:10000;//特别注意！这个len是未离散化前的长度，要是直接用它初始化，很可能越界！ 
	for(i=0;i<len;i++)
	{
		x[i]=i;
	}
	
	for(i=0;i<m;i++)
	{
		num++;
		scanf("%d %d %s",&a,&b,ch);
		//先不考虑范围 
		a=ins(a-1);
		b=ins(b);
		f1=find(a);
		f2=find(b);
		if(ch[0]=='e')//同类
		{
			if(f1==f2)//已合并，判断对错 
			{
				if(y[a]==y[b])
				{
					
				}
				else
				{
					printf("%d",--num);
					return 0;
				}
			}
			else//未合并，则合并 
			{
				x[f2]=x[f1];
				y[f2]=(y[a]+y[b])%2; 
			}
		} 
		else
		{
			if(f1==f2)//已合并，判断对错 
			{
				if(y[a]!=y[b])
				{
					
				}
				else
				{
					printf("%d",--num);
					return 0;
				}
			}
			else//未合并，则合并 
			{
				x[f2]=x[f1];
				y[f2]=(y[a]+y[b]+1)%2; 
			}
		}
	}
	printf("%d",num);
	return 0; 
}


