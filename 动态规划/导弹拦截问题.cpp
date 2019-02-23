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
飞来一系列导弹，每个有一个高度
现有系统起始能拦截任意高度
之后每次都不能超过前一次的高度

问只用一个系统，最多能拦截多少个
若想拦截所有，最少配备几个系统

问1为求最长不上升子序列
问2位求最长上升子序列
*/

int x[1001];
int inc[1001];//最长上升
int decr[1001];//最长不上升

int main()
{
    int i,n=0,MAX,MIN,j,temp,ans1=1,ans2=1;
    while(~scanf("%d",&temp))
    {
        x[++n]=temp;
        inc[n]=1;
        decr[n]=1;
    }
    for(i=2;i<=n;i++)
    {
        MAX=0;
        MIN=0;
        for(j=1;j<i;j++)
        {
            if(x[i]>x[j])
            {
                MAX=max(MAX,inc[j]);
            }
            else
            {
                MIN=max(MIN,decr[j]);
            }
        }
        inc[i]+=MAX;
        decr[i]+=MIN;
        ans1=max(ans1,inc[i]);
        ans2=max(ans2,decr[i]);
    }
    printf("%d\n%d",ans2,ans1);
    return 0;
}
