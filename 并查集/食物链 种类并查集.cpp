#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;

/*
POJ - 1182
ʳ���� 
*/
inline int trans(int a)
{
	if(a==0)
	{
		return 0;	
	}
	else
	{
		return (a%2+1);
	}
} 

int x[50001]; 
int rel[50001];//0Ϊͬ�࣬1Ϊ�Ը���2Ϊ������

int findX(int n)
{
	if(n!=x[n])
	{
		int tem=findX(x[n]);
		rel[n]=(rel[n]+rel[x[n]])%3;//�˴����������⣬���з���� 
		return x[n]=tem;
	}
	return n;
}

int main()
{
	int N,K,i,j,tem,t,a,b,p1,p2,num=0,r;
	scanf("%d %d",&N,&K);
	for(i=1;i<=N;i++)
	{
		x[i]=i;	
	}
	memset(rel,0,sizeof(rel));
	while(K--)
	{
		scanf("%d",&t);
		scanf("%d %d",&a,&b);
		if(a>N||b>N)
		{
			num++;
			continue;
		}
		if(t==1)//�ϲ�ͬ�࣬�϶������ 
		{
			p1=findX(a);
			p2=findX(b);
			if(p1==p2)
			{
				if(rel[a]!=rel[b])//�Ѿ��ϲ���������a��b����ͬ�� 
				{
					num++;
					continue;
				}
			}
			else//���ºϲ� 
			{
				x[p2]=p1;
				rel[p2]=(trans(rel[b])+rel[a])%3;
			}
		}
		else//���ӻ��жϹ�ϵ 
		{
			p1=findX(a);
			p2=findX(b);
			if(p1==p2)//�Ѻϲ����жϹ�ϵ�Դ� 
			{
				if( ( rel[a]+trans(rel[b]) )%3!=1 )//�ǲ�ʳ��ϵ 
				{
					num++;
				}
			}
			else//δ�ϲ�����Ӳ�ʳ��ϵ 
			{
				x[p2]=p1;
				rel[p2]=(trans(rel[b])+rel[a]+2)%3;
			}
		}
	}
	cout<<num;
	return 0; 
}









