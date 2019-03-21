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
��ά���õı������൱����ͨ��������������һά
�ǵ�Ȼ��״̬Ҳ�ඨ��һά�����ˣ���Ҫע����ǣ��������κܶ࣬��һ����������������ƣ�����������������
���籾�⣬��������ޣ�ÿ�����޺���һ�������͵�������һ������
���������͵��ֱ�������Сֵ������£�����С������
�������͵���������Ҫ���٣�������ͨ����һ��������಻�ܳ�������
�������ȫ����ͨ�����������������ȼ���ȫȡ��Ȼ��ת��Ϊɾȥ��������
���ֱ��������dp[i][j]Ϊ�����ǵ���ǰ����ʱ����������i��jʱ����С����
���i��j�õ�ǰ���޶������㣬��ֱ�Ӹ�����Сֵ������������ǰһ�������״̬���������ۼ���
*/

int dp[100][100];//��������i��jʱ����С����
int n,m,INF=0x3f3f3f3f;
int O[1001];
int N[1001];
int wei[1001];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,num,k;
    cin>>n>>m>>num;
    for(i=1;i<=num;i++)
    {
        cin>>O[i]>>N[i]>>wei[i];
    }
    memset(dp,0x3f,sizeof(dp));
    for(i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }
    for(k=1;k<=num;k++)
    {
        for(i=n;i>=1;i--)
        {
            for(j=m;j>=1;j--)
            {
                /*
                ��ÿ�ֹ��Ͳ������ۣ�ע����ڲ��������������ʵ���Ժϲ�
                */
                if(O[k]>=i&&N[k]>=j)//���˻��ж�
                {
                    dp[i][j]=min(dp[i][j],wei[k]);
                }
                else if(O[k]<i&&N[k]<j)//���߶�������Ҫ����ǰһ״̬
                {
                     dp[i][j]=min(dp[i][j],dp[i-O[k]][j-N[k]]+wei[k]);
                }
                else if(O[k]<i)//������
                {
                    dp[i][j]=min(dp[i][j],dp[i-O[k]][j]+wei[k]);
                }
                else//������
                {
                    dp[i][j]=min(dp[i][j],dp[i][j-N[k]]+wei[k]);
                }
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
