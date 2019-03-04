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
��ȫ����
�����01������ÿ����Ʒ��������
��򵥵ģ�ת����01��������ÿ����Ʒ��ɣ���������/��Ʒ����������Ʒ
������̫����

ͬ����dp[i][j]Ϊ���ǵ�ǰi����Ʒ����������Ϊjʱ������ֵ
ÿ����Ʒ���ԷŶ��
����j>=wei[i]ʱ������Ƿţ�״̬Ӧ��i������������i-1
��Ϊ֮ǰ���ܾͷ������ɸ�i��Ʒ
�ʴ�ʱdp[i][j]Ϊdp[i-1][j]����ȫ���ţ���dp[i][j-wei[i]]+val[i]���ţ��е����ֵ
ͬ��dp����Ҳ�ɽ�Ϊ1ά����ʱjӦ�ô�С����ѭ��
*/

int dp[31][201];
int val[31];//��ֵ
int wei[31];//����

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n,t1,t2;
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
            t1=dp[i][j-wei[i]]+val[i];//��
            t2=dp[i-1][j];//����
            dp[i][j]=max(t1,t2);
        }
    }
    cout<<"max="<<dp[n][all];
    return 0;
}

