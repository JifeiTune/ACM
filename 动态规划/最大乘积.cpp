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
n�����������в���k��k<n-1�����˺�
���ܵ����ֵ

��dp[i][j]Ϊǰi��������j���˺�ʱ�����ֵ
��dp[i][j]ͨ��ö��dp[t][j-1]��t<i���ڳ���[t+1,i]��ɵ����õ�
���е����ֵ��Ϊ����
*/

long long dp[20][20];//ǰi������j���˺����ֵ
long long val[20][20];//[i,j]��ɵ�����ֵ
char x[20];

int main()
{
    ios::sync_with_stdio(false);
    int n,k,i,j,t;
    long long MAX;
    cin>>n>>k;
    cin>>(x+1);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        val[i][i]=x[i]-'0';
        for(j=i+1;j<=n;j++)
        {
            val[i][j]=val[i][j-1]*10+x[j]-'0';
            //printf("%d %d %lld\n",i,j,val[i][j]);
        }
        dp[i][0]=val[1][i];
    }
    for(i=2;i<=n;i++)//��β
    {
        for(j=1;j<i;j++)//�˺Ÿ���
        {
            MAX=0;
            for(t=j;t<i;t++)//�ָ��
            {
                MAX=max(MAX,dp[t][j-1]*val[t+1][i]);
            }
            dp[i][j]=MAX;
        }
    }
    cout<<dp[n][k];
    return 0;
}
