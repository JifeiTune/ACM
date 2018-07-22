#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;
/*
UVA - 11235
Frequent values
*/
#define num 100000//数组最大长度
#define LOG ((int)log2(num))//数组长度以2为底的对数
 
//假设数组下标从1开始
int x[num+1];//每一段的长度 
int MAX[num+1][LOG+1];
int len;//数组实际使用长度
int LEFT[num+1];//每一段的左端点
int RIGHT[num+1];//每一段的右端点
int number[num+1];//每一个元素对应的段号 

void init()//初始化数组后别忘了init！ 
{
	int f=(int)log2(len),i,j;
	for(i=1;i<=len;i++)
	{
		MAX[i][0]=x[i];
	}
	for(j=1;j<=f;j++)
	{
		for(i=1;i+(1<<j)-1<=len;i++)//注意范围，右坐标未超出数组下标才有计算的意义 
		{
			MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]); 
		}
	}
}

int answer(int i,int j)//求i到j最值 
{
	int k=(int)log2(j-i+1);
	return max(MAX[i][k],MAX[j-(1<<k)+1][k]);
}

int main()
{
	int n,q,i,j,tem,last,ans,L,R;
	while(scanf("%d",&n)&&n!=0)
	{
		memset(x,0,sizeof(int)*(n+1));
		scanf("%d",&q);
		len=1;//段号与段数 
		scanf("%d",&last);
		x[len]++;//更新段长 
		LEFT[len]=1;//更新段的左端点 
		number[1]=len;//更新元素对应段号 
		for(i=2;i<=n;i++)
		{
			scanf("%d",&tem);
			if(tem==last)
			{
				x[len]++;//更新段长 
				number[i]=len;
			}
			else
			{
				last=tem;
				RIGHT[len]=i-1;//上一段的右端点确定 
				len++;//新增段 
				x[len]++;
				LEFT[len]=i;
				number[i]=len;
			}
		}
		RIGHT[len]=n; 
		init();
		while(q--)
		{
			scanf("%d%d",&i,&j);
			if(number[i]==number[j])//在同一段 
			{
				printf("%d\n",j-i+1);
			}
			else
			{
				R=RIGHT[number[i]],L=LEFT[number[j]];
				ans=max(R-i+1,j-L+1);
				if(L>R+1)//这样中间才会有段 
				{
					i=number[R+1];
					j=number[L-1];
					printf("%d\n",max(ans,answer(i,j))); 
				}
				else
				{
					printf("%d\n",ans);
				}
			}
		}
	} 
	return 0; 
}




















