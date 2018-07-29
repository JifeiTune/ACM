#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define LL long long//这样不仅简写long long，在不会超范围时也可方便地改为int 

/*
拓展欧几里得
求解整数x和y，使得ax+by==d，且abs(x)+abs(y)最小，其中d=gcd(a,b) 
*/
void Egcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(b==0)
	{
		d=a,x=1,y=0;
	}
	else
	{
		Egcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

/*
x与y都可能是非常大的数 
(x/y)%MODE（保证能整除） != (x%MODE)/(y%MODE)
于是需要求解y%MODE的乘法逆元，转换成乘法，方便分部计算不断取余，不会溢出
*/ 
LL inv(LL a,LL MODE)//计算a摸MODE下逆元 
{
	LL d,x,y;
	Egcd(a,MODE,d,x,y);
	return d==1?(x+MODE)%MODE:-1;//-1代表无逆元 
}

int main()
{
	
	LL a=12,b=3,MODE=7;//(a/b)%MODE 
	LL tem=inv(b,MODE);
	cout<<(a*tem)%MODE;
	return 0; 
}






