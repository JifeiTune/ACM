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
һ��ʯ�Ӷѣ�ÿ�ο��Ժϲ���������
�ϲ��Ļ����������ܵ�ʯ����
���Ҫ�ϲ���һ�ѣ����ܵ���С����

�������һ�κϲ�����Ȼ��[1,k],[k,N]�ϲ�
����Ϊ�ϲ���[1,k]��[k,N]����Сֵ֮��
�ټ��ϣ�[1,N]���ܵ�ʯ����

����ϲ���[1,k]��[k,N]����Сֵ��֪��
��ö��k������
�Ժϲ���[1,k]��[k,N]��Сֵ�����Ҳһ��
�ݹ�+dp���
*/

int dp[101][101];//dp[i][j]��ʾ��i��j��ʯ�ӶѺϲ���һ��ʱ����С����
int sum[101];//ǰ׺�ͣ�������i��j��ʯ������

int solve(int L,int R)
{
    if(dp[L][R]!=-1)
    {
        return dp[L][R];
    }
    int k,i,j,temp,ans=0x7fffffff;
    for(k=L;k<R;k++)
    {
        temp=solve(L,k)+solve(k+1,R);
        ans=min(ans,temp);
    }
    dp[L][R]=ans+sum[R]-sum[L-1];
    return dp[L][R];
}

int main()
{
    ios::sync_with_stdio(false);
    int N,i,ans=1;
    cin>>N;
    sum[0]=0;
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=N;i++)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
        dp[i][i]=0;//ͬһ��ʯ������ϲ�������Ϊ0
    }
    cout<<solve(1,N);
    return 0;
}
