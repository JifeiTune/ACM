#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<map>
/*
n个数，求最长连续子段（求出端点），子段内不同数字个数不超过k
从起点开始，然后每次向右扩充，当扩充至不符合条件时就左端点右移至符合条件 
原来这就叫尺取法？？？…… 

用了map，其实用hash数组更快的 
*/
using namespace std;

int x[500001];
map<int,int> mp;//某个数字当前取到个数 

int main()
{
	int n,k,L,R,i,j,num,ansL,ansR;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	ansL=1,ansR=1;
	L=1;
	num=0;//当前不同元素个数 
	for(i=1;i<=n;i++)//右端点移动 
	{
		if(mp.find(x[i])==mp.end())//没找到，需加入 
		{
			if(num==k)//当前已经装不下了，需要更新 
			{
				if(R-L>ansR-ansL)//更新最长区间 
				{
					ansL=L,ansR=R;
				}
				R=i;
				for(j=L;j<R;j++)
				{
					mp[x[j]]--;
					if(mp[x[j]]==0)//成功删完一个 
					{
						mp.erase(x[j]);
						L=j+1;
						break;
					}
				}
				mp[x[i]]=1;//加入新的
				
			}
			else//装得下 
			{
				mp[x[i]]=1;
				num++;
				R=i; 
			}
		}
		else
		{
			mp[x[i]]++;//个数加1
			R=i; 
		}
	}
	if(R-L>ansR-ansL)
	{
		ansL=L,ansR=R;
	}
	printf("%d %d\n",ansL,ansR); 
	return 0; 
}









