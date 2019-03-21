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
using namespace std;

/*
有N（达50个）个集合，每个集合元素达1e4，有达2000次询问
每次求出询问的两个集合，交集元素个数与并集元素的商

直接用set模拟当然会超时，求交集和并集很简单，关键是要让两个集合元素有序
先将每个集合元素去重，再从大到小排序，然后类比归并排序的合并操作
现在相当于有2个单调队列，每次取队头比较，若相等，都取出，属于交集和并集
若不等，取较小值，属于并集
注意最后可能会有一个取完一个还没取完，剩下的元素属于并集 
*/ 

vector<int> x[51];
int ele[10001];

double getN(int a,int b)//已去除内部重复
{
    vector<int> &v1=x[a],&v2=x[b];
    int i,j,len1=v1.size(),len2=v2.size(),inte=0,uni=0;
    i=j=0;
    while(i<len1&&j<len2)
    {
        if(v1[i]<v2[j])
        {
            ++uni,++i;
        }
        else if(v1[i]>v2[j])
        {
			++uni,++j;
        }
        else
        {
            ++uni;
            ++inte;//二者共有，属于交集
			++i,++j;
        }
    }
    //注意下面的别漏了，剩下的是独有的
    while(i<len1)
    {
        ++uni,++i;
    }
    while(j<len2)
    {
        ++uni,++j;
    }
    return (double)inte/uni;
}

int main()
{
    int n,m,len,i,k,temp,a,b,last,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&len);
        for(j=1;j<=len;j++)
        {
            scanf("%d",&ele[j]);
        }
        sort(ele+1,ele+1+len);
        last=ele[1]-1;
        for(j=1;j<=len;j++)
        {
            if(ele[j]!=last)//去重
            {
                last=ele[j];
                x[i].push_back(ele[j]);
            }
        }
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        printf("%.2f%\n",getN(a,b)*100.0);
    }
    return 0;
}





