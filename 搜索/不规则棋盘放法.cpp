#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/*
棋盘长与宽为N
为'#'的位置才可放置棋子
任意两个棋子不能同行或同列
放M(M<=N)个棋子，问放法数

解法近似N皇后，不同之处在于M可能小于N
所以对于每行，分放与不放讨论
*/
char x[101][101];
int H,W,ans;
bool vis[101];//某一列是否被放置

void dfs(int c,int num)//当前处于c行，需摆放num个棋子
{
    if(num==0)//成功达成一种方案
    {
        ++ans;
        return;
    }
    if(c>H)
    {
        return;
    }
    int i;
    for(i=1;i<=W;i++)//本层放置才考虑下一层
    {
        if(x[c][i]=='#'&&(!vis[i]))//i列可放置
        {
            vis[i]=1;
            dfs(c+1,num-1);
            vis[i]=0;//恢复
        }
    }
    dfs(c+1,num);//忽略本层
}

int main()
{
    int T,i,j,num;
    while(scanf("%d%d",&H,&num))
    {
        if(H==-1)
        {
            break;
        }
        W=H;
        for(i=1;i<=H;i++)
        {
            for(j=1;j<=W;j++)
            {
                scanf(" %c",&x[i][j]);
            }
        }
        memset(vis,0,sizeof(vis));
        ans=0;
        dfs(1,num);
        printf("%d\n",ans);
    }
    return 0;
}
