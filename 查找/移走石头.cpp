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
N��ʯͷ�ų�һ��
�ֿ����Ƴ��������յ�������M��ʯͷ
ʹ��ʯͷ����С�ľ������
���������

�����������
����Ҫ��֤��ǰ����ʱ�����Ƴ���ʯͷ��
��<=M������ܻ��ܴ�
��>M��������С
*/

int x[50001];
int N,M,Len;

inline int getN(int L)//��С���ΪLʱ����С��������
{
    int ans=0,last=0,i;
    for(i=1;i<=N;i++)
    {
        if(x[i]-last<L)
        {
            ans++;//����i
        }
        else
        {
            last=x[i];
        }
    }
    if(Len-last<L)//��Ҫ���յ�Ƚ�
    {
        ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,MIN=0x7fffffff,L,R,num,sum=0,mid,last;
    cin>>Len>>N>>M;
    x[0]=0;
    for(i=1;i<=N;i++)
    {
        cin>>x[i];
        MIN=min(MIN,x[i]-x[i-1]);
    }
    MIN=min(MIN,Len-x[N]);//ע���©��
    L=MIN,R=Len;
    while(R>=L)
    {
        mid=(L+R)/2;
        if(getN(mid)<=M)
        {
            last=mid;
            L=mid+1;
        }
        else
        {
            R=mid-1;
        }
    }
    cout<<last;
    return 0;
}



