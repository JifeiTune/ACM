#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<random>
#include<functional>
using namespace std;

/*
给定一个整数序列，找其长度不小于Len的子段，使得子段的均值最大，问这个最大均值

当均值给定时，判断是否存在不小于Len的子段是可以在O(N)内完成的
因为若将原序列每个数减去均值，就转换成求一个不小于Len的子段，使得子段和>=0
子段和当然可以用前缀和O(1)求解，但是这个子段怎么找呢，看似要O(N^2)枚左右端点
其实不用，子段和用前缀和表示为pre[R]-pre[L-1]，要让它>=0，当然希望pre[L-1]越小越好
所以只需枚举R，并记录左边距R超过Len的pre值中，最小的那个，每次pre[R]减去它即可
二分均值，就可在O(NlogN)解决 
*/

int x[100001];
int n,MAX;
#define INF 0x3f3f3f3f
long long pre[100001];//前缀和

inline bool isOk(int ave)//看能否找到一个子段，使其均值不小于ave
{
    long long MIN=0x3f3f3f3f3f3f3f3f;
    int i,p;
    for(i=1;i<=n;i++)
    {
    	pre[i]=pre[i-1]+x[i]-ave;//减去均值，求前缀和
	}
    for(i=MAX;i<=n;i++)
    {
        if(pre[i-MAX]<MIN)//取最小的
		{
			MIN=pre[i-MAX];
		}
		if(pre[i]-MIN>=0)
		{
			return 1;
		}
    }
    return 0;
}

int main(int argc, char* argv[])
{
	int i,last,L=INF,R=-INF,mid;
	scanf("%d%d",&n,&MAX);
	pre[0]=0;
	for(i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        x[i]*=1000;//按照精度扩大1000倍
        L=min(L,x[i]);
        R=max(R,x[i]);
    }
    pre[0]=0;
    while(L<=R)
    {
        mid=(L+R)/2;//二分均值
        if(isOk(mid))
        {
            last=mid;
            L=mid+1;
        }
        else
        {
            R=mid-1;
        }
    }
    printf("%d",last);
	return 0;
}
