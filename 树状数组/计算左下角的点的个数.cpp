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
#include<ctime>

using namespace std;

/*
给出许多点的坐标，每个点的级别，定义为在之左下方，或者正左，正右的点的个数
问每个等级的点的数目
看似像个二维前缀和，即某个坐标有点，值就加一，最后统计每个点左下角矩形内的和
但是坐标范围大，二维开不了，又不想搞麻烦的离散化，怎么办？
其实问题可以转换成一维的，在其左下角，也就是在满足纵坐标小于等于时，横坐标也小于等于
所以如果将点按纵坐标升序排列，纵坐标相同时按横坐标升序排序
然后按序扫描，那么扫描到当前点时，计算之前的点中，横坐标小于等于它的点的个数即可
这种统计小于、大于其的点的个数的问题可用树状数组解决
本题输入已经排好序，一边读一边计算即可 
*/

#define lowbit(n) (n&(-n))

int num;//实际个数
int x[100010];
int level[100010];

void add(int p,int n)
{
    while(p<=num)
    {
        x[p]+=n;
        p+=lowbit(p);
    }
}

int sum(int p)
{
    int ans=0;
    while(p>0)
    {
        ans+=x[p];
        p-=lowbit(p);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,op,a,b,i,c;
    num=32010;
    memset(x,0,sizeof(x));
    memset(level,0,sizeof(level));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        ++a;//下标可能为0，加1
        ++level[sum(a)];
        add(a,1);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",level[i]);
    }
    return 0;
}




