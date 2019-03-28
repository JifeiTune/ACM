#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

typedef long long LL;

struct Node
{
    int L,R;
    LL val;
};

#define MAXN 1000001

Node x[MAXN*4];

void build(int root,int L,int R)//建一棵没有值的空树
{
    x[root].L=L,x[root].R=R,x[root].val=0;
    if(L<R)//还得往下
    {
        int mid=((L+R)>>1);
        build(root<<1,L,mid);
        build((root<<1)|1,mid+1,R);
    }
}

void setVal(int root,int L,int R,long long val)//区间、点修改,在这里val为加上的值
{
    //首先修改区间肯定是root区间的子集
    x[root].val=max(x[root].val,val);
    if(x[root].L<x[root].R)
    {
        int mid=(x[root].L+x[root].R)/2;
        if(L<=mid)//跨入左子区间
        {
            setVal(root<<1,L,min(mid,R),val);
        }
        if(R>mid)//跨入右子区间
        {
            setVal((root<<1)|1,max(mid+1,L),R,val);
        }
    }

}

long long getVal(int root,int L,int R)
{
    if(L==x[root].L&&R==x[root].R)
    {
        return x[root].val;
    }
    else
    {
        long long ans=0,temp;
        int mid=(x[root].L+x[root].R)/2;
        if(L<=mid)//跨入左子区间
        {
            temp=getVal(root<<1,L,min(mid,R));
            ans=max(ans,temp);
        }
        if(R>mid)//跨入右子区间
        {
            temp=getVal((root<<1)|1,max(mid+1,L),R);
            ans=max(ans,temp);
        }
        return ans;
    }
}

int main()
{
    int n,i,j,L,R,op,pos=0;
    long long MOD,last=0,num;
    char c;
    scanf("%d%lld",&n,&MOD);
	build(1,1,n);
    while(n--)
    {
        scanf(" %c%lld",&c,&num);
        if(c=='A')
        {
            ++pos;
            setVal(1,pos,pos,(num+last)%MOD);
        }
        else
        {
            last=getVal(1,pos-num+1,pos);
            printf("%lld\n",last);
        }
    }

	return 0;
}
