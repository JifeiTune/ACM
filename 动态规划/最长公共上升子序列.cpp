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
����������������У�������Ⱥ͸�����
�������ĵ�

���⻹Ҫ��֮�������
��last[i]����ʾ���Ž�ʱĳ��Ԫ�ص�ǰһ��Ԫ��
dp���̸��¼���
*/

int A[501];
int B[501];
int dp[501][501];//dp[i][j]��ʾ��A[i]��B[j]��βʱ����������������г���
int last[501];//���Ž�ʱ��һ���㣨B�У�

void out(int p)
{
    if(last[p]!=p)
    {
        out(last[p]);
    }
    cout<<B[p]<<' ';
}

int main()
{
    int i,j,MAX,ans,lenA,lenB,End,p;
    cin>>lenA;
    for(i=1;i<=lenA;i++)
    {
        cin>>A[i];
        dp[i][0]=0;
    }
    cin>>lenB;
    for(i=1;i<=lenB;i++)
    {
        cin>>B[i];
        dp[0][i]=0;
        last[i]=i;
    }
    dp[0][0]=0;
    ans=0;
    for(i=1;i<=lenA;i++)
    {
        MAX=0;
        for(j=1;j<=lenB;j++)
        {
            if(A[i]!=B[j])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=MAX+1;
                last[j]=MAX>0?p:j;//ֻ�ڻ�����ʱ����ǰһ���±�
            }
            if(dp[i][j]>ans)
            {
                ans=dp[i][j];
                End=j;//�������Ž����һ��Ԫ������
            }
            if(A[i]>B[j]&&dp[i][j]>MAX)
            {
                MAX=dp[i][j];
                p=j;//��¼�±�
            }
        }
    }
    cout<<ans<<'\n';
    if(ans>0)
    {
        out(End);
    }
    return 0;
}


