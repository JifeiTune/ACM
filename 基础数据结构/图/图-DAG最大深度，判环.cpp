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
n��Ա����������������ÿ��������100���ȴ���һϵ�й�ϵ��B->A��ʾA�Ľ���������B�� 
Ҫʹ�ܽ������٣��������Сֵ 

��ͼ���ڵ����Ա������ָ�򽱽�ߵģ����ͼ��DAG
��ô���Ǵ����Ϊ0�ĵ�������������������⣬�������һ�㣬��������1
ÿ��������ж����ȣ����������ɶ���·����ȡ���ֵ

����ԭ�⻹Ҫ�л�������ģ��һ����������Ĺ��̣�������ȡ��ɾ�߷�
�������ڵ�������n�����л� 
*/ 

vector<int> G[10001];
int In[10001];//���
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
        G[b].push_back(a);//a��b�ߣ�ָ����ߵĽ�ͼ
        In[a]++;
    }
    temp.val=100;
    for(i=1;i<=n;i++)
    {
        MAX[i]=100;
        if(In[i]==0)
        {
            temp.p=i;
            q.push(temp);//���Ϊ0�ĵ����
        }
    }
    while(!q.empty())
    {
        num++;//��¼����
        temp=q.front();
        q.pop();
        len=G[temp.p].size();
        MAX[temp.p]=max(MAX[temp.p],temp.val);//ȡ������
        for(i=0;i<len;i++)
        {
            to=G[temp.p][i];
            In[to]--;//��ȼ�һ
            if(In[to]==0)//���Ϊ0�������룬�ȴ����
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






