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
n层楼，k个相同硬度的鸡蛋
问采取最优策略时，最坏情况下，扔几次才能确定鸡蛋的硬度
注：假设鸡蛋硬度为m，则m层扔下不破，m层以上扔下破，破了的当然无法再扔了

注意到以下个事实：
同样多个鸡蛋，确认[1,1+x]层中哪层开始会破
和确认[k,k+1]层中哪层会破，扔的最少次数一样，即只与区间长度有关
在每一层扔时，都有破和不破2种可能，分别转移到上下2个区间
每次都要考虑这2种情况，因为考虑最坏情况，所以取最大值

设dp[i][j]为在i层楼中利用j个鸡蛋试探出硬度的最优解
则dp[i][j]=min(dp[i][j],max(dp[i-t][j]+1,dp[t-1][j-1]+1))
t为枚举的扔下层数
*/

int dp[101][11];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,n,k,t,temp1,temp2;
    while(cin>>n>>k)
    {
        for(i=1;i<=n;i++)
        {
            dp[i][1]=i;
        }
        for(i=1;i<=k;i++)
        {
            dp[0][i]=0;
            dp[1][i]=1;
        }
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=k;j++)
            {
                dp[i][j]=0x7fffffff;
                for(t=1;t<=i;t++)//枚举下落点
                {
                    temp1=dp[i-t][j]+1;//没破
                    temp2=dp[t-1][j-1]+1;//破了
                    temp1=max(temp1,temp2);
                    dp[i][j]=min(dp[i][j],temp1);
                }
            }
        }
        cout<<dp[n][k]<<'\n';
    }
    return 0;
}

