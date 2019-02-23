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
#include<queue>

using namespace std;

/*
将给定的若干网线切割成等长的若干个
最长为多少

二分长度即可，虽然每次二分要统计可切割数
而网线数目达1e4，也就是统计时需要循环1e4次
但二分次数不会太多，没关系的

特别注意，因double精度缺陷，最好将其根据所需精度转换成整型来计算！！！
如这里精确到小数点后2位，就扩大100倍
*/

long long x[10001];
int n;

inline long long getN(int len)//根据所选长度计算能分割多少份
{
    long long i,num=0;
    for(i=1;i<=n;i++)
    {
        num+=x[i]/len;
    }
    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    long long L,R,mid,MAX=0,i,num,ans;
    double temp;
    cin>>n>>num;
    for(i=1;i<=n;i++)
    {
        cin>>temp;
        x[i]=temp*100;
        MAX=max(MAX,x[i]);
    }
    L=1,R=MAX;
    ans=0;
    while(L<=R)
    {
        mid=(L+R)/2;
        if(getN(mid)>=num)
        {
            L=mid;
            ans=mid;
        }
        else
        {
            R=mid;
        }
    }
    printf("%.2f",ans/100.0);
    return 0;
}



