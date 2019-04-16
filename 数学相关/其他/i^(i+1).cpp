#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

/*
定义F(i)表示i异或(i+1)的二进制表示中，1的个数 
问i在[L,R]范围内，F(i)的和为多少
打表发现，数n起始点为2^(n-1)-1，每隔2^n出现一次
每次根据右端点求出最大的n，再从1到n分别求即可 
*/ 

inline int getNum(int n,int R)//[0,R]范围内，n出现次数
{
    if(R<0)
    {
        return 0;
    }
    int ans=0,be=(1<<(n-1))-1,d=(1<<n);
    if(be<=R)
    {
        ans=(R-be)/d+1;//等差数列通项公式转化 
    }
    return ans;
}

int main()
{
	int i,j,k,T,Time,L,R,MAX;
	long long ans=0;
    scanf("%d",&T);
    while(T--)
    {
    	ans=0;
        scanf("%d%d",&L,&R);
        MAX=1;
        while(((1<<(MAX-1))-1)<=R)
        {
            ++MAX;
        }
        --MAX;
        for(i=1;i<=MAX;i++)
        {
            ans+=(getNum(i,R)-getNum(i,L-1))*(long long)i;
        }
        printf("%d\n",ans);
    }
	return 0;
}
