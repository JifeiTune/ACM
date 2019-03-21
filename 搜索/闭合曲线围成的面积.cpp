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
10*10�ķ�����0��1��������1��ɵ����ߣ�Χ�ɵ����Ϊ����0�ĸ�������������
һ����뵽�ҵ������ڲ��ĵ㣬��dfs����ͨ����0�ĸ��������ڲ��ĵ����ȷ��

�������룬�ڲ���0�ĸ����͵���100��ȥ�ⲿ��0������1�ĸ���
���ⲿ��0�����ܺ���˳�ŷ�����߽�dfs���� 
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
