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
将长为n的数组分成连续的k段
每段的值为其中元素之和
要使所有段中最大值最小，该如何划分（多解时，使前面的段值尽量小）

设dp[i][j]表示将前i个数分成j段时的最小值
每次枚举最后一段的起始位置
d[i][j]则为max(dp[t][j-1],sum[i]-sum[t])中的最小值（t为分割点）
求出了dp[n][k]后，贪心递归打印即可
*/

int x[501];
int dp[501][501];//前i个分成j份时的最小值
int n,k,ans;

void out(int num,int ed)//
{
    if(num>=1)
    {
        int i,sum=0;
        for(i=ed;i>=num;i--)//从末尾向前尽可能多地取
        {
            sum+=(x[i]-x[i-1]);
            if(sum>ans)
            {
                out(num-1,i);
                cout<<i+1<<' '<<ed<<'\n';
                return;
            }
        }
        out(num-1,num-1);
        cout<<num<<' '<<ed<<'\n';
    }

}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,MIN,MAX,temp,p,t,T;
    cin>>n>>k;
    x[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
        x[i]+=x[i-1];
        dp[i][1]=x[i];
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k&&j<=i;j++)
        {
            MIN=0x7fffffff;
            for(t=1;t<i;t++)//枚举分割点
            {
                temp=max(dp[t][j-1],x[i]-x[t]);
                MIN=min(MIN,temp);
            }
            dp[i][j]=MIN;
        }
    }
    ans=dp[n][k];
    //cout<<ans<<'\n';
    out(k,n);
    return 0;
}


