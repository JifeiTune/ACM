#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
using namespace std;
/*
在x数组，下标be到ed二分查找key
first为1则返回第一个等于key的下标，为0返回最后一个
若未找到，返回-1 
*/
int BinS(int x[],int be,int ed,int key,bool first)
{
	int i=be,j=ed,mid;
	while(i<=j)
	{
		mid=(i+j)/2;
		if(key==x[mid])
		{
			//比起普通的元素不会重复的二分查找增加了以下判断 
			if(first)
			{
				if(mid-1>=be&&key==x[mid-1])//找第一个，则看左边是否还有相等的 
				{
					j=mid-1;
				}
				else
				{
					return mid;
				}
			}
			else
			{
				if(mid+1<=ed&&key==x[mid+1])//找最后一个，则看右边是否还有相等的 
				{
					i=mid+1;
				}
				else
				{
					return mid;
				}
			}
		}
		else if(key<x[mid])
		{
			j=mid-1;
		}
		else
		{
			i=mid+1;
		}
	}
	return -1; 
}

using namespace std;

int main()
{
	int x[5]={2,2,2,2,2};
	cout<<BinS(x,0,4,2,0);
	return 0; 
}
