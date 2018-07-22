#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
UVALive - 3644
X-Plosives
*/
using namespace std;

int x[100001];

int find(int n)
{
	if(x[n]!=n)
	{
		return x[n]=find(x[n]);
	}
	return n;
} 

int main()
{
	int a,b,i,j,n,tem,f1,f2,num;
	bool flag=1;
	while(flag)
	{
		num=0;
		for(i=1;i<=100000;i++)
		{
			x[i]=i;
		}
		while(1)
		{
			if( scanf("%d",&a)==EOF )
			{
				flag=0;
				break;//EOF，跳出外层循环 
			}
			if(a==-1)
			{
				break;//-1跳出内层循环 
			}
			scanf("%d",&b);
			f1=find(a);
			f2=find(b);
			if(f1==f2)//添加后产生环 
			{
				num++;
			}
			else
			{
				x[f2]=f1;	
			} 
		}
		if(flag)
		printf("%d\n",num);
	}
	return 0; 
}


