#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;

#define num 100001//������󳤶�
 
/*
�����±��1��ʼ
*/
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
	len=10000;
	
	return 0; 
}




















