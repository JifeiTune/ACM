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
#include<ctime>

using namespace std;

/*
树状数组的本质是通过lowbit将下标分段
改成二维时，在第一维分段的基础上，给第二维分段即可
写法类比一维时的情况 
*/ 

#define lowbit(n) (n&(-n))

int H,W;
long long x[4100][4100];

void add(int h,int w,int val)
{
    int i,j;
    for(i=h;i<=H;i+=lowbit(i))
    {
        for(j=w;j<=W;j+=lowbit(j))
        {
            x[i][j]+=val;
        }
    }
}

long long sum(int h,int w)
{
    long long ans=0;
    int i,j;
    for(i=h;i>0;i-=lowbit(i))
    {
        for(j=w;j>0;j-=lowbit(j))
        {
            ans+=x[i][j];
        }
    }
    return ans;
}

int main()
{
    memset(x,0,sizeof(x));
    int q,op,a,b,c,d,i,j;
    scanf("%d%d",&H,&W);
    while(~scanf("%d",&op))
    {
        if(op==1)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }
        else
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            printf("%lld\n",sum(c,d)-sum(a-1,d)-sum(c,b-1)+sum(a-1,b-1));
        }
    }
    return 0;
}




