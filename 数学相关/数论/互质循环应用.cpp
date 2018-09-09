#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define MAXN 2000 
/*
-w<=x<=w，-h<=y<=h的范围内，每个整点种植一棵树
问从原点可以看到多少棵树
在一条线上的树，假设最近的坐标为(x,y)，则之后的点为(kx,ky)
即只要求所有互质的点对即可，根据对称性，特判轴上的4个点，求第一象限点对数乘4即可
通过翻转使高更小，则相当于每次对于一个i(1<=i<=h)，求所有j(1<=j<=w)中与i互质的个数
之前做题已知，对于与i互质的数j，是加上ki构成循环的
则通过欧拉函数求出比i小且与i互质的数个数，求出循环部分，再暴力边界即可 
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

inline bool gcd1(int a,int b)//判断a与b是否互质 
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
		if(h>w)//使高更小 
		{
			swap(w,h);
		}
		for(i=1;i<=h;i++)//一层层扫描 
		{
			ans+=(w/i)*((double)euler[i]);//循环部分
			tem=w%i;//剩余部分
			for(j=1;j<=tem;j++)//有tem个 
			{
				if(gcd1(w-j+1,i))//互质的加上 
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






