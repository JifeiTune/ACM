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
n皇后问题，输入n，输出所有结果
ans[i]为第i行放的皇后所在列号
*/
int ans[100];
int num=1;
int n;

bool check(int H,int j)//H行j列放置是否可行
{
    int i;
    for(i=1;H-i>=1;i++)
    {
        if(ans[H-i]==j||ans[H-i]==j-i||ans[H-i]==j+i)
        {
            return 0;
        }
    }
    return 1;
}

void dfs(int H)//在第H行尝试放置
{
    int i,j;
    if(H==n+1)
    {
        printf("No. %d\n",num++);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d ",ans[i]==j?1:0);
            }
            putchar('\n');
        }
        return;
    }

    for(i=1;i<=n;i++)
    {
        if(check(H,i))
        {
            ans[H]=i;
            dfs(H+1);
        }
    }
}

int main()
{
    cin>>n;
    dfs(1);
}

