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
�����ֵ����Ϊ����Ԫ�صĺ�
������Ӿ����ֵ

�漰����ͣ��϶�Ҫʹ��ǰ׺�ͼ������
��ö�����ϽǺ����½ǣ����Ӷ�ΪO(N^4)

�������������ѹ������ѹ�������������ѹ��
��ö���е���ʼ�ͽ�����һ��ѹ����һ����
ת�������еķ���������Ӷκ�
�ܵĸ��ӶȽ�ΪO(N^3)
*/

int x[101][101];
int sum[101][101];//ÿ�е�ǰ׺��

#define getV(k,i,j) (sum[k][j]-sum[k][i-1])

int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,k,MAX,p,last,ans;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        sum[i][0]=0;
        for(j=1;j<=n;j++)
        {
            cin>>x[i][j];
            sum[i][j]=sum[i][j-1]+x[i][j];
        }
    }
    if(n==1)
    {
        cout<<x[1][1];
        return 0;
    }
    ans=0;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)//ö���е���ʼ���յ�
        {
            last=0;
            for(k=1;k<=n;k++)//������Ӷκ�
            {
                if(last>0)
                {
                    last+=getV(k,i,j);
                }
                else
                {
                    last=getV(k,i,j);
                }
                ans=max(ans,last);
            }
        }
    }
    cout<<ans;
    return 0;
}
