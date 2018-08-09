#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<queue>
using namespace std;

/*
固定长度的连续序列中的最值
这个序列是在原序列中滑动的
使用滑动窗口高效求解

窗口向右滑动时，左边元素删除元素，右边增加元素
假设是求最小值，如果窗口中有一个序列是3 2 1，会发现在1不得不被删除前
窗口滑动，最小值都不可能在3 2中取，所以应及时删除
也就是，当窗口右边要新增一个元素时，应删除前面所有比它大的元素
在将该元素防于最右端，于是窗口中元素总是递增的，最左边元素就是最小值
注意，窗口中元素个数不一定等于窗口尺寸
最左边的元素不一定是窗口框住原序列时的最左边的元素
滑动更新时判断最左边元素是否要删除，判断是否等于原序列中窗口左端第一个元素即可 
*/

int main()
{
	//假设每次求窗口中最小值 
	int x[10]={3,4,1,8,0,1,3,7,6,4};
	int len=3;//滑动窗口长度
	int size=10;//原序列长度 
	int i,j,k,tem;
	deque<int> dq;
	//预处理，求得窗口初始值 
	dq.push_back(x[0]);
	for(i=1;i<len;i++)
	{
		while(!dq.empty()&&dq.back()>x[i])
		{
			dq.pop_back();
		}
		dq.push_back(x[i]);
	}
	cout<<dq.front()<<' ';
	//开始更新 
	for(i=len;i<size;i++)
	{
		if(dq.front()==x[i-len])
		{
			dq.pop_front();
		}
		while(!dq.empty()&&dq.back()>x[i])
		{
			dq.pop_back();
		}
		dq.push_back(x[i]);
		cout<<dq.front()<<' ';
	}
	return 0; 
}














