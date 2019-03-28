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
    LL val,lazy;
};

#define MAXN 1000001

Node x[MAXN*4];

void build(int root,int L,int R)//建一棵没有值的空树
{
    x[root].L=L,x[root].R=R,x[root].val=0,x[root].lazy=0;
    if(L<R)//还得往下
    {
        int mid=((L+R)>>1);
        build(root<<1,L,mid);
        build((root<<1)|1,mid+1,R);
        x[root].val=x[root<<1].val+x[(root<<1)|1].val;
    }
    else if(L==R)
    {
    	scanf("%lld",&x[root].val);
	}
}

void pushDown(int root)//当且仅当该区间用上了，但只用了一部分，该节点的lazy标记才需要下推
{
    if(x[root].lazy!=0)
    {
        x[root<<1].lazy+=x[root].lazy;
        x[(root<<1)|1].lazy+=x[root].lazy;
        x[root].val+=x[root].lazy*(x[root].R-x[root].L+1);//清空lazy前先加上
        x[root].lazy=0;//当前节点lazy清空
    }

}

void setVal(int root,int L,int R,int val)//区间、点修改,在这里val为加上的值
{
    //首先修改区间肯定是root区间的子集
    if(x[root].L==L&&x[root].R==R)//区间正好重合
    {
        if(L==R)//已经是叶子节点，就别去搞什么lazy标记了
        {
            x[root].val+=val;
        }
        else
        {
            x[root].lazy+=val;
        }
    }
    else//修改区间为本区间一部分
    {
        pushDown(root);//先下推标记
        x[root].val+=(long long)val*(R-L+1);//本节点加上
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
        return x[root].val+x[root].lazy*(x[root].R-x[root].L+1);
    }
    else
    {
        pushDown(root);
        long long ans=0;
        int mid=(x[root].L+x[root].R)/2;
        if(L<=mid)//跨入左子区间
        {
            ans+=getVal(root<<1,L,min(mid,R));
        }
        if(R>mid)//跨入右子区间
        {
            ans+=getVal((root<<1)|1,max(mid+1,L),R);
        }
        return ans;
    }
}

int main()
{
    int n,q,i,j,L,R,op,num;
    scanf("%d%d",&n,&q);
	build(1,1,n);
    while(q--)
    {
        scanf("%d%d%d",&op,&L,&R);
        if(op==1)
        {
            scanf("%d",&num);
            setVal(1,L,R,num);
        }
        else
        {
            printf("%lld\n",getVal(1,L,R));
        }
    }
	return 0;
}

