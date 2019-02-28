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
二分求解的问题
1、从复杂度上看，应在O(log(N))或O(Nlog(N))内解决
注意log(N)比较小，即使N达到1e5（这个一般为判断函数），也没关系
2、具备单调性，要求解的值可以用一个函数衡量（“太大”、“太小”、“正好”）

将N个元素的数组划分成M段（M<=N），每段的值为其元素和
要让最大值最小，求该最大值

二分该最大值，判断函数为根据传入的最大值计算最少分多少段
若段数大于M，说明最大值太小了
若小于等于M，说明最大值还能小
*/

int x[100001];
int N,M;

inline int getN(int num)//最大值为num时，最小划分数
{
    int i,ans=1,last=0;
    for(i=1;i<=N;i++)
    {
        if(x[i]+last<=num)
        {
            last+=x[i];
        }
        else
        {
            ++ans;
            last=x[i];
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,MAX=0,L,R,num,sum=0,mid,last;
    cin>>N>>M;
    for(i=1;i<=N;i++)
    {
        cin>>x[i];
        sum+=x[i];
        MAX=max(MAX,x[i]);
    }
    L=MAX,R=sum;
    while(R>=L)
    {
        mid=(L+R)/2;
        if(getN(mid)<=M)
        {
            last=mid;
            R=mid-1;
        }
        else
        {
            L=mid+1;
        }
    }
    cout<<last;
    return 0;
}



