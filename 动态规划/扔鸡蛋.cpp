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
n��¥��k����ͬӲ�ȵļ���
�ʲ�ȡ���Ų���ʱ�������£��Ӽ��β���ȷ��������Ӳ��
ע�����輦��Ӳ��Ϊm����m�����²��ƣ�m�����������ƣ����˵ĵ�Ȼ�޷�������

ע�⵽���¸���ʵ��
ͬ�����������ȷ��[1,1+x]�����Ĳ㿪ʼ����
��ȷ��[k,k+1]�����Ĳ���ƣ��ӵ����ٴ���һ������ֻ�����䳤���й�
��ÿһ����ʱ�������ƺͲ���2�ֿ��ܣ��ֱ�ת�Ƶ�����2������
ÿ�ζ�Ҫ������2���������Ϊ��������������ȡ���ֵ

��dp[i][j]Ϊ��i��¥������j��������̽��Ӳ�ȵ����Ž�
��dp[i][j]=min(dp[i][j],max(dp[i-t][j]+1,dp[t-1][j-1]+1))
tΪö�ٵ����²���
*/

int dp[101][11];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,n,k,t,temp1,temp2;
    while(cin>>n>>k)
    {
        for(i=1;i<=n;i++)
        {
            dp[i][1]=i;
        }
        for(i=1;i<=k;i++)
        {
            dp[0][i]=0;
            dp[1][i]=1;
        }
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=k;j++)
            {
                dp[i][j]=0x7fffffff;
                for(t=1;t<=i;t++)//ö�������
                {
                    temp1=dp[i-t][j]+1;//û��
                    temp2=dp[t-1][j-1]+1;//����
                    temp1=max(temp1,temp2);
                    dp[i][j]=min(dp[i][j],temp1);
                }
            }
        }
        cout<<dp[n][k]<<'\n';
    }
    return 0;
}

