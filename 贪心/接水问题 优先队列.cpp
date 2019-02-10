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

priority_queue<int,vector<int>,greater<int> > pq;

/*
n个人接水，只有m个水龙头
n个人的顺序接水顺序一定，但起初可以m个人同时开始
只要有一个人接水完成，后面的人可以瞬间过去接水，问总的接水时间

显然是每次安排后面的人到最先结束接水的人所在水龙头
怎么定义最先结束接水呢？
给每个人定义一个结束时间即可
结束时间（当前时间+所需时间）推入升序的优先队列
每次取队头，更新其结束时间为当前时间
最后整个队列中最大值即为答案 
*/

int main()
{
    ios::sync_with_stdio(false);
    int T,n,m,i,MAX,temp,fr;
    cin>>n>>m;
    if(m>=n)
    {
        MAX=0;
        while(m--)
        {
            cin>>temp;
            MAX=max(MAX,temp);
        }
        cout<<MAX;
    }
    else
    {
        T=0;//当前时间
        for(i=1;i<=m;i++)
        {
            cin>>temp;
            pq.push(temp);//推入结束时间
        }
        for(i=1;i<=n-m;i++)//出一个入一个
        {
            cin>>temp;
            fr=pq.top();
            pq.pop();
            T=fr;//当前时间为最早的结束时间
            pq.push(T+temp);
        }
        while(!pq.empty())
        {
            T=pq.top();
            pq.pop();
        }
        cout<<T;
    }
    return 0;
}

