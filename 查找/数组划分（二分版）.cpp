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
������������
1���Ӹ��Ӷ��Ͽ���Ӧ��O(log(N))��O(Nlog(N))�ڽ��
ע��log(N)�Ƚ�С����ʹN�ﵽ1e5�����һ��Ϊ�жϺ�������Ҳû��ϵ
2���߱������ԣ�Ҫ����ֵ������һ��������������̫�󡱡���̫С���������á���

��N��Ԫ�ص����黮�ֳ�M�Σ�M<=N����ÿ�ε�ֵΪ��Ԫ�غ�
Ҫ�����ֵ��С��������ֵ

���ָ����ֵ���жϺ���Ϊ���ݴ�������ֵ�������ٷֶ��ٶ�
����������M��˵�����ֵ̫С��
��С�ڵ���M��˵�����ֵ����С
*/

int x[100001];
int N,M;

inline int getN(int num)//���ֵΪnumʱ����С������
{
    int i,ans=1,last=0;
    for(i=1;i<=N;i++)
    {
        if(x[i]+last<=num)
        {
            last+=x[i];
        }
        else
        {
            ++ans;
            last=x[i];
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,MAX=0,L,R,num,sum=0,mid,last;
    cin>>N>>M;
    for(i=1;i<=N;i++)
    {
        cin>>x[i];
        sum+=x[i];
        MAX=max(MAX,x[i]);
    }
    L=MAX,R=sum;
    while(R>=L)
    {
        mid=(L+R)/2;
        if(getN(mid)<=M)
        {
            last=mid;
            R=mid-1;
        }
        else
        {
            L=mid+1;
        }
    }
    cout<<last;
    return 0;
}



