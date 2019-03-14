#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>

using namespace std;

/*
给出一份冒泡排序代码
在排序过程中，某个元素位置会变化
对一组排列数用此代码排序，问在这个过程中，每个元素位置最大相差多少

给出的代码，是每次从右向左冒，更小的往左走
冒泡排序时，每次都是相邻的元素比较，并可能交换顺序
所以，一个元素能向右移几次，取决于其右边比它小的元素个数，统计这个可通过树状数组来 
起初位置知道，又因为是排列数，最终位置也知道
而元素最左边的位置，不可能比最终位置还更左，因为向左走的前提是左边有比它大的元素
统计初始位置、最终位置和可能最右的位置中的最大值和最小值，相减即可 
*/

#define lowbit(x) (x&-x)

int MAX;//树状数组有意义部分最大下标
int last[100005];//原
int x[100005];
int ans[100005];//在某个数右边并且比该数小的元素个数

int sum(int n)//求前缀和
{
	int ans=0;
	while(n>0)
	{
		ans+=x[n];
		n-=lowbit(n);
	}
	return ans;
}

void add(int p,int a)//修改值，p位置，a加上的值
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
	int T,n,i,j,k,tem,L,R,cas=1;
	cin>>T;
	while(T--)
    {
        cin>>n;
        MAX=n;
        memset(x,0,sizeof(int)*(n+1));
        for(i=1;i<=n;i++)
        {
            cin>>last[i];
        }
        for(i=1;i<=n;i++)
        {
            add(last[n-i+1],1);//加一
            L=R=n-i+1;//现在的位置
            R+=sum(last[n-i+1]-1);//可能更右的位置
            R=max(R,last[n-i+1]);
            L=min(L,last[n-i+1]);
            ans[last[n-i+1]]=abs(R-L);
        }
        printf("Case #%d: ",cas++);
        printf("%d",ans[1]);
        for(i=2;i<=n;i++)
        {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
	return 0;
}

