#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

/*
一个长为n的整数序列，每个数都唯一
每次定位到当前最大的数，取出它，以及与之分别左右相邻的k个数（若不足，全取出）
取出的数放置在一个组里，问此过程持续下去直到序列为空，原序列中每个数分别分到了哪一个组里

去掉了的就不会再取，所以用链式结构可以做到线性复杂度
关键是，每次要找最大的数，怎么定位
原序列中每个数都唯一，所以可以用multiset存下每个数和其在原序列中的下标
需要方便地定位到下标，用STL list显然难以做到 
可以写一个存在数组中的链表L[i]和R[i]分别表示下标为i的数，左边、右边的数的下标，-1表示不存在
每次删除后，将剩下的两部分连起来，当然也得特判下是否为空
*/

struct Node
{
    int val;
    int pos;
    bool operator<(const Node &r) const
    {
        return val<r.val;
    }
    Node(){}
    Node(int _val,int _pos):val(_val),pos(_pos){}
};

multiset<Node> mt;
int L[200001];
int R[200001];
int val[200001];
int kind[200001];

int main()
{
    ios::sync_with_stdio(false);
    int n,k,i,num=0,now;
    Node nd;
    multiset<Node>::iterator it;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
        L[i]=i-1,R[i]=i+1;
        mt.insert(Node(val[i],i));
    }
    L[1]=-1;
    R[n]=-1;
    while(!mt.empty())
    {
        ++num;
        now=((num&1)?1:2);
        it=mt.end();
        --it;
        nd=(*it);
        mt.erase(it);
        kind[nd.pos]=now;
        int Lp=nd.pos,Rp=nd.pos,temp=k;
        while(temp--)//删除右边的k个
        {
            Rp=R[Rp];
            if(Rp==-1)
            {
                break;
            }
            else
            {
                kind[Rp]=now;
                mt.erase(mt.find(Node(val[Rp],0)));
            }
        }

        temp=k;
        while(temp--)//删除左边的k个
        {
            Lp=L[Lp];
            if(Lp==-1)
            {
                break;
            }
            else
            {
                kind[Lp]=now;
                mt.erase(mt.find(Node(val[Lp],0)));
            }
        }
        //连接剩下的部分
        Rp=(Rp==-1?-1:R[Rp]);
        Lp=(Lp==-1?-1:L[Lp]);
        if(Lp!=-1)
        {
            R[Lp]=Rp;
        }
        if(Rp!=-1)
        {
            L[Rp]=Lp;
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d",kind[i]);
    }
    return 0;
}
