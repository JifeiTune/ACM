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
二维费用的背包，相当于普通背包，容量多了一维
那当然将状态也多定义一维就行了，需要注意的是，背包变形很多，不一定总是容量最多限制，还可能是最少限制
例如本题，有许多气罐，每个气罐含有一定的氧和氮，具有一个重量
在满足氧和氮分别不少于最小值的情况下，问最小总重量
这里氧和氮是最少需要多少，不像普通背包一样，是最多不能超过多少
如果想完全用普通背包的做法，可以先假设全取，然后转换为删去若干气罐
如果直接做，设dp[i][j]为，考虑到当前气罐时，至少有氧i氮j时的最小重量
如果i和j用当前气罐都能满足，那直接更新最小值，否则必须借助前一能满足的状态，分类讨论即可
*/

int dp[100][100];//至少有氧i氮j时的最小重量
int n,m,INF=0x3f3f3f3f;
int O[1001];
int N[1001];
int wei[1001];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,num,k;
    cin>>n>>m>>num;
    for(i=1;i<=num;i++)
    {
        cin>>O[i]>>N[i]>>wei[i];
    }
    memset(dp,0x3f,sizeof(dp));
    for(i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }
    for(k=1;k<=num;k++)
    {
        for(i=n;i>=1;i--)
        {
            for(j=m;j>=1;j--)
            {
                /*
                分每种够和不够讨论，注意存在不够的三种情况其实可以合并
                */
                if(O[k]>=i&&N[k]>=j)//放了还有多
                {
                    dp[i][j]=min(dp[i][j],wei[k]);
                }
                else if(O[k]<i&&N[k]<j)//二者都不够，要借助前一状态
                {
                     dp[i][j]=min(dp[i][j],dp[i-O[k]][j-N[k]]+wei[k]);
                }
                else if(O[k]<i)//氧不够
                {
                    dp[i][j]=min(dp[i][j],dp[i-O[k]][j]+wei[k]);
                }
                else//氮不够
                {
                    dp[i][j]=min(dp[i][j],dp[i][j-N[k]]+wei[k]);
                }
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
