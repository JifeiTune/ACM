#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
using namespace std;
/*
��x���飬�±�be��ed���ֲ���key
firstΪ1�򷵻ص�һ������key���±꣬Ϊ0�������һ��
��δ�ҵ�������-1 
*/
int BinS(int x[],int be,int ed,int key,bool first)
{
	int i=be,j=ed,mid;
	while(i<=j)
	{
		mid=(i+j)/2;
		if(key==x[mid])
		{
			//������ͨ��Ԫ�ز����ظ��Ķ��ֲ��������������ж� 
			if(first)
			{
				if(mid-1>=be&&key==x[mid-1])//�ҵ�һ����������Ƿ�����ȵ� 
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
				if(mid+1<=ed&&key==x[mid+1])//�����һ�������ұ��Ƿ�����ȵ� 
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
