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
n����������ȡ����������
����ȡ�ĺͱ���Ϊk�ı���
�����������Ƕ���

��01�������ƣ�ÿ����Ҫô��Ҫô����
dp[i][j]��ʾ����ǰi����
���%k����jʱ������
ע���漰������һ�㶼����ȡ����
*/
int x[101];
int dp[101][101];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,ans,temp,n,k,t1,t2,MAX;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    memset(dp,-1,sizeof(dp));//-1�����״̬���ɴ�
    dp[0][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<k;j++)
        {
            if(dp[i-1][(j-x[i]%k+k)%k]!=-1)//�ţ���������ܴﵽ��״̬��
            {
                t1=dp[i-1][(j-x[i]%k+k)%k]+x[i];
            }
            else
            {
                t1=-1;
            }
            t2=dp[i-1][j];//����
            dp[i][j]=max(t1,t2);
        }
    }
    cout<<dp[n][0];
    return 0;
}
