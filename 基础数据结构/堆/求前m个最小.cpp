#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
using namespace std;

/*
给定n个一元二次函数，函数开口都向上，对称轴在y轴左边，与y轴焦点在x轴上方
设定义域为正整数集，求所有函数的所有值中最小的前m个

本质上是要维护m个最小值，使用大根堆
先将第一个函数的前m个最小值放入
然后枚举其他函数，当其值小于堆顶时，替换堆顶，否则换一个函数
最后堆里面m个值就是最小
*/

#define F(a,b,c,x) (a*x*x+b*x+c)

multiset<long long> mt;

int main()
{
    ios::sync_with_stdio(false);
    int n,m,i,j,k,a,b,c,num;
    long long temp;
    cin>>n>>m;
    cin>>a>>b>>c;
    for(i=1;i<=m;i++)
    {
        mt.insert(F(a,b,c,i));
    }
    n--;
    while(n--)
    {
        cin>>a>>b>>c;
        for(i=1;;i++)
        {
            temp=F(a,b,c,i);
            if(temp<(*mt.rbegin()))
            {
                mt.erase(--mt.end());
                mt.insert(temp);
            }
            else
            {
                break;
            }
        }
    }
    while(!mt.empty())
    {
        cout<<(*mt.begin())<<' ';
        mt.erase(mt.begin());
    }
    return 0;
}
