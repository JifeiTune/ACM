#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<set>
#include<queue>

using namespace std;

/*
教训！以后遇到看起来像数论的题不要被唬住，极有可能只是范围不大的打表规律题

定义F(x)表示x的质因子个数，每次给定[L,R]（L、R不超过1e6），问gcd(F(i),F(j))(L<=i<j<=R)的最大值
看起来好像要枚举i、j，其实会发现在给定范围内F(x)不会太大，因为2*3*5*7*11*13*17*19恰好大于1e6
所以F(x)最大值也就7，因此问题转换为判断[L,R]内是否存在值为1-7的点（或者说有几个）
因为也就有以下几种情况，1-7内某个数字出现了2次或以上，那gcd存在那个值
以及存在2和4、2和6、3和6的情况，分别为2、2、3
在这些值里找最大即可（初值最小为1）

这种存在性以及出现多少次的问题，可用前缀和解决，即某个位置存在，就置为1
求个前缀和，区间个的个数，就是区间求和，和为0表示不存在
*/

#define MAX ((int)(1e6))//此处控制筛选范围

bool x[MAX+1];//标记为1表示是合数，0表示质数
int Num[MAX+1]={0};//质因子个数
int pre[8][MAX]={{0}};//前缀和
vector<int> Pri;

inline void getP()
{
	long long bs,i;
	long long range=(long long)(sqrt(MAX)+1);
	memset(x,0,sizeof(x));//先全部标记为质数
	for(i=2;i<=range;i++)
	{
		if(!x[i])//未标记，说明是质数
		{
			bs=i;//倍数一开始就设为i，因为小于i的数之前已经筛过
			while(bs*i<=MAX)
			{
				x[bs*i]=1;
				bs++;
			}
		}
	}
}

int has[8];//has[i]表示为i的个数

int main()
{
    int i,j,bs=0,len,temp,ans,T,L,R;
    getP();
    Pri.reserve(100000);
    for(i=2;i<=MAX;i++)
    {
        if(!x[i])
        {
            Pri.push_back(i);
        }
    }
    len=Pri.size();
    for(i=0;i<len;i++)
    {
        //printf("%d\n",Pri[i]);
        temp=Pri[i];
        while(temp<=MAX)
        {
            ++Num[temp];
            temp+=Pri[i];
        }
    }
    for(i=1;i<=MAX;i++)
    {
        pre[Num[i]][i]=1;
    }
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=MAX;j++)
        {
            pre[i][j]+=pre[i][j-1];
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        ans=1;
        scanf("%d%d",&L,&R);
        for(i=1;i<=7;i++)
        {
            has[i]=pre[i][R]-pre[i][L-1];
            if(has[i]>1)
            {
                ans=i;//大的覆盖小的
            }
        }
        if(has[2]&&has[4]||has[2]&&has[6])
        {
            ans=max(ans,2);
        }
        if(has[3]&&has[6])
        {
            ans=max(ans,3);
        }
        printf("%d\n",ans);
    }
	return 0;
}
