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

//n��Ԫ�ػ�����k������(k<=n)���м��ֻ��ַ���

long long dp[31][31];//dp[i][j]��ʾi��Ԫ�ػ�����j������ʱ�ķ�����


int main()
{
    int i,j,n,k;
    memset(dp,0,sizeof(dp));
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        dp[i][1]=1;//�߽�
        for(j=2;j<=i&&j<=k;j++)
        {
            dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];//����һ���ǿռ��ϣ����߷���һ���ռ���
        }
    }
    cout<<dp[n][k];
    return 0;
}



