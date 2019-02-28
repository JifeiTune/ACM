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
һ������������ÿ��������һ����
ÿ��ֻ�����º����ߣ��ߵ�ĳ�����Ӻ����ȡ�����ϵ�����ȡ�ߺ���Ϊ0
���Ⱥ���2�Σ��ܵ��ջ����ֵ����

ֻ�����º������ߣ������dp����������һ�Σ��ܺý��
��2�Σ��ؼ����ǵڶ��ο����ߵ���һ���Ѿ�ȡ���˵�����
����2��״̬��dp����Ϊ4ά������������ͬʱ�ߵ�

ÿ���㶼���ܴ����������������4�����
��������غϣ����غϻ��м�ȥ
*/

int x[11][11];
int dp[11][11][11][11];//��һ��·���ߵ�x[i][j]���ڶ���·���ߵ�x[t1][t2]ʱ�����ֵ

int main()
{
    ios::sync_with_stdio(false);
    int T,i,j,ans,temp,n,k,lenA,lenB,t1,t2,MAX,a,b,c;
    memset(x,0,sizeof(x));
    cin>>n;
    while(cin>>a>>b>>c)
    {
        if(a==0)
        {
            break;
        }
        x[a][b]=c;
    }
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(t1=1;t1<=n;t1++)
            {
                for(t2=1;t2<=n;t2++)
                {
                    dp[i][j][t1][t2]=max(dp[i-1][j][t1-1][t2],dp[i-1][j][t1][t2-1]);
                    dp[i][j][t1][t2]=max(dp[i][j][t1][t2],dp[i][j-1][t1-1][t2]);
                    dp[i][j][t1][t2]=max(dp[i][j][t1][t2],dp[i][j-1][t1][t2-1]);
                    dp[i][j][t1][t2]+=x[i][j]+x[t1][t2];//���ϵ�ǰ2����ȡ��
                    if(i==t1&&j==t2)
                    {
                        dp[i][j][t1][t2]-=x[i][j];//�����غϣ�ֻ��һ��
                    }
                }
            }
        }
    }
    cout<<dp[n][n][n][n];
    return 0;
}
