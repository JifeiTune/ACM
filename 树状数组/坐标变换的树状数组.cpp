#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
UVALive - 5902
Movie collection
*/
using namespace std;

#define lowbit(x) (x&-x)

int x[200001];
int pos[100001];//����ӳ�� 

int sum(int n)//��ǰ׺�� 
{
	int ans=0;
	while(n>0)
	{
		ans+=x[n];
		n-=lowbit(n);
	}
	return ans;
}

void add(int p,int a)//�޸�ֵ��pλ�ã�a���ϵ�ֵ 
{
	if(p<1)
	{
		return;
	}
	while(p<=200000)
	{
		x[p]+=a;
		p+=lowbit(p);
	}
} 

int main()
{
	int T,n,m,a,b,i,j,tem,front,cas;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		memset(x,0,sizeof(x));
		for(i=1;i<=n;i++)
		{
			pos[i]=i+100000;
			add(pos[i],1);
		}
		front=100001;
		cas=1;
		while(m--)
		{
			scanf("%d",&tem);
			if((cas++)>1)
			{
				printf(" ");
			}
			printf("%d",sum(pos[tem]-1)); 
			if(pos[tem]!=front)//ȡ�����Ƕ��ϵľ�û��Ҫ�任�� 
			{
				add(pos[tem],-1);
				front--;
				add(front,1);//����λ��
				pos[tem]=front;//λ�ñ任 
			}
		}
		printf("\n");
	}
	return 0; 
}












