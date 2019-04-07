#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>

using namespace std;

/*
每次会在给定区间种一颗树，这棵树和之前种的种类都不同
每次询问某个区间内树的种类数

种树时，从起点到终点连一条线，问题就转换为求任意区间内线的个数（只有端点也算）
那就有三种线，端点都在区间内的，和只有右端点或者左端点在区间内的
端点都在区间内的不好区分，可以反过来考虑，用总数减去不在区间内的
不在区间内的就很好求了，统计区间左边，右端点的个数，和区间右边，左端点的个数
用树状数组即可
*/

#define lowbit(x) (x&-x)

int MAX;//树状数组有意义部分最大下标
int L[50001]={0};
int R[50001]={0};

int sum(int *x,int n)//求前缀和
{
	int ans=0;
	while(n>0)
	{
		ans+=x[n];
		n-=lowbit(n);
	}
	return ans;
}

void add(int *x,int p,int a)//修改值，p位置，a加上的值
{
	if(p<1)
	{
		return;
	}
	while(p<=MAX)
	{
		x[p]+=a;
		p+=lowbit(p);
	}
}

int main()
{
    ios::sync_with_stdio(false);
	int n,q,a,b,op,kind=0;
	cin>>MAX>>q;
	while(q--)
    {
        cin>>op>>a>>b;
        if(op==1)
        {
            ++kind;
            add(R,b,1);
            add(L,a,1);
        }
        else
        {
            cout<<kind-sum(R,a-1)-(sum(L,MAX)-sum(L,b))<<'\n';
        }
    }
	return 0;
}

