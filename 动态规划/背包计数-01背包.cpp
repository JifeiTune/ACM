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
n����ͬ������ȡ�������ɸ���ʹ���Ϊall����ȡ���м���

01������������
������ԭ���������״̬ת�ƣ���״̬��Ӧ��ֵ����ܴﵽ��״̬������
ԭ��������Ҫ��״̬��ȡ��ֵ������ʱ���Ǹ���״̬��ֵ��� 
��dp[i][j]Ϊ���ǵ���i��ʱ����Ϊj��ȡ����
��Ȼ��ҪΪj����ô��ȡʱ������dp[i-1][j]��ȡʱ������dp[i-1][j-val[i]]����ͼ���
ͬ��ѹ��Ϊһά
*/

int dp[1001];//���ǵ�ǰ������Ϊi��ȡ����
int val[101];//��ֵ

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n;
    cin>>n>>all;
    for(i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    dp[0]=1;//û��������Ϊ0��һ�֣���ʲô����ȡ
    for(i=1;i<=n;i++)
    {
        for(j=all;j>=val[i];j--)
        {
            dp[j]+=dp[j-val[i]];
        }
    }
    cout<<dp[all];
    return 0;
}

