#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
��״������ǰ׺���Ǵ�1��ʼ��� 
*/
using namespace std;

#define lowbit(x) (x&-x)

int MAX;//��״���������岿������±� 
int x[100001];

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
	while(p<=MAX)
	{
		x[p]+=a;
		p+=lowbit(p);
	}
} 

int main()
{
	
	return 0; 
}


