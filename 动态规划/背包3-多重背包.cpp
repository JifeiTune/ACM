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
���ر���
�����01������ÿ����Ʒ����Ҳһ���������ܳ���1��
01������״̬ת����ȡ�Ͳ�ȡ����ʵ����ȡ0����1��
���ر����У�ö��ȡ0-num[i]������

�Ż�
*/

int dp[501][6001];
int val[501];//��ֵ
int wei[501];//����
int num[501];//����

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n,k,t1,t2;
    cin>>n>>all;
    for(i=1;i<=n;i++)
    {
        cin>>wei[i]>>val[i]>>num[i];
    }
    for(j=0;j<=all;j++)
    {
        dp[0][j]=0;//���ݵ��Ʊ��ʽ��ʼ���߽�
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=all;j++)//ö������
        {
            dp[i][j]=0;
            for(k=0;k<=num[i];k++)//ö��ȡ�ĸ���
            {
                temp=k*wei[i];
                if(j>=temp)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-temp]+k*val[i]);
                }
            }
        }

    }
    cout<<dp[n][all];
    return 0;
}

