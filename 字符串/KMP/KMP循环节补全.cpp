#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<cstdio>
using namespace std;
/*
给一个字符串，问最少在后面补几个字符能构成循环
求循环节长度(lenx-Next[lenx])，当然前提是lenx%(lenx-Next[lenx])==0
再求循环次数，为1则补lenx，否则不需要补
不构成循环，则相对当于问lenx再加多少才能整除以(lenx-Next[lenx])
因为循环中，i每加1，Next也加1 
*/
int Next[100001];
char x[100001];//模式串

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

int main()
{
	int lenx,i,T,tem;
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%s",x);
		lenx=strlen(x);
		Cal(lenx);
		if(lenx%(lenx-Next[lenx])==0)//已经构成循环
		{
			printf("%d\n",lenx/(lenx-Next[lenx])==1?lenx:0);//防止循环为1，即实际非循环
		}
		else//添加使得整除，构成循环
		{
			printf("%d\n",(lenx-Next[lenx])-lenx%(lenx-Next[lenx]));
		}
	}
	return 0;
}





