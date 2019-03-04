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
混合背包
01、完全、多重混合起来
每种物品可能只有1个，可能有多个，可能有无限个

注意到01背包就是数量为1的多重背包，可以统一为多重背包做
于是涉及到选取某一物品时，若有无限件，用完全背包的递推式
否则用多重背包
*/

int dp[31][201];
int val[31];//价值
int wei[31];//重量
int num[31];//数量

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n,k,t1,t2;
    cin>>all>>n;
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
        if(num[i]!=0)//多重背包
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
        else//完全背包
        {
            for(j=0;j<wei[i];j++)
            {
                dp[i][j]=dp[i-1][j];
            }
            for(j=wei[i];j<=all;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-wei[i]]+val[i]);
            }
        }
    }
    cout<<dp[n][all];
    return 0;
}

