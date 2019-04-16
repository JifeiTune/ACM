#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

/*
在树上给出3点
需找出1点，使得3点到该点距离之和最小
输出该点和距离和

手玩样例发现，所要找的点是，两两求LCA，深度最大的那个LCA……
啊，好卡时间，最后加了输入输出挂才过……
*/

#define MAXN 500001
#define EXP 21//不小于log2(MAXN)

vector<int> Tree[MAXN];
int dep[MAXN];//点的深度
int up[MAXN][EXP];//up[i][j]表示i点出发，向上跳2^j所到的点，0就表示没有
int D=0;

void dfs(int n,int fa)//当前节点，当前节点父节点
{
    int len=Tree[n].size(),i,j,to;
    //遍历到了当前节点，就表示已经遍历完了根到该点路径上的点，所以可以直接更新当前点的up
    for(j=1;(1<<j)<=dep[n];j++)//能跳多少取决于其深度
    {
        //当前点跳2^j等于先跳2^(j-1)，再跳2^(j-1)
        up[n][j]=up[up[n][j-1]][j-1];
    }

    for(i=0;i<len;i++)
    {
        to=Tree[n][i];
        if(to!=fa)//别搜回去了
        {
            dep[to]=dep[n]+1;
            D=D>dep[to]?D:dep[to];
			up[to][0]=n;//先更新深度和距离，以及up边界
            dfs(to,n);
        }
    }
}

int LCA(int a,int b)//求a与b的最近公共祖先
{
    int h,i,j;
    h=dep[a]-dep[b];//为了让a和b处于同一深度所要跳跃的点
    if(dep[a]<dep[b])
    {
        swap(a,b);//让a为深度更大的点
        h=-h;
    }
    i=0;
    while(h>0)//h的二进制上为1的位权都是要跳跃的
    {
        if(h&1)
        {
            a=up[a][i];//当前位权为2^i
        }
		++i;
		h>>=1;//右移1位
    }
    if(a==b)
    {
        return a;//已经为同一点了，说明2点原来在同一条根出发的路径上
    }
    /*
    此时说明原来2点在不同的根出发的路径上，一起向上跳，正好跳到同一点即为LCA
    我们不知道还要向上跳多少，所以只能贪心地构造所跳步数的二进制数
    从高位开始尝试，如果跳该位权正好不会调至相同，就跳
    */
    for(j=D;j>=0;j--)
    {
        if(up[a][j]!=up[b][j])//不等就跳
        {
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];//还差一步
}

inline void in(int &ret)
{
	char c;
	int sgn;
	c=getchar();
	while((c<'0'||c>'9')) c=getchar();
	ret=c-'0';
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
}

inline void out(int x)
{
	if(x>9) out(x/10);
	putchar(x%10+'0');
}

int main()
{

    int n,q,a,b,c,i,j,temp,ans,MAX=0,ab,ac,bc;
    scanf("%d%d",&n,&q);
    for(i=1;i<n;i++)
    {
        in(a),in(b);
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    dep[1]=0;
    dfs(1,-1);//假设以1为根
    D=log2(D)+1;
    while(q--)
    {
        in(a),in(b),in(c);
        ab=LCA(a,b);
        ac=LCA(a,c);
        bc=LCA(b,c);
        temp=ab;
        MAX=dep[ab];
        if(dep[ab]<dep[ac])
        {
            temp=ac;
            MAX=dep[ac];
        }
        if(dep[bc]>MAX)
        {
            temp=bc;
        }
        out(temp),putchar(' ');
        out(dep[a]+dep[b]+dep[c]-dep[ab]-dep[ac]-dep[bc]);
        putchar('\n');
    }
    return 0;
}
