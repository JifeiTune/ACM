#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<ctime>
#include<list>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

/*
POJ - 1182 食物链

快一年后再次做这个题，原题标解中关系通过相加和取余来得到不是太好理解，这里换成通用的关系转换矩阵
普通并查集，维护的是等价关系，对于其他复杂的关系，可以再开一个关系数组
代表当前节点对于代表元的关系，节点与节点间的关系可以通过分别与中间节点的关系来得到
再开一个关系映射数组即可
本题中有两类关系，一是“已经确定了相互关系”，普通方法就能解决
二是具体的关系“吃、被吃、同类”，可用0、1、2表示
其中吃与被吃是互反的，改变方向时互换一下即可，0与1通过异或1可变反

值得一提的是，这题用cin，关闭同步，超时…… 
*/
int x[50001];//代表元
int rel[50001];//指向代表元的关系

int trans[3][3]={{1,2,0},{2,0,1},{0,1,2}};//A对于B的关系为i，B对于C的关系为j时，A对于C的关系为trans[i][j]

int rev(int r)//关系取反
{
    if(r==2)
    {
        return 2;
    }
    return r^1;
}

int Find(int n)
{
    if(x[n]==n)
    {
        return n;
    }
    else
    {
    	int fa=x[n];//先记录父节点，否则路径压缩后会变
        x[n]=Find(x[n]);
        rel[n]=trans[rel[n]][rel[fa]];//该节点与代表元关系，通过父节点为中介得到
        return x[n];
    }
}

int main()
{
    int i,j,temp,len,ans=0,n,m,f1,f2,op,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        x[i]=i;
        rel[i]=2;//自己和自己是同类
    }
    while(m--)
    {
    	scanf("%d%d%d",&a,&b,&c);
        if(b>n||c>n)
        {
            ans++;
        }
        else
        {
            f1=Find(b);
            f2=Find(c);
            if(a==1)//同类
            {
                if(f1!=f2)//之前不知道二者关系，可以合并
                {
                    x[f2]=f1;
                    rel[f2]=trans[rev(rel[c])][rel[b]];
                }
                else
                {
                    if(rel[b]!=rel[c])//已经有关系，且不是同类
                    {
                        ans++;
                    }
                }
            }
            else//b吃c
            {
                if(f1!=f2)//之前不知道二者关系，可以合并
                {
                    x[f2]=f1;
                    temp=trans[rev(rel[c])][1];//f2与b的关系
                    rel[f2]=trans[temp][rel[b]];//f2与f1的关系
                }
                else
                {
                    if(trans[rel[b]][rev(rel[c])]!=0)//已经有关系，且不是b吃c
                    {
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
