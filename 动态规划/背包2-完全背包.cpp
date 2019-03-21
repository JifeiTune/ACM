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
完全背包
相比于01背包，每种物品个数无限
最简单的，转换成01背包，即每种物品变成（背包容量/物品重量）件物品
但这样太慢了

同样设dp[i][j]为考虑到前i个物品，背包容量为j时的最大价值
每个物品可以放多个
所以j>=wei[i]时，如果是放，状态应由i推来，而不是i-1
因为之前可能就放了若干个i物品
故此时dp[i][j]为dp[i-1][j]（完全不放）和dp[i][j-wei[i]]+val[i]（放）中的最大值
同理dp数组也可降为1维，此时j应该从小到大循环
*/

int dp[201];
int val[31];//价值
int wei[31];//重量

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n,t1,t2;
    cin>>all>>n;
    for(i=1;i<=n;i++)
    {
        cin>>wei[i]>>val[i];
    }
    for(j=0;j<=all;j++)
    {
        dp[j]=0;//根据递推表达式初始化边界
    }
    for(i=1;i<=n;i++)
    {
        //注意下面应该正序，因为物品无限的，在i状态可重复考虑
        for(j=wei[i];j<=all;j++)//省略了容量不足的情况，因为就等于i-1时对应的值
        {
            dp[j]=max(dp[j],dp[j-wei[i]]+val[i]);//放或不放
        }
    }
    cout<<"max="<<dp[all];
    return 0;
}

