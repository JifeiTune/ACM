#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
/*
2018北京网络赛B题
求n个环形串的最长公共子序列，若有多个，输出字典序最小的
n<=10，串长<=8
数据量非常小，直接枚举每个环形字符串的起始，再枚举每一个子序列
存在n个set中，最后取交集即可
*/
using namespace std;

set<string> all[10];
int N;
char x[20];

void Enum(int len,int p)//枚举当前长为len的环形字符串的子序列，存于all[p]
{
    int i,j,k,tem;
    string str;
    for(i=0;i<len-1;i++)
    {
        x[len+i]=x[i];//倍增
    }
    for(i=0;i<len;i++)//以i为起点在长为len的子串中枚举子序列
    {
        tem=(1<<len)-1;
        for(j=1;j<=tem;j++)
        {
            str="";
            for(k=0;k<len;k++)
            {
                if(j&(1<<k))
                {
                    str.push_back(x[i+k]);
                }
            }
            all[p].insert(str);
        }
    }
}

int main()
{
    int i,len,MAX;
    set<string> tem;
    L:while(~scanf("%d",&N))
    {
        for(i=0;i<N;i++)
        {
            all[i].clear();
            scanf("%s",x);
            len=strlen(x);
            Enum(len,i);
        }
        tem=all[0];
        for(i=1;i<N;i++)//两两求交集
        {
            tem.clear();
            set_intersection(all[i-1].begin(),all[i-1].end(),all[i].begin(),all[i].end(),inserter(tem,tem.begin()));
            if(tem.size()==0)
            {
                printf("0\n");
                goto L;
            }
            swap(tem,all[i]);
        }
        set<string>::iterator it=all[N-1].begin(),pos;
        MAX=0;
        //cout<<all[N-1].size();
        while(it!=all[N-1].end())
        {
            if((*it).length()>MAX)
            {
                pos=it;
                MAX=(*it).length();
            }
            ++it;
        }
        cout<<*pos<<'\n';
    }
    return 0;
}




