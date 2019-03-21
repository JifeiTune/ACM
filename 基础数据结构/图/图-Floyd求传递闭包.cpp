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
#include<regex>

using namespace std;

/*
���ݱհ��������ÿ�������ܴﵽ�����е�
Floyd�󴫵ݱհ���A->B��B->C����A->C��ö���м��B����������·���Լ��޸�

�����������飬����֪���������ɶԵ�������ϵ���������ĸ����أ����ж��ٸ����鲻���ܾ����м�����
���������м���������ͨ��������ϵ�����ж��г�������/2����������أ��������

��������Ϊ�ڵ㣬A->B��ʾB��A�أ�����ô��ݱհ���ͳ��ÿ�����ܵ���Ľڵ�����Ϊ��֮�ص�������
ͳ���ܵ���õ�Ľڵ�����Ϊ��֮��Ľڵ�����������/2�Ƚϼ���
*/

int G[101][101];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,n,m,a,b,ans=0;
    memset(G,0,sizeof(G));//�����Ϊ����2�㲻�ɴ�
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        G[b][a]=1;//b��a���һ����
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(G[i][k]&&G[k][j])
                {
                    G[i][j]=1;
                }
            }
        }
    }
    m=n/2;
    for(k=1;k<=n;k++)//ͳ��ÿ�������Ӧ�к��еĺ�
    {
        a=0,b=0;
        for(j=1;j<=n;j++)//�У�����k�ص�
        {
            a+=G[k][j];
        }
        for(i=1;i<=n;i++)//�У�����k���
        {
            b+=G[i][k];
        }
        if(a>m||b>m)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
