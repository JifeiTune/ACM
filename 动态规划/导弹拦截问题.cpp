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
����һϵ�е�����ÿ����һ���߶�
����ϵͳ��ʼ����������߶�
֮��ÿ�ζ����ܳ���ǰһ�εĸ߶�

��ֻ��һ��ϵͳ����������ض��ٸ�
�����������У������䱸����ϵͳ

��1Ϊ���������������
��2λ�������������
*/

int x[1001];
int inc[1001];//�����
int decr[1001];//�������

int main()
{
    int i,n=0,MAX,MIN,j,temp,ans1=1,ans2=1;
    while(~scanf("%d",&temp))
    {
        x[++n]=temp;
        inc[n]=1;
        decr[n]=1;
    }
    for(i=2;i<=n;i++)
    {
        MAX=0;
        MIN=0;
        for(j=1;j<i;j++)
        {
            if(x[i]>x[j])
            {
                MAX=max(MAX,inc[j]);
            }
            else
            {
                MIN=max(MIN,decr[j]);
            }
        }
        inc[i]+=MAX;
        decr[i]+=MIN;
        ans1=max(ans1,inc[i]);
        ans2=max(ans2,decr[i]);
    }
    printf("%d\n%d",ans2,ans1);
    return 0;
}
