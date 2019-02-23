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
�����������������и�ɵȳ������ɸ�
�Ϊ����

���ֳ��ȼ��ɣ���Ȼÿ�ζ���Ҫͳ�ƿ��и���
��������Ŀ��1e4��Ҳ����ͳ��ʱ��Ҫѭ��1e4��
�����ִ�������̫�࣬û��ϵ��

�ر�ע�⣬��double����ȱ�ݣ���ý���������辫��ת�������������㣡����
�����ﾫȷ��С�����2λ��������100��
*/

long long x[10001];
int n;

inline long long getN(int len)//������ѡ���ȼ����ָܷ���ٷ�
{
    long long i,num=0;
    for(i=1;i<=n;i++)
    {
        num+=x[i]/len;
    }
    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    long long L,R,mid,MAX=0,i,num,ans;
    double temp;
    cin>>n>>num;
    for(i=1;i<=n;i++)
    {
        cin>>temp;
        x[i]=temp*100;
        MAX=max(MAX,x[i]);
    }
    L=1,R=MAX;
    ans=0;
    while(L<=R)
    {
        mid=(L+R)/2;
        if(getN(mid)>=num)
        {
            L=mid;
            ans=mid;
        }
        else
        {
            R=mid;
        }
    }
    printf("%.2f",ans/100.0);
    return 0;
}



