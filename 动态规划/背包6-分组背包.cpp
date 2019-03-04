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
���鱳��
�����01������ÿ����Ʒ��������һ����
ͬһ�����Ʒֻ��ѡһ��

״̬��һ�£�dp[i][j]��ʾΪ���ǵ�ǰi���顱������Ϊjʱ������ֵ
���01������
*/

int dp[31][201];
int val[31];//��ֵ
int wei[31];

vector<int> x[11];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,num,k,len,temp,MAX,all,n;
    cin>>all>>n>>T;
    for(i=1;i<=n;i++)
    {
        cin>>wei[i]>>val[i]>>num;
        x[num].push_back(i);
    }
    for(j=0;j<=all;j++)
    {
        dp[0][j]=0;//���ݵ��Ʊ��ʽ��ʼ���߽�
    }
    for(i=1;i<=T;i++)//ö�����
    {
        for(j=0;j<=all;j++)
        {
            len=x[i].size();
            dp[i][j]=dp[i-1][j];//����һ������ѡ
            for(k=0;k<len;k++)//������ѡ����һ��
            {
                if(j>=wei[x[i][k]])
                {
                    temp=dp[i-1][j-wei[x[i][k]]]+val[x[i][k]];
                    dp[i][j]=max(dp[i][j],temp);
                }
            }
        }
    }
    cout<<dp[T][all];
    return 0;
}
