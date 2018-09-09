#include<iostream>
#include<cmath>
using namespace std; 
/*
������k%n�ĺ�
��n>kʱ�����Ϊk
С��k���֣������Է���
��i>sqrt(n)ʱ���������n/i��ֵ�ֶΣ��ɵȲ�����
�ֶ���ͼ��� 
*/
inline long long sum(long long be,long long num,long long d)//�Ȳ���� 
{
	return num*be+d*num*(num-1)/2;
}


int main()
{
	int n,k,i,front,num,be,tem,end,t1,t2;
	long long ans;
	while(~scanf("%d%d",&n,&k))
	{
		ans=0;
		if(n>k)//����� 
		{
			ans+=((long long)k)*(n-k);
		}
		front=sqrt(k)+1;
		tem=min(front-1,n);
		for(i=1;i<=tem;i++)//ǰ��� 
		{
			ans+=k%i;
		}
		end=k/front;
		tem=min(n,k);
		tem=k/tem;
		for(i=tem;i<=end;i++)//һ�ζ�ö�� 
		{
			t1=k/(i+1);
			t2=min(k/i,n);
			num=t2-t1;
			be=k%t2;
			ans+=sum(be,num,i);
		}
		printf("%lld\n",ans);
	}
	
	return 0; 
}





