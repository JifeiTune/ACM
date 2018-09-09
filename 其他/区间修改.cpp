#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<vector> 
using namespace std;

long long x[110005];//ÿ�����˺� 
long long dam[110005];//ÿ�����ߵ��յ��˺� 
/*
HDU4970Killing
Monsters

1-n�������ڣ���m����̨��ÿ����̨����[L,R]��ÿһ����������ʩ��K�˺�
���ڸ���num�����ޣ�ÿ��������p�㣬����Ϊh��������ж���ֻ�������߳�n
�����޸ģ���ͨ��״���鲻�У��߶����ֲ���д
��ʵһ��ʼ�뵽�ˣ���x[L]����k��x[R+1]��ȥk�����ǰ׺���������ÿһ���˺���
���ȷʵ������״���飬����ÿ���˺����䣬�ڲ�ÿһ�㶼Ӧ��K���������˺�
��û������״����
�����ŷ��֣�������Ͳ��������ˡ��������ò�����״������߶������� 
*/ 

int main()
{
	int n,m,L,R,K,num,ans,i;
	long long h,p;
	while(scanf("%d",&n)&&n!=0)
	{
		ans=0;
		memset(x,0,sizeof(x));
		memset(dam,0,sizeof(dam));
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d%d",&L,&R,&K);
			x[L]+=K;
			x[R+1]-=K;
		}
		for(i=2;i<=n;i++)//ͨ����͸���ÿһ���˺� 
		{
			x[i]+=x[i-1];
		}
		for(i=n;i>=1;i--) 
		{
			dam[i]=dam[i+1]+x[i];
		}
		scanf("%d",&num);
		while(num--)
		{
			scanf("%lld%lld",&h,&p);
			{
				if(dam[p]<h)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0; 
}


