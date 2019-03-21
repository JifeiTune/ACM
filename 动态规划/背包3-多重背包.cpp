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
多重背包
相比于01背包，每种物品个数也一定，但可能超过1个
01背包中状态转移是取和不取，其实就是取0个或1个
多重背包中，枚举取0-num[i]个即可

同样可以压缩成一维，既然物品可以取多个，那容量应该正序还是逆序枚举呢？
依然需要同01背包一样逆序枚举，即i状态必须由i-1状态得来
完全背包需要正序，是因为每个物品都是无限的，不管i状态时对应容量下，物品取了多少个，都能再取
而01背包和多重背包，物品不是无限的，我们不知道i状态时对应某个容量得到最优解时，i物品取了多少个
当然除非你特意去记录，不过很麻烦。所以只能从i-1状态得到，一次需要逆序，否则求解大容量时
小容量的最优解是i状态的而不是i-1状态的，造成重复
*/

int dp[6001];
int val[501];//价值
int wei[501];//重量
int num[501];//数量

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n,k,t1,t2;
    cin>>n>>all;
    for(i=1;i<=n;i++)
    {
        cin>>wei[i]>>val[i]>>num[i];
    }
    for(j=0;j<=all;j++)
    {
        dp[j]=0;//根据递推表达式初始化边界
    }
    for(i=1;i<=n;i++)
    {
        for(j=all;j>=0;j--)//枚举容量
        {
            for(k=0;k<=num[i];k++)//枚举取的个数
            {
                temp=k*wei[i];
                if(j>=temp)
                {
                    dp[j]=max(dp[j],dp[j-temp]+k*val[i]);
                }
            }
        }

    }
    cout<<dp[all];
    return 0;
}

