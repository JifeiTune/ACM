#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define MAXN 4000000 
/*
��2-n��ÿ����i
���б�iС������i��gcd֮��
��
G=0;
for(i=1;i<N;i++)
for(j=i+1;j<=N;j++)
{
	G+=gcd(i,j);
}
��G
��Ȼ������һ������gcdȻ�������
��������a��b���ʣ�ka��kb��gcdΪk������
ÿ����̶�gcdֵ�ĸ���Ȼ���ۼ�
����nΪ10����ôȡiʱ��С��i����i���ʵĸ���Ϊeuler[i]
�����ʶ���Ϊeuler[i]����ôֻҪki<=n�����ܲ���euler[i]��gcdΪk�Ķ���
���ģ������ظ����㣬һ�������ֻ����һ�������ɣ���Ϊ�������ɵĶԶ��ǻ��ʵ�
��2 3����
4 6
6 9
�����ɵ�ֻ�����л��ʶ�2 3����
��� 
10��n�� 
2  3  4  5  6  7  8  9  10��i�� 
5  3  2  2  1  1  1  1  1��n/i�������� 
1  2  2  4  2  6  4  6  4��i��ŷ�������� 
1  3  5  9  11 17 21 27 31��ŷ��ǰ׺��
���Ϊ31*1+9*2+3*3+1*4+1*5=67����Ϊ��������Ϊgcd�� 
*/

 
long long euler[MAXN+1]; 
void getEuler(){ 
     memset(euler,0,sizeof(euler)); 
     euler[1] = 1; 
     for(int i = 2;i <= MAXN ;i++) 
         if(!euler[i]) 
             for(int j = i;j <= MAXN ; j += i){ 
                 if(!euler[j]) 
                     euler[j] = j; 
                 euler[j] = euler[j]/i*(i-1); 
             } 
}

int main()
{
	getEuler();
	int n,i,j,k,tem,ed;
	long long ans;
	for(i=3;i<=MAXN;i++)
	{
		euler[i]+=euler[i-1];//��ŷ������ǰ׺ 
	}
	while(~scanf("%d",&n))
	{
		if(n==0)
		{
			break;
		}
		ans=0;
		ed=n/2;
		for(i=1;i<=ed;i++)
		{
			ans+=euler[n/i]*i;
		}
		printf("%lld\n",ans);
	}
	return 0; 
}






