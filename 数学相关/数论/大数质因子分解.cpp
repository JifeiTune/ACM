#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

/*
kuangbinģ�� 
*/ 

const int S = 8; //����㷨�ж�����һ�� 8��10 �͹���
// ���� ret = (a*b)%           a,b,  c< 2^63
long long mult_mod(long long a,long long b,long long c)
{
	a %= c;
	b %= c;
	long long ret = 0;
	long long tmp = a;
	while(b)
	{
		if(b & 1)
		{
			ret += tmp;
			if(ret > c)ret -= c;//ֱ��ȡģ���ܶ�
		}
		tmp <<= 1;
		if(tmp > c)tmp -= c;
		b >>= 1;
	}
	return ret;
}
// ���� ret = (a^n)%mod
long long pow_mod(long long a,long long n,long long mod)
{
	long long ret = 1;


	long long temp = a%mod;
	while(n)
	{
		if(n & 1)ret = mult_mod(ret,temp,mod);
		temp = mult_mod(temp,temp,mod);
		n >>= 1;
	}
	return ret;
}

bool check(long long a,long long n,long long x,long long t)
{
	long long ret = pow_mod(a,x,n);
	long long last = ret;
	for(int i = 1; i <= t; i++)
	{
		ret = mult_mod(ret,ret,n);
		if(ret == 1 && last != 1 && last != n-1)return true;//����
		last = ret;
	}
	if(ret != 1)return true;
	else return false;
}

bool Miller_Rabin(long long n)
{
	if( n < 2)return false;
	if( n == 2)return true;
	if( (n&1) == 0)return false;//ż��
	long long x = n -1;
	long long t = 0;
	while( (x&1)==0 )
	{
		x >>= 1;
		t++;
	}
	for(int i = 0; i < 10; i++)
	{
		long long a = rand()%(n-1) + 1;
		if( check(a,n,x,t) )
			return false;
	}
	return true;
}

long long factor[100];//�����طֽ������շ���ʱʱ����ģ�
int tol;//�����صĸ�������� 0��tol-1
long long gcd(long long a,long long b)
{
	long long t;
	while(b)
	{
		t = a;
		a = b;
		b = t%b;
	}
	if(a >= 0)return a;
	else return -a;
}

//�ҳ�һ������
long long pollard_rho(long long x,long long c)
{
	long long i = 1, k = 2;
	srand(time(NULL));
	long long x0 = rand()%(x-1) + 1;
	long long y = x0;
	while(1)
	{
		i ++;
		x0 = (mult_mod(x0,x0,x) + c)%x;
		long long d = gcd(y -x0,x);
		if( d != 1 && d != x)return d;
		if(y == x0)return x;
		if(i == k)
		{
			y = x0;
			k += k;
		}
	}
}
//�� n ���������ӷֽ⣬���� factor. k ����Ϊ 107 ���Ҽ���
void findfac(long long n,int k)
{

	if(n == 1)return;
	if(Miller_Rabin(n))
	{
		factor[tol++] = n;
		return;
	}
	long long p = n;
	int  c= k;
	while( p >= n)p = pollard_rho(p, c--);//ֵ�仯����ֹ��ѭ�� k
	findfac(p,k);
	findfac(n/p,k);
}


int main()
{
	srand((unsigned)time(NULL));
	long long n;
	cin>>n;
	if(Miller_Rabin(n))
	{
		printf("%lld",n);
	}
	else
	{
		tol=0;
		findfac(n,107);
		for(int j=0; j<tol; j++)
		{
			printf("%lld ",factor[j]);
		}
		putchar('\n');
	}

	return 0;
}
