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
有n种面值的货币，要组成总数all，有几种取法

完全背包计数，类比01背包计数，结合完全背包求法即可
结果会很大，开long long 
*/

long long dp[1000001];
int x[1001];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,n,all;
    cin>>n>>all;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    dp[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=x[i];j<=all;j++)//注意要正序，因为容量足够时，i状态由i状态推来
        {
            dp[j]+=dp[j-x[i]];
        }
    }
    cout<<dp[all];
    return 0;
}

