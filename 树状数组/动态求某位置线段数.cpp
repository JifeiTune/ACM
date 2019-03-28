#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>

using namespace std;

/*
一个长为n的01串，起初都为0，每次让[L,R]内元素翻转，或者问指定位p是0还还是1
显然，一个元素反转偶数次为0，否则为1，所以需求解元素反转次数
同样是扫描线问题，每次反转，添加[L,R]的线段，问题转换为求p位置线段个数
扫描线遇到左端点时，线段数加一，移出右端点时，线段数减一
故用树状数组统计一下前缀和，每次L位置加一，R+1位置减一
*/

#define lowbit(x) (x&-x)

int MAX;//树状数组有意义部分最大下标
int x[100001]={0};

int sum(int n)//求前缀和
{
	int ans=0;
	while(n>0)
	{
		ans+=x[n];
		n-=lowbit(n);
	}
	return ans;
}

void add(int p,int a)//修改值，p位置，a加上的值
{
	if(p<1)
	{
		return;
	}
	while(p<=MAX)
	{
		x[p]+=a;
		p+=lowbit(p);
	}
}

int main()
{
    ios::sync_with_stdio(false);
	int n,q,a,b,op,kind=0;
	cin>>MAX>>q;
	while(q--)
    {
        cin>>op>>a;
        if(op==1)
        {
            cin>>b;
            add(a,1);
            add(b+1,-1);//注意，因为端点也算，所以结束时在右端点下一位置
        }
        else
        {
            b=sum(a);
            if(b&1)
            {
                cout<<1<<'\n';
            }
            else
            {
                cout<<0<<'\n';
            }
        }
    }
	return 0;
}

