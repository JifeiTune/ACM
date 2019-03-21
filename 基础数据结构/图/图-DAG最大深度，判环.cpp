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
n个员工发奖金（整数），每个人最少100，先存着一系列关系，B->A表示A的奖金必须高于B的 
要使总奖金最少，问这个最小值 

建图，节点代表员工，边指向奖金高的，如果图是DAG
那么就是从入度为0的点出发，求点的最大深度问题，深度增加一层，奖金增加1
每个点可能有多个深度，即到达它由多条路径，取最大值

但是原题还要判环，所以模拟一下拓扑排序的过程，这里用取点删边法
最后输出节点数少于n代表有环 
*/ 

vector<int> G[10001];
int In[10001];//入度
int MAX[10001];

struct Node
{
    int p,val;
};

queue<Node> q;

int main()
{
    int n,m,a,b,i,j,len,ans=0,to,num=0;
    Node temp,nex;
    scanf("%d%d",&n,&m);
    memset(In,0,sizeof(In));
    while(m--)
    {
        scanf("%d%d",&a,&b);
        G[b].push_back(a);//a比b高，指向更高的建图
        In[a]++;
    }
    temp.val=100;
    for(i=1;i<=n;i++)
    {
        MAX[i]=100;
        if(In[i]==0)
        {
            temp.p=i;
            q.push(temp);//入度为0的点存入
        }
    }
    while(!q.empty())
    {
        num++;//记录个数
        temp=q.front();
        q.pop();
        len=G[temp.p].size();
        MAX[temp.p]=max(MAX[temp.p],temp.val);//取最大深度
        for(i=0;i<len;i++)
        {
            to=G[temp.p][i];
            In[to]--;//入度减一
            if(In[to]==0)//入度为0，则推入，等待输出
            {
                nex.p=to,nex.val=temp.val+1;
                q.push(nex);
            }
        }
    }
    if(num!=n)
    {
        printf("Poor Xed");
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            ans+=MAX[i];
        }
        printf("%d",ans);
    }
    return 0;
}






