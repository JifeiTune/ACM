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
��n����ֵ�Ļ��ң�Ҫ�������all���м���ȡ��

��ȫ�������������01���������������ȫ�����󷨼���
�����ܴ󣬿�long long 
*/

long long dp[1000001];
int x[1001];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,n,all;
    cin>>n>>all;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    dp[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=x[i];j<=all;j++)//ע��Ҫ������Ϊ�����㹻ʱ��i״̬��i״̬����
        {
            dp[j]+=dp[j-x[i]];
        }
    }
    cout<<dp[all];
    return 0;
}

