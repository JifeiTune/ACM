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
#include<queue>

using namespace std;

/*
字符串A和B，编辑距离为将A化为B的最小编辑次数
每次编辑可以：删除、插入或修改一个字符
求编辑距离

设dp[i][j]表示将A[1,i]转换成B[1,j]的最小编辑次数（下标从1开始）
注！！！这个状态是对于原串来说的，而不是修改后（可能变短、变长）
则初态dp[k][0]=k,dp[0][k]=k（其中一个串为空）
之后求到dp[i][j]时，可能有3种转换方式
1、修改，若A[i]==B[j]，不必修改，就等于dp[i-1][j-1]，否则加上1
2、删除A[i]，删除后就是dp[i-1][j]（A[1,i-1]已经转换成B[1,j]，A[i]多余）加上删除操作的1
3、插入B[j]于A[i]位置，为dp[i][j-1]（A[1,i]已经转换成B[1,j-1]，还缺B[j]）加上插入操作的1
取三者的最小值即可
*/


char A[2001];
char B[2001];

int dp[2001][2001];

int main()
{
    ios::sync_with_stdio(false);
    int T,i,j,ans,temp,n,k,lenA,lenB,t1,t2,t3,MAX;
    cin>>(A+1)>>(B+1);
    lenA=strlen(A+1);
    lenB=strlen(B+1);
    for(i=0;i<=lenA;i++)
    {
        dp[i][0]=i;
    }
    for(j=0;j<=lenB;j++)
    {
        dp[0][j]=j;
    }
    for(i=1;i<=lenA;i++)
    {
        for(j=1;j<=lenB;j++)
        {
            t1=dp[i-1][j-1]+(A[i]==B[j]?0:1);//修改
            t2=dp[i-1][j]+1;//删除
            t3=dp[i][j-1]+1;//插入
            MAX=min(t1,t2);
            MAX=min(MAX,t3);
            dp[i][j]=MAX;
        }
    }
    cout<<dp[lenA][lenB];
    return 0;
}
