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
��n��ƻ������k�����ӣ���������������Ϊ��
���Ӳ���˳����1,3��3,1��ͬһ�ַ���

����ڹ̶�λ�����������֣�������Ϊ0�����
�Կɲ���dp���

��dp[i][j]��ʾ��i��ƻ������j�����ӵķŷ�
1.��i<jʱ����Ȼ����������Ϊ�գ���Ϊ����˳�����Կ����j������Ϊ��
��i������ǰj-1�����ӣ���dp[i][j]=dp[i][j-1]
2.i>=jʱ����ȹ̶�λ�����������֣�Ҳ��ȫΪ�ǿպʹ��ڷǿ�2�����
��dp[i][j]=dp[i-j][j]+dp[i][j-1]
*/

long long dp[21][21];//dp[i][j]��ʾi��Ԫ�ػ�����j������ʱ�ķ�����


int main()
{
    ios::sync_with_stdio(false);
    int i,j,n,k,T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        dp[0][0]=1;
        for(i=1;i<=n;i++)
        {
            dp[0][i]=1;
            dp[i][1]=1;
            for(j=2;j<=k;j++)
            {
                if(i<j)
                {
                    dp[i][j]=dp[i][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-j][j]+dp[i][j-1];
                }
            }
        }
        cout<<dp[n][k]<<'\n';
    }

    return 0;
}

