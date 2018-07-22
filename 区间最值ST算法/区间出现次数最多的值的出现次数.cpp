#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;
/*
UVA - 11235
Frequent values
*/
#define num 100000//������󳤶�
#define LOG ((int)log2(num))//���鳤����2Ϊ�׵Ķ���
 
//���������±��1��ʼ
int x[num+1];//ÿһ�εĳ��� 
int MAX[num+1][LOG+1];
int len;//����ʵ��ʹ�ó���
int LEFT[num+1];//ÿһ�ε���˵�
int RIGHT[num+1];//ÿһ�ε��Ҷ˵�
int number[num+1];//ÿһ��Ԫ�ض�Ӧ�Ķκ� 

void init()//��ʼ������������init�� 
{
	int f=(int)log2(len),i,j;
	for(i=1;i<=len;i++)
	{
		MAX[i][0]=x[i];
	}
	for(j=1;j<=f;j++)
	{
		for(i=1;i+(1<<j)-1<=len;i++)//ע�ⷶΧ��������δ���������±���м�������� 
		{
			MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]); 
		}
	}
}

int answer(int i,int j)//��i��j��ֵ 
{
	int k=(int)log2(j-i+1);
	return max(MAX[i][k],MAX[j-(1<<k)+1][k]);
}

int main()
{
	int n,q,i,j,tem,last,ans,L,R;
	while(scanf("%d",&n)&&n!=0)
	{
		memset(x,0,sizeof(int)*(n+1));
		scanf("%d",&q);
		len=1;//�κ������ 
		scanf("%d",&last);
		x[len]++;//���¶γ� 
		LEFT[len]=1;//���¶ε���˵� 
		number[1]=len;//����Ԫ�ض�Ӧ�κ� 
		for(i=2;i<=n;i++)
		{
			scanf("%d",&tem);
			if(tem==last)
			{
				x[len]++;//���¶γ� 
				number[i]=len;
			}
			else
			{
				last=tem;
				RIGHT[len]=i-1;//��һ�ε��Ҷ˵�ȷ�� 
				len++;//������ 
				x[len]++;
				LEFT[len]=i;
				number[i]=len;
			}
		}
		RIGHT[len]=n; 
		init();
		while(q--)
		{
			scanf("%d%d",&i,&j);
			if(number[i]==number[j])//��ͬһ�� 
			{
				printf("%d\n",j-i+1);
			}
			else
			{
				R=RIGHT[number[i]],L=LEFT[number[j]];
				ans=max(R-i+1,j-L+1);
				if(L>R+1)//�����м�Ż��ж� 
				{
					i=number[R+1];
					j=number[L-1];
					printf("%d\n",max(ans,answer(i,j))); 
				}
				else
				{
					printf("%d\n",ans);
				}
			}
		}
	} 
	return 0; 
}




















