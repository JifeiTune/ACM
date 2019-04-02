#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

/*
输入一个数组，要求按以下方法将之改成一个没有重复元素的数组：
从左到右扫描元素，如果当前元素在之前用过，就不断加一知道没有出现过

暴力当然免了，所要解决的问题就是，如果当前元素重复了，需要增加最少多少才能不重复
可用并查集，连续使用的元素放在同一个团，维护每个元素所在团的最大值+1
下次有元素与团中元素重复时，直接置为那个值，合并后更新该值
但更新后该值可能在其他团里，再更新一下
*/

int x[1000001];
int MAX[1000001];//每个元素所在团最大值

int Find(int n)
{
    return x[n]=(x[n]==n?n:Find(x[n]));
}

int main()
{
    ios::sync_with_stdio(false);
    int len,i,f1,f2,temp,m;
    cin>>len;
    for(i=1;i<=1000001;i++)
    {
        x[i]=i;
        MAX[i]=i;
    }
    for(i=1;i<=len;i++)
    {
        cin>>temp;
        f1=Find(temp);
        m=MAX[f1];
        cout<<m<<' ';
        x[m]=f1;//合并，m肯定是独立点
        f2=Find(m+1);
        x[f1]=f2;
    }
    return 0;
}
