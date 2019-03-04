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

using namespace std;

/*
n��k�У�k>=n���ľ���
ÿ��ѡȡһ��Ԫ��
����2Ԫ�ز�����ͬһ�� 
Ҫʹ����Ԫ�صĺ����
������ͣ��Լ�·��

���Ʊ������⣬���ǵ�ĳһ�е�ĳһ��ʱ
��Ԫ����ѡ�Ͳ�ѡ2�ֿ��ܣ���¼��ÿ��ѡ������ֵ
dp[i][j]��ʾѡ��i��Ԫ�أ����ҿ��ǵ�j��ʱ�����ֵ
��dp[i][j]Ϊdp[i-1][j-1]+x[i][j]��ѡ����dp[i][j-1]����ѡ���е����ֵ 
ע����ƺ÷�Χ��x[i][j]����Ϊ���������Ա߽�����Ӧ����һ����Сֵ
Ҫ��ӡ·�����������״ֻ̬�ǡ����ǵ����������ǡ���֪��β��
��������vis���飬����ĳ��״̬ȡ����ʱ��x[i][j]�Ƿ�ѡ��
�����ݵ��Ʊ��ʽ�����Ʋ��ݹ��ӡ���� 
*/

int x[101][101];
int dp[101][101];//ǰi�п��ǵ�ǰj��ʱ�����ֵ
bool vis[101][101];//��ǰ����״̬���Ƿ�ȡj
int n,k;

void out(int H,int num)
{
    if(H>=1)
    {
        int j;
        for(j=k;j>=1;j--)
        {
            if(dp[H][j]==num&&vis[H][j])
            {
                out(H-1,num-x[H][j]);
                cout<<j<<' ';
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,p;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            cin>>x[i][j];
        }
    }
    MAX=0;
    memset(vis,0,sizeof(vis));
    dp[0][0]=0;
    for(i=1;i<=n;i++)
    {
        dp[i][i-1]=-99999;
        for(j=i;j<=(k-n+i);j++)
        {
            if(dp[i-1][j-1]+x[i][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j-1]+x[i][j];
                vis[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    cout<<dp[n][k]<<'\n';
    out(n,dp[n][k]);
    return 0;
}
