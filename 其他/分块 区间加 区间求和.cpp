#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<list>

using namespace std;

/*
下标从0开始，Bsize为块大小
则下标为i的数，在第i/Bsize块（也从0开始），整除时，i为该块的起始
末尾可能有残缺部分，那部分暴力处理，不要在sum和lazy中按块考虑
*/

#define MAXN int(5e4+1)
#define BMAXN int(1e3+1)//块数

typedef long long LL;

LL x[MAXN];//原数组
int len;//数组长度
int Bsize;//块大小
int belong[MAXN];
LL sum[BMAXN]={0};//每一块的区间和
LL lazy[BMAXN]={0};//每一块待加上的数

void init()
{
    Bsize=sqrt(len);
    //多组样例时，清空sum和lazy
    int i;
    for(i=0;i<len;i++)
    {
    	belong[i]=i/Bsize;
        sum[belong[i]]+=x[i];
    }
}

void add(int L,int R,int val)//[L,R]加上val
{
    int i;
    for(i=L;i<=R;)
    {
        if(i%Bsize==0&&i+Bsize-1<=R)//只有完全是一块才统一处理
        {
            lazy[belong[i]]+=val;//加到lazy上
            i+=Bsize;
        }
        else//块外暴力处理
        {
            x[i]+=val;
            sum[belong[i]]+=val;//所在块总和也要加
            ++i;
        }
    }
}

LL query(int L,int R)//求[L,R]之和
{
    int i;
    LL ans=0;
    for(i=L;i<=R;)
    {
        if(i%Bsize==0&&i+Bsize-1<=R)//只有完全是一块才统一处理
        {
            //该块的结果，加上该块lazy上待解决的
            ans+=sum[belong[i]]+lazy[belong[i]]*Bsize;
            i+=Bsize;
        }
        else//块外暴力处理
        {
            ans+=x[i]+lazy[belong[i]];
            ++i;
        }
    }
    return ans;
}


int main()
{
    int T,i,q,L,R,val,op;
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        scanf("%lld",&x[i]);
    }
	init();
    for(i=1;i<=len;i++)
    {
        scanf("%d%d%d%d",&op,&L,&R,&val);
        if(op==0)//加上
        {
            add(L-1,R-1,val);
        }
        else//询问
        {
            printf("%lld\n",query(L-1,R-1));
        }
    }
    return 0;
}



