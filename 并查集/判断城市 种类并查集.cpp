#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
POJ - 1703
Find them, Catch them 
*/
using namespace std; 

int x[100001];//��ȷ����һ�������� 
int y[100001];//���븸�ڵ��ϵ ��������ʾ���� 

int find(int n)
{
	int t,len=0;
	if(n!=x[n])
	{
		t=find(x[n]);//�ҵ����մ���Ԫ 
		y[n]+=y[x[n]];//���ݡ����ڵ������Ԫ��ϵ���������ڵ��븸�ڵ��ϵ�����������Ԫ�Ĺ�ϵ 
		y[n]%=2;
		return x[n]=t;//�����´���Ԫ
	} 
	return n;
}

int main()
{
	int T,a,b,i,j,n,tem,N,M,t1,t2;
	char c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);//N���ﷸ��M�����
		for(i=1;i<=N;i++)
		{
			x[i]=i;
		}
		memset(y,0,sizeof(int)*(N+1));
		while(M--)
		{
			scanf(" %c",&c);
			scanf("%d %d",&a,&b);
			if(c=='A')//�ش� 
			{
				if(find(a)!=find(b))//������ͬһ�����ϣ���ȷ�� 
				{
					printf("Not sure yet.\n");
				}
				else
				{
					if( (y[a]-y[b])&1==1 )
					{
						printf("In different gangs.\n");
					}
					else
					{
						printf("In the same gang.\n");
					}
				}
			}
			else
			{
				t1=find(a);
				t2=find(b);
				x[t2]=t1; 
				if(y[a]==y[b])//�����븸�ڵ�Ĺ�ϵ 
				{
					y[t2]=1;
				}
				else
				{
					y[t2]=0;
				}
			}
		} 		
	}  
	return 0; 
}


