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
�������⣬N���˹��ӣ�һ�Ҵ������迼�ǳŻأ��������2��
����ʱ�����ٶ������˾��������ܵ����ʱ��

��N<=3ʱ�����ǹ̶��ģ�����>3ʱ
ÿ�ο��ǽ��ٶ������������͵��԰�
������������Ϊ���ǿ����뵽��������������һ����ӣ����ɱ��˳Żأ������ܽ�ʡ����ʱ��
������2�ַ�����
1�������˷�2�δ�������2�˹�ȥ
2�������˴��ο�Ĺ�ȥ��������������2��һ���ȥ�����ɴο���˳Ż�
�����ٶ�����ѡȡ���ż���
*/

vector<int> all;

int sum(int n)
{
    int i,ans=0;
    if(n==1||n==2)
    {
        return all[n-1];
    }
    else if(n==3)
    {
        return (all[0]+all[1]+all[2]);
    }
    else
    {
        while(n>=4)
        {
            ans+=min(all[n-1]+all[n-2]+2*all[0],all[n-1]+2*all[1]+all[0]);//2�ַ���ȡ����
            n-=2;
        }
        ans+=sum(n);
        return ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int T,n,i,j,k,ans,temp;
    cin>>T;
    while(T--)
    {
        all.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            all.push_back(temp);
        }
        sort(all.begin(),all.end());
        cout<<sum(n)<<'\n';
    }
    return 0;
}

