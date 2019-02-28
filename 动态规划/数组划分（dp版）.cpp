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
����Ϊn������ֳ�������k��
ÿ�ε�ֵΪ����Ԫ��֮��
Ҫʹ���ж������ֵ��С������λ��֣����ʱ��ʹǰ��Ķ�ֵ����С��

��dp[i][j]��ʾ��ǰi�����ֳ�j��ʱ����Сֵ
ÿ��ö�����һ�ε���ʼλ��
d[i][j]��Ϊmax(dp[t][j-1],sum[i]-sum[t])�е���Сֵ��tΪ�ָ�㣩
�����dp[n][k]��̰�ĵݹ��ӡ����
*/

int x[501];
int dp[501][501];//ǰi���ֳ�j��ʱ����Сֵ
int n,k,ans;

void out(int num,int ed)//
{
    if(num>=1)
    {
        int i,sum=0;
        for(i=ed;i>=num;i--)//��ĩβ��ǰ�����ܶ��ȡ
        {
            sum+=(x[i]-x[i-1]);
            if(sum>ans)
            {
                out(num-1,i);
                cout<<i+1<<' '<<ed<<'\n';
                return;
            }
        }
        out(num-1,num-1);
        cout<<num<<' '<<ed<<'\n';
    }

}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,MIN,MAX,temp,p,t,T;
    cin>>n>>k;
    x[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
        x[i]+=x[i-1];
        dp[i][1]=x[i];
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k&&j<=i;j++)
        {
            MIN=0x7fffffff;
            for(t=1;t<i;t++)//ö�ٷָ��
            {
                temp=max(dp[t][j-1],x[i]-x[t]);
                MIN=min(MIN,temp);
            }
            dp[i][j]=MIN;
        }
    }
    ans=dp[n][k];
    //cout<<ans<<'\n';
    out(k,n);
    return 0;
}


