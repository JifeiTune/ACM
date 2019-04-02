#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

/*
长达1e6的序列，每个元素值达1e6，求最长的区间长度，区间内元素不重复

尺取就行，需存储当前区间内出现过的值，当然是可以用map的
但这周再练习hash，就不要map了
标记是否出现过，可以用一个vis数组，但是值太大，故需要离散化
将原序列排序后，第K大的离散化成K就行了
取一个结构体，保存数值和在原数组中的下标，按值排序后
扫一遍并在原数组改即可，注意重复的情况
*/

struct Node
{
    int val,p;
    bool operator<(const Node& r) const
    {
        return val<r.val;
    }
};

Node L[1000001];
int x[1000001];
bool vis[1000001]={0};

int main()
{
	int len,i,ans=0,b,n,last,MAX,j,p;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&L[i].val);
        L[i].p=i;
    }
    sort(L+1,L+1+n);
    last=L[1].val;
    p=1;
    x[L[1].p]=p;
    for(i=2;i<=n;i++)
    {
        if(L[i].val!=last)
        {
            ++p;
            last=L[i].val;
        }
        x[L[i].p]=p;
    }
    i=1,j=1,MAX=1;
    vis[x[1]]=1;
    while(j<=n)
    {
        ++j;
        while(j<=n&&vis[x[j]]==0)
        {
            vis[x[j]]=1;
            ++j;
        }
        MAX=max(MAX,j-i);
        if(j<=n)
        {
            while(x[i]!=x[j])
            {
                vis[x[i]]=0;
                ++i;
            }
            ++i;
        }
    }
    printf("%d",MAX);
	return 0;
}
