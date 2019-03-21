#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<list>

using namespace std;

/*
10*10的方格，有0和1，其中有1组成的曲线，围成的面积为其中0的个数，求这个面积
一般会想到找到曲线内部的点，做dfs求联通块中0的个数，但内部的点很难确定

反过来想，内部的0的个数就等于100减去外部的0个数和1的个数
而外部的0个数很好求，顺着方格外边界dfs即可 
*/


char x[11][11];
int ans;

void dfs(int Sh,int Sw)
{
    if(Sh>=1&&Sh<=10&&Sw>=1&&Sw<=10&&x[Sh][Sw]=='0')
    {
        x[Sh][Sw]='1';
        dfs(Sh+1,Sw);
        dfs(Sh-1,Sw);
        dfs(Sh,Sw+1);
        dfs(Sh,Sw-1);
    }
}

void out()
{
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            putchar(x[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
    putchar('\n');
}

int main()
{
    ios::sync_with_stdio(false);
    int i,n,j;
    ans=0;
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
        {
            scanf(" %c",&x[i][j]);
        }
    }
    for(i=1;i<=10;i++)
    {
        if(x[i][1]=='0')
        {
            dfs(i,1);

        }
        if(x[i][10]=='0')
        {
            dfs(i,10);

        }
        if(x[1][i]=='0')
        {
            dfs(1,i);

        }
        if(x[10][i]=='0')
        {
            dfs(10,i);

        }
    }
    ans=0;
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
        {
            if(x[i][j]=='0')
            {
                ++ans;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
