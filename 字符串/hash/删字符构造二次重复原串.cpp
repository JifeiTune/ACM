#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<set>
using namespace std;

/*
给定一个字符串，问是否能删除其中一个字符，使得剩下的部分为SS的形式，即一个字符串复制成2份
输出S，若能使得S不唯一，需加说明

先对原串hash，求好前缀和
然后枚举删除位，并将剩下的字符串分2份，每份采取相同的hash
也就是在原hash上调整，使得对应位位权相等，求得新hash后判断是否相等
至于判断S的唯一性，控制整体的hash方式相同，每次得到一个解，将hash值放入set
当set元素个数超过1时表示不唯一
*/

char x[2000005];

typedef unsigned int ui;

ui base=131;
ui pre[2000005];
ui pow[2000005];//base^i
set<ui> all;

int main()
{
    int len,i,mid,p=-1;
    ui temp,L,R;
    pow[0]=1;
    scanf("%d%s",&len,x+1);
    if((len&1)==0||len==1)
    {
        puts("NOT POSSIBLE");
        return 0;
    }
    for(i=1;i<=len;i++)
    {
        pow[i]=pow[i-1]*base;
    }
    temp=base;
    pre[0]=x[0];
    for(i=1;i<=len;i++)//这样hash位权小的在左边
    {
        pre[i]=pre[i-1]+pow[i]*x[i];
    }
    mid=len/2+1;
    for(i=1;i<mid;i++)//被删除位在左半部分
    {
        L=(pre[mid]-pre[i])*pow[mid-1]+pre[i-1]*pow[mid];
        R=pre[len]-pre[mid];
        if(L==R)
        {
            all.insert(R);
            p=i;
            if(all.size()>1)
            {
                puts("NOT UNIQUE");
                return 0;
            }
        }
    }
    L=pre[mid-1]*pow[mid];
    R=pre[len]-pre[mid];
    if(L==R)
    {
        all.insert(R);
        p=mid;
        if(all.size()>1)
        {
            puts("NOT UNIQUE");
            return 0;
        }
    }
    for(i=mid+1;i<=len;i++)
    {
        L=pre[mid-1]*pow[mid];
        R=(pre[i-1]-pre[mid-1])*base+(pre[len]-pre[i]);
        if(L==R)
        {
            all.insert(R);
            p=i;
            if(all.size()>1)
            {
                puts("NOT UNIQUE");
                return 0;
            }
        }
    }
    if(p==-1)
    {
        printf("NOT POSSIBLE");
        return 0;
    }
    --mid;
    for(i=1;i<=len&&mid!=0;i++)
    {
        if(i!=p)
        {
            putchar(x[i]);
            --mid;
        }
    }
    return 0;
}
