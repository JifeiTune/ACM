#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<list>
#include<cstdlib>
#include<fstream>
#include<algorithm>
using namespace std;

/*
����һ�����飬Ѱ����������Ҫ������������
��������������֮��С��MAXLEN

��������֮��ҪС��MAXLEN����ʵ�����������ֵ��ȥ��СֵҪС��MAXLEN
������ֵ��RMQ���
ö����˵㣬�Ҷ˵���Զ�����⣬�൱�ڶ�������Ҫ���������󳤶�
�����䲻�о��Ҷ����䣬��������Ծ����ҳ�����
*/

#define num 100001//������󳤶�
int x[num];
int MAX[num][20];
int MIN[num][20];
int len;//����ʵ��ʹ�ó���

void init()//��ʼ������������init��
{
	int i,j;
	for(i=1;i<=len;i++)
	{
		MAX[i][0]=x[i];
		MIN[i][0]=x[i];//��i��ͷ����Ϊ2^0����ֵ��Ȼ���Լ�
	}
	for(j=1;(1<<j)<=len;j++)
	{
		for(i=1;i+(1<<j)-1<=len;i++)//ע�ⷶΧ��������δ���������±���м��������
		{
			MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);
			MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);//���ֳɳ�����ȵ�����������
		}
	}
}

int answer(int i,int j,bool what)//��i��j��ֵ��whatΪ1��ʾ�����ֵ��Ϊ0��ʾ����Сֵ
{
	int dis=j-i+1,k=0;
	while((1<<(++k))<=dis);
    --k;
	if(what)
	{
		return max(MAX[i][k],MAX[j-(1<<k)+1][k]);
	}
	else
	{
		return min(MIN[i][k],MIN[j-(1<<k)+1][k]);
	}
}

int main()
{
    int i,j,L,R,mid,T,MAXLEN,last;
    long long ans=0;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d%d",&len,&MAXLEN);
        for(i=1;i<=len;i++)
        {
            scanf("%d",&x[i]);
        }
        init();
        for(i=1;i<=len;i++)
        {
            L=i,R=len;
            while(L<=R)//���������ұ�һ�����������ĵ�
            {
                mid=(L+R)/2;
                if(answer(i,mid,1)-answer(i,mid,0)<MAXLEN)
                {
                    last=mid;
                    L=mid+1;
                }
                else
                {
                    R=mid-1;
                }
            }
            ans+=last-i+1;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
