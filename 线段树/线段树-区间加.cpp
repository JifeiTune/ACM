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

void build(int root,int L,int R)//��һ��û��ֵ�Ŀ���
{
    x[root].L=L,x[root].R=R,x[root].val=0,x[root].lazy=0;
    if(L<R)//��������
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

void pushDown(int root)//���ҽ��������������ˣ���ֻ����һ���֣��ýڵ��lazy��ǲ���Ҫ����
{
    if(x[root].lazy!=0)
    {
        x[root<<1].lazy+=x[root].lazy;
        x[(root<<1)|1].lazy+=x[root].lazy;
        x[root].val+=x[root].lazy*(x[root].R-x[root].L+1);//���lazyǰ�ȼ���
        x[root].lazy=0;//��ǰ�ڵ�lazy���
    }

}

void setVal(int root,int L,int R,int val)//���䡢���޸�,������valΪ���ϵ�ֵ
{
    //�����޸�����϶���root������Ӽ�
    if(x[root].L==L&&x[root].R==R)//���������غ�
    {
        if(L==R)//�Ѿ���Ҷ�ӽڵ㣬�ͱ�ȥ��ʲôlazy�����
        {
            x[root].val+=val;
        }
        else
        {
            x[root].lazy+=val;
        }
    }
    else//�޸�����Ϊ������һ����
    {
        pushDown(root);//�����Ʊ��
        x[root].val+=(long long)val*(R-L+1);//���ڵ����
        int mid=(x[root].L+x[root].R)/2;
        if(L<=mid)//������������
        {
            setVal(root<<1,L,min(mid,R),val);
        }
        if(R>mid)//������������
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
        if(L<=mid)//������������
        {
            ans+=getVal(root<<1,L,min(mid,R));
        }
        if(R>mid)//������������
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

