#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
��[1-n!]�У����������Ӷ�����m�����ĸ���
���������Ӷ�����m���ɵȼ�ת��Ϊ��m!����
�����൱����[1-n!]����m!���ʵ����ĸ���
�ر�ע����Ŀ����n>=m����n!��Ϊm!�ı���
���ǿ���������������ѭ���ķ�ʽ��
�ؼ��������m!��ŷ�������� 
���Ҫ��ȥ1����Ϊ1��Ȼ��m!���ʣ������������� 
*/
using namespace std;

#define MAX (int)(10000000)//�˴�����ɸѡ��Χ 
#define MOD 100000007

bool x[MAX+1];//���Ϊ1��ʾ�Ǻ�����0��ʾ���� 
int Fe[MAX+1];//�׳˵�ŷ������ 

inline void getP()
{
	long long bs,i;
	long long range=(long long)(sqrt(MAX)+1);
	memset(x,0,sizeof(x));//��ȫ�����Ϊ���� 
	for(i=2;i<=range;i++)
	{
		if(!x[i])//δ��ǣ�˵�������� 
		{
			bs=i;//����һ��ʼ����Ϊi����ΪС��i����֮ǰ�Ѿ�ɸ�� 
			while(bs*i<=MAX)
			{
				x[bs*i]=1;
				bs++;
			}
		}
	}
}

void getFe()//���Ƶõ�ÿ���׳˵�ŷ������ 
{
	int i;
	Fe[1]=1;
	Fe[2]=1;
	for(i=3;i<=MAX;i++)
	{
		if(!x[i])//����
		{
			Fe[i]=(((long long)Fe[i-1])*(i-1))%MOD;
		}
		else
		{
			Fe[i]=(((long long)Fe[i-1])*i)%MOD;	
		}	
	} 
}

int main()
{
	getP();
	getFe();
	int n,m,i;
	long long tem;
	while(scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)
		{
			break;
		}
		tem=1;
		for(i=m+1;i<=n;i++)
		{
			tem=(tem*i)%MOD;//����n!/m! 
		}
		printf("%lld\n",(tem*Fe[m]-1+MOD)%MOD); 
	}
	return 0; 
}


