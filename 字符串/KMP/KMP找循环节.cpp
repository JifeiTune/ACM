#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<cstdio>
using namespace std;

int Next[1000001];
char x[1000001];//模式串

/*
问给定的字符串由几个循环节构成
假设某字符串循节长度为i，则有Next[i+1]*2==i
之后i每加1，相应Next也加1 
继续可推得i结尾的字符串循环节个数为(i+1)/( (i+1)-Next[i+1] )（前提是能整除！不能整除则为1） 
即串的长度除以（串的长度减去串的最长前缀后缀公共长度，也就是循环节长度） 
*/ 

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
	int lenx,i,T;
	while(scanf("%s",x))
	{
		if(x[0]=='.')
        {
            break;
        }
		lenx=strlen(x);
		Cal(lenx);
        printf("%d\n",lenx%(lenx-Next[lenx])==0?lenx/(lenx-Next[lenx]):1);
	}
	return 0;
} 





