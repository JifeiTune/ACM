#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

long long Euler(long long n)//求比n小且与n互质的数的个数 
{ 
	long long ans=n; 
	for(int i=2;i*i<=n;i++)
	{ 
	    if(n%i==0)
		{ 
	        ans-=ans/i; 
	        while(n%i==0)
	        {
				n/=i;
			}      
	    } 
	} 
	if(n>1)
	{
		ans-=ans/n;
	} 
	return ans; 
} 
int main()
{
	
	cout<<Euler(8);
	return 0; 
}






