#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
/*
��n!�ֽ������ӣ���Ȼ�����Ӷ�<=n
��Ȼ�����ܴ�2-nһ�����ֽ�������
���赱ǰҪ��n!�ֽ������Ӻ�k�ĸ���
��ֻ��k����С�ڵ���n�ı����ֽܷ��������n/k��
�Ƚ��ѽ��ͣ������ӣ�16!����������3�ĸ���
���ܵ�����3 6 9 12 15��16/3=5����
ȡ��5��������3�󣬱��1 2 3 4 5
������Ϊǰһ�εĸ�������ʱ�൱������5!��k�ĸ���
��ĳ��n/k==0ʱ�������� 
*/
using namespace std;

inline int solve(int n,int k)//��n!��������k�ĸ��� 
{
	int ans=0;
	while(n/k!=0)
	{
		ans+=n/k;
		n=n/k;
	}
	return ans;
}

int main()
{
	
	return 0; 
}


