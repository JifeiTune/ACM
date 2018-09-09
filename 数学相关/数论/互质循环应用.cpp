#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define MAXN 2000 
/*
-w<=x<=w��-h<=y<=h�ķ�Χ�ڣ�ÿ��������ֲһ����
�ʴ�ԭ����Կ������ٿ���
��һ�����ϵ������������������Ϊ(x,y)����֮��ĵ�Ϊ(kx,ky)
��ֻҪ�����л��ʵĵ�Լ��ɣ����ݶԳ��ԣ��������ϵ�4���㣬���һ���޵������4����
ͨ����תʹ�߸�С�����൱��ÿ�ζ���һ��i(1<=i<=h)��������j(1<=j<=w)����i���ʵĸ���
֮ǰ������֪��������i���ʵ���j���Ǽ���ki����ѭ����
��ͨ��ŷ�����������iС����i���ʵ������������ѭ�����֣��ٱ����߽缴�� 
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

inline bool gcd1(int a,int b)//�ж�a��b�Ƿ��� 
{
	int tem=a%b;
	while(tem!=0)
	{
		a=b;
		b=tem;
		tem=a%b;	
	}
	return b==1?1:0;
} 

int main()
{
	getEuler();
	int n,i,j,k,tem,w,h;
	double ans;
	while(~scanf("%d%d",&w,&h))
	{
		ans=0;
		if(w==0&&h==0)
		{
			break;
		}
		if(h>w)//ʹ�߸�С 
		{
			swap(w,h);
		}
		for(i=1;i<=h;i++)//һ���ɨ�� 
		{
			ans+=(w/i)*((double)euler[i]);//ѭ������
			tem=w%i;//ʣ�ಿ��
			for(j=1;j<=tem;j++)//��tem�� 
			{
				if(gcd1(w-j+1,i))//���ʵļ��� 
				{
					ans+=1;
				}
			}
		}
		ans*=4;
		ans+=4;
		printf("%.7f\n",ans/((double)w*h*4+2*w+2*h) );
	}
	return 0; 
}






