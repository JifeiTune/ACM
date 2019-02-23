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
矩阵的值定义为所有元素的和
求最大子矩阵的值

涉及到求和，肯定要使用前缀和加速求解
若枚举左上角和右下角，复杂度为O(N^4)

若将矩阵进行行压缩或列压缩，假设进行行压缩
则枚举列的起始和结束，一行压缩成一个数
转换成在行的方向求最大子段和
总的复杂度降为O(N^3)
*/

int x[101][101];
int sum[101][101];//每行的前缀和

#define getV(k,i,j) (sum[k][j]-sum[k][i-1])

int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,k,MAX,p,last,ans;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        sum[i][0]=0;
        for(j=1;j<=n;j++)
        {
            cin>>x[i][j];
            sum[i][j]=sum[i][j-1]+x[i][j];
        }
    }
    if(n==1)
    {
        cout<<x[1][1];
        return 0;
    }
    ans=0;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)//枚举列的起始和终点
        {
            last=0;
            for(k=1;k<=n;k++)//求最大子段和
            {
                if(last>0)
                {
                    last+=getV(k,i,j);
                }
                else
                {
                    last=getV(k,i,j);
                }
                ans=max(ans,last);
            }
        }
    }
    cout<<ans;
    return 0;
}
