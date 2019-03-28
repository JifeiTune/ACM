#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
下标从0开始 
此处前后缀不包含自己！ 
字符串匹配时，假设到了模式串i位置不匹配，则i位置以前，双方是相等的
接下来对模式串移位，在起始移到i之前时，就相当于自己在匹配自己
而自己匹配自己在每个点上结果都是一样的，可以预处理记录下来加速匹配
假设有如下匹配 
ababdefg
ababc
当前在c位置不匹配，那么下一步应该直接
ababdefg
  ababc
即用模式串下标2位置与该字符比较（未优化KMP版本，新匹配字符可能会与之前匹配字符相等）
Next[i]表示当i位置失配时，下一次被匹配串该位置应该与模式串哪个位置的字符比较
实际意义为模式串开头到i-1位置的子串，前缀与后缀相同时的最大长度
此模板Next[0]=1而不是-1 
*/
using namespace std; 

int Next[10001];//若Next[i]+1=i，实际上公共长度为i 
int x[10001];//模式串 
int y[1000001];//被匹配 

void Cal(int lenx)//计算Next数组，lenx为x长度 
{ 
    int i,j; 
    Next[0]=0,Next[1]=0;
	for(i=1;i<lenx;i++)
	{
		j=Next[i];
		while(j&&x[i]!=x[j])
		{
			j=Next[j];	
		}
		Next[i+1]=x[i]==x[j]?j+1:0;
	} 
}

int KMP(int lenx,int leny)
{
	Cal(lenx);
	int i,j=0;
	bool flag=1;
	for(i=0;i<leny;i++)
	{
		while(j!=0&&x[j]!=y[i])
		{
			j=Next[j];
		}
		if(x[j]==y[i])
		{
			j++;
		}
		if(j==lenx)
		{
			flag=0;
			return i-lenx+1;//输出起始位置 
		}
	}
	if(flag)
	{
		return -2;
	}
}

int main()
{
	int lenx,leny,i,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&leny,&lenx);
		for(i=0;i<leny;i++)
		{
			scanf("%d",&y[i]);
		}
		for(i=0;i<lenx;i++)
		{
			scanf("%d",&x[i]);
		}
		printf("%d\n",KMP(lenx,leny)+1);
	}
	return 0; 
}

