#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
UVALive - 3027
Corporative Network 
*/
using namespace std;

int main()
{
	int T,i,j,a,b,n,num,x[20001],t;
	unsigned long long dis[20001],tem;
	char c;
	scanf("%d",&T);
	while(T--)
	{
		memset(dis,0,sizeof(dis));//ÿ���㵽���ڵ��ʼ����Ϊ0 
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			x[i]=i;//���ڵ��ʼΪ�Լ� 
		}
		while(scanf(" %c",&c)&&c!='O')
		{
			if(c=='E')
			{
				scanf("%d",&a);
				tem=0;
				t=a;
				while(x[t]!=t)//Ѱ��b�ĸ��ڵ� 
				{
					tem+=dis[t];
					t=x[t];
				}
				x[a]=t;//·��ѹ�� 
				dis[a]=tem;
				
				printf("%llu\n",dis[a]);	
			}
			else
			{
				scanf("%d %d",&a,&b);//b��Ϊa�ĸ��ڵ�
				dis[a]=abs(a-b)%1000;
				x[a]=b;
			}
		} 
	}
	return 0; 
}









