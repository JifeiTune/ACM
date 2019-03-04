#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<list>
#include<cmath>
#include<stack>

using namespace std;

/*
多重背包
相比于01背包，每种物品个数也一定，但可能超过1个
01背包中状态转移是取和不取，其实就是取0个或1个
多重背包中，枚举取0-num[i]个即可

优化
*/

int dp[501][6001];
int val[501];//价值
int wei[501];//重量
int num[501];//数量

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n,k,t1,t2;
    cin>>n>>all;
    for(i=1;i<=n;i++)
    {
        cin>>wei[i]>>val[i]>>num[i];
    }
    for(j=0;j<=all;j++)
    {
        dp[0][j]=0;//根据递推表达式初始化边界
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=all;j++)//枚举容量
        {
            dp[i][j]=0;
            for(k=0;k<=num[i];k++)//枚举取的个数
            {
                temp=k*wei[i];
                if(j>=temp)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-temp]+k*val[i]);
                }
            }
        }

    }
    cout<<dp[n][all];
    return 0;
}

