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
N个石头排成一排
现可以移除除起点和终点外的最多M个石头
使得石头间最小的距离最大
问这个距离

二分这个距离
计算要保证当前距离时最少移除的石头数
若<=M，则可能还能大
若>M，则必须变小
*/

int x[50001];
int N,M,Len;

inline int getN(int L)//最小间隔为L时，最小、移走数
{
    int ans=0,last=0,i;
    for(i=1;i<=N;i++)
    {
        if(x[i]-last<L)
        {
            ans++;//移走i
        }
        else
        {
            last=x[i];
        }
    }
    if(Len-last<L)//还要和终点比较
    {
        ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,MIN=0x7fffffff,L,R,num,sum=0,mid,last;
    cin>>Len>>N>>M;
    x[0]=0;
    for(i=1;i<=N;i++)
    {
        cin>>x[i];
        MIN=min(MIN,x[i]-x[i-1]);
    }
    MIN=min(MIN,Len-x[N]);//注意别漏了
    L=MIN,R=Len;
    while(R>=L)
    {
        mid=(L+R)/2;
        if(getN(mid)<=M)
        {
            last=mid;
            L=mid+1;
        }
        else
        {
            R=mid-1;
        }
    }
    cout<<last;
    return 0;
}



