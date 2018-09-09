#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define MAXN 4000000 
/*
求2-n的每个数i
所有比i小的数与i的gcd之和
即
G=0;
for(i=1;i<N;i++)
for(j=i+1;j<=N;j++)
{
	G+=gcd(i,j);
}
求G
当然不可能一个个求gcd然后加起来
而是利用a与b互质，ka与kb的gcd为k的性质
每次求固定gcd值的个数然后累加
假设n为10，那么取i时，小于i且与i互质的个数为euler[i]
即互质对数为euler[i]，那么只要ki<=n，就能产生euler[i]个gcd为k的对数
放心，不会重复多算，一个对最多只能由一个对生成，因为用来生成的对都是互质的
如2 3生成
4 6
6 9
被生成的只可能有互质对2 3生成
打表： 
10（n） 
2  3  4  5  6  7  8  9  10（i） 
5  3  2  2  1  1  1  1  1（n/i，倍数） 
1  2  2  4  2  6  4  6  4（i的欧拉函数） 
1  3  5  9  11 17 21 27 31（欧拉前缀）
结果为31*1+9*2+3*3+1*4+1*5=67（左为对数，右为gcd） 
*/

 
long long euler[MAXN+1]; 
void getEuler(){ 
     memset(euler,0,sizeof(euler)); 
     euler[1] = 1; 
     for(int i = 2;i <= MAXN ;i++) 
         if(!euler[i]) 
             for(int j = i;j <= MAXN ; j += i){ 
                 if(!euler[j]) 
                     euler[j] = j; 
                 euler[j] = euler[j]/i*(i-1); 
             } 
}

int main()
{
	getEuler();
	int n,i,j,k,tem,ed;
	long long ans;
	for(i=3;i<=MAXN;i++)
	{
		euler[i]+=euler[i-1];//求欧拉函数前缀 
	}
	while(~scanf("%d",&n))
	{
		if(n==0)
		{
			break;
		}
		ans=0;
		ed=n/2;
		for(i=1;i<=ed;i++)
		{
			ans+=euler[n/i]*i;
		}
		printf("%lld\n",ans);
	}
	return 0; 
}






