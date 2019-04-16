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
从节点带权值的森林中，选择m个节点，要求是，选择某个节点，其父节点必须选，一次类推
即选了一个点，从根至它路径上的点都必须被选
问选取的权值和最大是多少

原图是森林，为方便，新增一个虚根，原森林中所有根都为其子节点，这样就能统一在一棵树上解决
考虑以i为根的一棵子树，假设在子树中选j个点，最大值为dp[i][j]
想要选择左右子树上的点，必须选择i，然后在所有子节点中选j-1个
子树节点太多，难以分配怎么办？转二叉树
多叉树转二叉树，即转换成左孩子右兄弟表示法
转换后每个节点的左子节点为原树中的孩子，右子节点为原树中的兄弟（有相同父节点）
对二叉树进行搜索，回溯时，左右子树已求解
然后考虑2种情况：
1.选本节点，选了后才能选左子树，然后剩下的在左右子节点分配
2.不选本节点，那只能在右子树选取
当然，都要防止左右子树不存在，0节点（虚拟节点）也要单独考虑，因为不选它也能选左节点
dp[i][j]在求解过程中，可能求了不存在的垃圾状态，不过不影响，因为在max的过程中会被忽略
不会影响最终结果
*/

int L[101];//左孩子
int R[101];//右兄弟
int val[101];//每个节点权值
int dp[101][101];//二叉树上，考虑到i节点，选j个时的最大值
int n,m;//总节点数和可选节点数

void addE(int fa,int ch)//根据父子关系更新左孩子右兄弟表示
{
    R[ch]=L[fa];//fa的旧孩子变成新孩子的兄弟
    L[fa]=ch;//更新fa的直达孩子
}

void dfs(int now)
{
    int lc=L[now],rc=R[now],i,j,t1,t2,t3;
    if(lc!=-1) dfs(lc);
    if(rc!=-1) dfs(rc);//先处理左右子树
    for(i=1;i<=m;i++)//在以本节点为根的子树中，选i个
    {
        t1=0,t2=0;
    	if(now==0)//虚拟节点0单独考虑，可以不选它但选左子树
		{
			for(j=0;j<=i;j++)
			{
				t1=max(t1,(lc==-1?0:dp[lc][j])+(rc==-1?0:dp[rc][i-j]));
			}
			dp[now][i]=t1;
		}
		else
		{
			//本节点选，选了才能考虑左子树
	        for(j=0;j<=i-1;j++)//枚举左子树选j，则右子树选i-1-j
	        {
	            //要防止无子树，若无置为0
	            t1=max(t1,(lc==-1?0:dp[lc][j])+(rc==-1?0:dp[rc][i-1-j]));
	        }
	        t1+=val[now];//本节点加上
	        //不选本节点，只能考虑右子树
	        t2=(rc==-1?0:dp[rc][i]);//全在右子树选，但要防止没有
	        dp[now][i]=max(t1,t2);
		}

    }
}

int main()
{
    ios::sync_with_stdio(false);
    memset(L,-1,sizeof(L));
    memset(R,-1,sizeof(R));
    memset(dp,0,sizeof(dp));
    int i,j,dis,fa;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&fa,&val[i]);
        if(fa==0)//没有父节点，虚设一个0节点为父节点
        {
            addE(0,i);
        }
        else
        {
            addE(fa,i);
        }
    }
    val[0]=0;
    dfs(0);
    printf("%d",dp[0][m]);
    return 0;
}
/*
3 3
0 1
1 2
1 3

*/



