#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<map>
using namespace std;
/*
ԭ��ܼ򵥣��������ǿ��Կ��ɱ��Լ�С�����ı���
������������δ��ǣ�����������Ȼ���2��ʼ��ÿ���ҵ�һ��δ��ǵ���
�϶���Ϊ������Ȼ���Ƿ�Χ���������ı�����2���𣩣����ʣ�µ�δ��ǵľ�������
Ѱ�ҵ�sqrt(MAX)���ɣ���Ϊ��ʱ�����Ѿ����ԴﵽMAX 
*/ 
#define MAX (int)(1e6+1)//�˴�����ɸѡ��Χ 

bool x[MAX];//���Ϊ1��ʾ�Ǻ�����0��ʾ���� 

int main()
{
	long long bs,i;
	long long range=(long long)(sqrt(MAX)+1);
	memset(x,0,sizeof(x));//��ȫ�����Ϊ���� 
	for(i=2;i<=range;i++)
	{
		if(!x[i])//δ��ǣ�˵�������� 
		{
			bs=2;
			while(bs*i<=MAX)
			{
				x[bs*i]=1;
				bs++;
			}
		}
	}
	for(i=2;i<=MAX;i++)
	{
		if(!x[i])
		{
			printf("%lld\n",i);
		}
	}
	return 0; 
}













