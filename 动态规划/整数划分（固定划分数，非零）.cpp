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
����n���ֳ�k�ݣ�k�ݵĺ�Ϊn�����ֺ󲻼�˳����1,3��3,1��ͬһ�����֣�
�ʻ�������

��dp[i][j]��ʾ��i���ֳ�j�ݵĻ�����
��i<jʱΪ0��i==jʱΪ1
i>jʱ����j�ݶ�>1�����Ȼ���Ϊj��1��ʣ�µ�i-j�ٷֳ�j��
������==1�ģ� ���Ƚ�i-1�ֳ�j-1�ݣ�ʣ�µ�1�Գ�1��
��dp[i][j]=dp[i-j][j]+dp[i-1][j-1]
*/

long long dp[201][7];//dp[i][j]��ʾi��Ԫ�ػ��ֳ�j�ݵķ�����


int main()
{
    int i,j,n,k;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        dp[i][1]=1;//�ֳ�1��ֻ��1�ַַ�
        for(j=2;j<=i&&j<=k;j++)
        {
            if(i<j)
            {
                dp[i][j]=0;
            }
            else if(i==j)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
            }
        }
    }
    cout<<dp[n][k];
    return 0;
}


