#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<map>
using namespace std;

inline long long gcd(long long x,long long y)//求解x与y的最大公约数
{
	long long tem;
	while((tem=x%y)!=0)
	{
		x=y;
		y=tem;
	}
	return y;
} 

int main()
{
	cout<<gcd(100,15);
	return 0; 
}













