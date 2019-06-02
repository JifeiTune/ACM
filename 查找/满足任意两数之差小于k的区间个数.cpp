#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<list>
#include<cstdlib>
#include<fstream>
#include<algorithm>
using namespace std;

/*
给定一个数组，寻找满足以下要求的区间个数：
区间内任意两数之差小于MAXLEN

任意两数之差要小于MAXLEN，其实就是区间最大值减去最小值要小于MAXLEN
区间最值用RMQ解决
枚举左端点，右端点可以二分求解，相当于二分满足要求的区间最大长度
长区间不行就找短区间，短区间可以就再找长区间
*/

#define num 100001//数组最大长度
int x[num];
int MAX[num][20];
int MIN[num][20];
int len;//数组实际使用长度

void init()//初始化数组后别忘了init！
{
	int i,j;
	for(i=1;i<=len;i++)
	{
		MAX[i][0]=x[i];
		MIN[i][0]=x[i];//以i开头长度为2^0的最值当然是自己
	}
	for(j=1;(1<<j)<=len;j++)
	{
		for(i=1;i+(1<<j)-1<=len;i++)//注意范围，右坐标未超出数组下标才有计算的意义
		{
			MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);
			MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);//划分成长度相等的两个子区间
		}
	}
}

int answer(int i,int j,bool what)//求i到j最值，what为1表示求最大值，为0表示求最小值
{
	int dis=j-i+1,k=0;
	while((1<<(++k))<=dis);
    --k;
	if(what)
	{
		return max(MAX[i][k],MAX[j-(1<<k)+1][k]);
	}
	else
	{
		return min(MIN[i][k],MIN[j-(1<<k)+1][k]);
	}
}

int main()
{
    int i,j,L,R,mid,T,MAXLEN,last;
    long long ans=0;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d%d",&len,&MAXLEN);
        for(i=1;i<=len;i++)
        {
            scanf("%d",&x[i]);
        }
        init();
        for(i=1;i<=len;i++)
        {
            L=i,R=len;
            while(L<=R)//二分找最右边一个满足条件的点
            {
                mid=(L+R)/2;
                if(answer(i,mid,1)-answer(i,mid,0)<MAXLEN)
                {
                    last=mid;
                    L=mid+1;
                }
                else
                {
                    R=mid-1;
                }
            }
            ans+=last-i+1;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
