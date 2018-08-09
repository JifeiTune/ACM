#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<map> 

using namespace std;

int x[100001];
int num[100001];//代表元所在集合元素个数 

int find(int n)
{
	if(x[n]!=n)
	{
		return x[n]=find(x[n]);
	}
	return n;
} 

int main()
{
	int T,a,b,i,j,n,tem,f1,f2,c,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			x[i]=i;
			num[i]=1;//起初只有自己 
		}
		for(i=1;i<n;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(c==0)
			{
				f1=find(a);
				f2=find(b);
				x[f2]=f1;
				num[f1]+=num[f2];//加上 
			}
		}
		ans=num[find(1)];
		for(i=2;i<=n;i++)
		{
			ans^=num[find(i)];
		}
		printf("%d\n",ans);
	}
	return 0; 
}


