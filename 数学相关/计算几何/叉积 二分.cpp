#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
һ�����κ��ӣ�������n�鵲�彫���ӷֳ�n+1�����֣������0��n��
����m���㣬��ÿ�������м�����
��һ��Ϊ������n������m���������Ͻǡ����½�����
������n��Ϊÿ�������϶˺��¶˵ĺ����꣬��֤�����������
������m��Ϊ������꣬��֤�㲻�ڵ����ϣ�Ҳ��Խ��

�㵽�������¶˵������������������<0��Ϊ��>0��Ϊ�ң�����ȷ�������ĸ����� 
*/
using namespace std;

struct P
{
	int i,j;
} board[5001];//�������º�����

int U,L;//�����͵ײ������� 
int m,n;

int num[5001];//ÿ�����ֵĵ��� 

inline bool Right(int X,int Y,int p)//��(X,Y)�Ƿ���board[p]�ұ� 
{
	return ( (board[p].i-X)*(L-Y)-(board[p].j-X)*(U-Y) )>0; 
}

inline void binS(int X,int Y)//���ֲ������һ�����ڵ���ߵİ壬�ҵ��˰��±꼴Ϊnum�±꣬�Ҳ����±�Ϊ0 
{
	int i=1,j=n,mid;//��������Ϊ1��n
	while(i<=j)
	{
		mid=(i+j)/2;
		if(Right(X,Y,mid))
		{
			if(mid!=n&&Right(X,Y,mid+1))//ע��mid==n����� 
			{
				i=mid+1;//ע�⣬����ȡ����ԭ�򣬲���Խ�� 
			} 
			else
			{
				num[mid]++;
				return;
			}
		}
		else
		{
			j=mid-1;
		}
	} 
	num[0]++;
}

int main()
{
	int i,j,k,ans,tem,X1,Y1,X2,Y2;
	while(scanf("%d",&n)&&n!=0)
	{
		scanf("%d %d %d %d %d",&m,&X1,&Y1,&X2,&Y2);
		U=Y1,L=Y2;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&board[i].i,&board[i].j);//���Ǻ����� 
		}
		memset(num,0,sizeof(num));
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&X1,&Y1);
			binS(X1,Y1);//���ֹ������޸�num����s 
		}
		for(i=0;i<=n;i++)
		{
			printf("%d: %d\n",i,num[i]);
		}
		putchar('\n');
	}
	return 0; 
}


