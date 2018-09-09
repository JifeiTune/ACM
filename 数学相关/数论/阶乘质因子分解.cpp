#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
/*
对n!分解质因子，显然质因子都<=n
当然不可能从2-n一个个分解质因子
假设当前要求n!分解质因子后k的个数
则只有k所有小于等于n的倍数能分解出来，有n/k个
比较难解释，看例子，16!中求质因子3的个数
可能的项有3 6 9 12 15（16/3=5个）
取出5个质因子3后，变成1 2 3 4 5
最大项就为前一次的个数，此时相当于再求5!中k的个数
当某次n/k==0时结束即可 
*/
using namespace std;

inline int solve(int n,int k)//求n!中质因子k的个数 
{
	int ans=0;
	while(n/k!=0)
	{
		ans+=n/k;
		n=n/k;
	}
	return ans;
}

int main()
{
	
	return 0; 
}


