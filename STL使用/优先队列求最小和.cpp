#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<queue> 

using namespace std;

/*
POJ 2010
Moo University - Financial Aid

��F�ʽ𣬴�C��ѧ����ѡN������������������
ÿ��ѧ���з���S�������ʽ�M
�����ѡȡʹ��N��ѧ��������λ������������λ��
�ָ�N��ѧ�����ʽ�Ͳ��ܳ���F

ö����λ��������ȸ÷���С��N/2��ѧ���ʽ���С��
�Լ��ȸ÷������N/2��ѧ���ʽ���С��
����ڷ�����������λ��������󼴿�

�ɲ������ȶ���ʵ�֣�����ѧ��ʱ���ʽ���Ѷ��Ƚ�
��С��pop�Ѷ���push��Ԫ�أ�ͬʱ�����ʽ�֮��
*/ 
struct stu
{
	long long sco;//���� 
	long long mon;//�����ʽ�
}x[100001];

bool CMP(stu a,stu b)//��������С�������򣬱���ö����λ�� 
{
	return a.sco<b.sco;
}

long long Left[100001];//Left[i]Ϊi���N/2��ѧ���������ʽ�͵���Сֵ 
long long Right[100001];

int main()
{
	long long N,C,F,i,j,ans,L,R;
	scanf("%lld%lld%lld",&N,&C,&F);
	for(i=1;i<=C;i++)
	{
		scanf("%lld %lld",&x[i].sco,&x[i].mon);
	}
	sort(x+1,x+1+C,CMP);//���������ö����λ�� 
	L=N/2+1,R=C-N/2;//��ѡ��λ����Χ 
	priority_queue<long long> q1,q2;
	Left[L]=0;
	for(i=1;i<L;i++)
	{
		Left[L]+=x[i].mon;
		q1.push(x[i].mon);
	}
	for(i=L+1;i<=R;i++)
	{
		if(x[i-1].mon<q1.top())//�и�С�� 
		{
			Left[i]=Left[i-1]-q1.top()+x[i-1].mon;
			q1.pop();
			q1.push(x[i-1].mon);
		}
		else
		{
			Left[i]=Left[i-1];
		}
	}
	Right[R]=0;
	for(i=C;i>R;i--)
	{
		Right[R]+=x[i].mon;
		q2.push(x[i].mon);
	}
	for(i=R-1;i>=L;i--)
	{
		if(x[i+1].mon<q2.top())
		{
			Right[i]=Right[i+1]-q2.top()+x[i+1].mon;
			q2.pop();
			q2.push(x[i+1].mon);
		}
		else
		{
			Right[i]=Right[i+1];
		}
	}
	for(i=R;i>=L;i--)
	{
		if(x[i].mon+Left[i]+Right[i]<=F)
		{
			printf("%lld",x[i].sco);
			return 0;
		}
	}
	printf("-1");
	return 0;
}

