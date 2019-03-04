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
分组背包
相比于01背包，每个物品被分入了一个组
同一组的物品只能选一个

状态变一下，dp[i][j]表示为考虑到前i“组”，容量为j时的最优值
类比01做即可
*/

int dp[31][201];
int val[31];//价值
int wei[31];

vector<int> x[11];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,num,k,len,temp,MAX,all,n;
    cin>>all>>n>>T;
    for(i=1;i<=n;i++)
    {
        cin>>wei[i]>>val[i]>>num;
        x[num].push_back(i);
    }
    for(j=0;j<=all;j++)
    {
        dp[0][j]=0;//根据递推表达式初始化边界
    }
    for(i=1;i<=T;i++)//枚举组号
    {
        for(j=0;j<=all;j++)
        {
            len=x[i].size();
            dp[i][j]=dp[i-1][j];//该组一个都不选
            for(k=0;k<len;k++)//该组里选其中一个
            {
                if(j>=wei[x[i][k]])
                {
                    temp=dp[i-1][j-wei[x[i][k]]]+val[x[i][k]];
                    dp[i][j]=max(dp[i][j],temp);
                }
            }
        }
    }
    cout<<dp[T][all];
    return 0;
}
