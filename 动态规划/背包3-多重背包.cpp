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

ͬ������ѹ����һά����Ȼ��Ʒ����ȡ�����������Ӧ������������ö���أ�
��Ȼ��Ҫͬ01����һ������ö�٣���i״̬������i-1״̬����
��ȫ������Ҫ��������Ϊÿ����Ʒ�������޵ģ�����i״̬ʱ��Ӧ�����£���Ʒȡ�˶��ٸ���������ȡ
��01�����Ͷ��ر�������Ʒ�������޵ģ����ǲ�֪��i״̬ʱ��Ӧĳ�������õ����Ž�ʱ��i��Ʒȡ�˶��ٸ�
��Ȼ����������ȥ��¼���������鷳������ֻ�ܴ�i-1״̬�õ���һ����Ҫ���򣬷�����������ʱ
С���������Ž���i״̬�Ķ�����i-1״̬�ģ�����ظ�
*/

int dp[6001];
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
        dp[j]=0;//���ݵ��Ʊ��ʽ��ʼ���߽�
    }
    for(i=1;i<=n;i++)
    {
        for(j=all;j>=0;j--)//ö������
        {
            for(k=0;k<=num[i];k++)//ö��ȡ�ĸ���
            {
                temp=k*wei[i];
                if(j>=temp)
                {
                    dp[j]=max(dp[j],dp[j-temp]+k*val[i]);
                }
            }
        }

    }
    cout<<dp[all];
    return 0;
}

