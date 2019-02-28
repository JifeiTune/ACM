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
将n个苹果放入k个盘子，允许其中有盘子为空
盘子不计顺序，如1,3和3,1是同一种方法

相比于固定位数的整数划分，允许划分为0的情况
仍可采用dp解决

设dp[i][j]表示将i个苹果放入j个盘子的放法
1.当i<j时，必然有若干盘子为空，因为不计顺序，所以可设第j个盘子为空
将i个放入前j-1个盘子，即dp[i][j]=dp[i][j-1]
2.i>=j时，类比固定位数的整数划分，也分全为非空和存在非空2种情况
即dp[i][j]=dp[i-j][j]+dp[i][j-1]
*/

long long dp[21][21];//dp[i][j]表示i个元素划分入j个集合时的方法数


int main()
{
    ios::sync_with_stdio(false);
    int i,j,n,k,T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        dp[0][0]=1;
        for(i=1;i<=n;i++)
        {
            dp[0][i]=1;
            dp[i][1]=1;
            for(j=2;j<=k;j++)
            {
                if(i<j)
                {
                    dp[i][j]=dp[i][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-j][j]+dp[i][j-1];
                }
            }
        }
        cout<<dp[n][k]<<'\n';
    }

    return 0;
}

