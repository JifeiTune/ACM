#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<map>
using namespace std;
/*
ԭ��ܼ򵥣��������ǿ��Կ��ɱ��Լ�С�����ı���
������������δ��ǣ�����������Ȼ���2��ʼ��ÿ���ҵ�һ��δ��ǵ���i
�϶���Ϊ������Ȼ���Ƿ�Χ���������ı�����i������ΪС��i����֮ǰɸ����
���ʣ�µ�δ��ǵľ�������
Ѱ�ҵ�sqrt(MAX)���ɣ���Ϊ��ʱi���Ѿ����ԴﵽMAX
*/ 
#define MAX (int)(1000)//�˴�����ɸѡ��Χ 

bool x[MAX+1];//���Ϊ1��ʾ�Ǻ�����0��ʾ���� 

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

int main()
{
	getP();
	int i;
	for(i=2;i<=MAX;i++)
	{
		if(!x[i])
		{
			printf("%lld\n",i);
		}
	}
	return 0; 
}













