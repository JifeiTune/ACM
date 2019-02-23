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
输出前k大的数
直接全部排序效率低，因为把其他数也排了

模拟快排的过程，使得枢轴及右边元素个数为k
再单独对这部分排序即可
*/

int x[100001];

void Qs(int be,int ed,int k)//使得枢轴及右边元素个数为k
{
    if(ed>be)
    {
        int i=be,j=ed,temp=x[be],num;
        while(j>i)//这样结束时i==j，且为空缺元素
        {
            while(j>i&&x[j]>=temp) j--;
            x[i]=x[j];
            while(j>i&&x[i]<=temp) i++;
            x[j]=x[i];
        }
        x[i]=temp;//此时i==j
        num=ed-i+1;
        if(num<k)//少了
        {
            Qs(be,i-1,k-num);//从枢轴左边再找缺失的
        }
        else if(num>k)//多了
        {
            Qs(i+1,ed,k);//从枢轴右边继续找
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int T,i,num,k;
    cin>>num;
    for(i=1;i<=num;i++)
    {
        cin>>x[i];
    }
    cin>>k;
    Qs(1,num,k);
    sort(x+1+num-k,x+1+num);
    for(i=num;i>=1+num-k;i--)
    {
        cout<<x[i]<<'\n';
    }
    return 0;
}

