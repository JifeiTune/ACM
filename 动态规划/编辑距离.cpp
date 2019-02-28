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
#include<queue>

using namespace std;

/*
�ַ���A��B���༭����Ϊ��A��ΪB����С�༭����
ÿ�α༭���ԣ�ɾ����������޸�һ���ַ�
��༭����

��dp[i][j]��ʾ��A[1,i]ת����B[1,j]����С�༭�������±��1��ʼ��
ע���������״̬�Ƕ���ԭ����˵�ģ��������޸ĺ󣨿��ܱ�̡��䳤��
���̬dp[k][0]=k,dp[0][k]=k������һ����Ϊ�գ�
֮����dp[i][j]ʱ��������3��ת����ʽ
1���޸ģ���A[i]==B[j]�������޸ģ��͵���dp[i-1][j-1]���������1
2��ɾ��A[i]��ɾ�������dp[i-1][j]��A[1,i-1]�Ѿ�ת����B[1,j]��A[i]���ࣩ����ɾ��������1
3������B[j]��A[i]λ�ã�Ϊdp[i][j-1]��A[1,i]�Ѿ�ת����B[1,j-1]����ȱB[j]�����ϲ��������1
ȡ���ߵ���Сֵ����
*/


char A[2001];
char B[2001];

int dp[2001][2001];

int main()
{
    ios::sync_with_stdio(false);
    int T,i,j,ans,temp,n,k,lenA,lenB,t1,t2,t3,MAX;
    cin>>(A+1)>>(B+1);
    lenA=strlen(A+1);
    lenB=strlen(B+1);
    for(i=0;i<=lenA;i++)
    {
        dp[i][0]=i;
    }
    for(j=0;j<=lenB;j++)
    {
        dp[0][j]=j;
    }
    for(i=1;i<=lenA;i++)
    {
        for(j=1;j<=lenB;j++)
        {
            t1=dp[i-1][j-1]+(A[i]==B[j]?0:1);//�޸�
            t2=dp[i-1][j]+1;//ɾ��
            t3=dp[i][j-1]+1;//����
            MAX=min(t1,t2);
            MAX=min(MAX,t3);
            dp[i][j]=MAX;
        }
    }
    cout<<dp[lenA][lenB];
    return 0;
}
