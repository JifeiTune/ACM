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
n行k列（k>=n）的矩阵
每行选取一个元素
任意2元素不可在同一列 
要使所有元素的和最大
输出最大和，以及路径

类似背包问题，考虑到某一行的某一列时
该元素有选和不选2种可能，记录下每种选择的最大值
dp[i][j]表示选择i个元素，并且考虑到j列时的最大值
则dp[i][j]为dp[i-1][j-1]+x[i][j]（选）和dp[i][j-1]（不选）中的最大值 
注意控制好范围，x[i][j]可能为负数，所以边界条件应该设一个极小值
要打印路径，而定义的状态只是“考虑到”，而不是“已知结尾”
所以设置vis数组，保存某个状态取最优时，x[i][j]是否选择
最后根据递推表达式，逆推并递归打印即可 
*/

int x[101][101];
int dp[101][101];//前i行考虑到前j列时的最大值
bool vis[101][101];//当前最优状态，是否取j
int n,k;

void out(int H,int num)
{
    if(H>=1)
    {
        int j;
        for(j=k;j>=1;j--)
        {
            if(dp[H][j]==num&&vis[H][j])
            {
                out(H-1,num-x[H][j]);
                cout<<j<<' ';
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,p;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            cin>>x[i][j];
        }
    }
    MAX=0;
    memset(vis,0,sizeof(vis));
    dp[0][0]=0;
    for(i=1;i<=n;i++)
    {
        dp[i][i-1]=-99999;
        for(j=i;j<=(k-n+i);j++)
        {
            if(dp[i-1][j-1]+x[i][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j-1]+x[i][j];
                vis[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    cout<<dp[n][k]<<'\n';
    out(n,dp[n][k]);
    return 0;
}
