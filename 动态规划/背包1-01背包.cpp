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
01����
ÿ������Ҫô��Ҫô����
dp[i][j]Ϊ���ǵ�ǰi����Ʒ����������Ϊjʱ������ֵ
��dp[i][j]����dp[i-1][j]�����ţ���dp[i-1][j-wei[i]]+val[i]���ţ��е����ֵ

���Է���dp[i][k1]������dp[i][k2]�õ����ʿ��Ż��ռ䣬��Ϊ1ά
��Ҫע�⣬��ʱ������ѭ��Ӧ�����򣬼�all->wei[i]
��Ϊ�����������Ҫ�õ�ǰһ״̬��i-1��С���������Ž⣬���˳����
С�����Ľⱻ�滻�ɵ�ǰ״̬��i����Ӱ�������ʱ�����

���Ҫ�󱳰������������ô״̬������Ҳ��Ϊ���÷���
��ʼ��ʱ��dp[0][0]=0�����ɴ�״̬��Ϊ��Сֵ��dp[0][k]��k>=1��
����������ֻҪ�пɴ�״̬��max�б�Ȼ���Լ�Сֵ
*/

int dp[31][201];
int val[31];//��ֵ
int wei[31];//����

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n;
    cin>>all>>n;
    for(i=1;i<=n;i++)
    {
        cin>>wei[i]>>val[i];
    }
    for(j=0;j<=all;j++)
    {
        dp[0][j]=0;//���ݵ��Ʊ��ʽ��ʼ���߽�
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<wei[i];j++)//��ʱֻ�ܲ���
        {
            dp[i][j]=dp[i-1][j];
        }
        for(j=wei[i];j<=all;j++)//��ʱ�ɷſɲ���
        {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-wei[i]]+val[i]);
        }
    }
    cout<<dp[n][all];
    return 0;
}

