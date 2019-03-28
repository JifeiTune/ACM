#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>

using namespace std;

/*
һ����Ϊn��01���������Ϊ0��ÿ����[L,R]��Ԫ�ط�ת��������ָ��λp��0������1
��Ȼ��һ��Ԫ�ط�תż����Ϊ0������Ϊ1�����������Ԫ�ط�ת����
ͬ����ɨ�������⣬ÿ�η�ת�����[L,R]���߶Σ�����ת��Ϊ��pλ���߶θ���
ɨ����������˵�ʱ���߶�����һ���Ƴ��Ҷ˵�ʱ���߶�����һ
������״����ͳ��һ��ǰ׺�ͣ�ÿ��Lλ�ü�һ��R+1λ�ü�һ
*/

#define lowbit(x) (x&-x)

int MAX;//��״���������岿������±�
int x[100001]={0};

int sum(int n)//��ǰ׺��
{
	int ans=0;
	while(n>0)
	{
		ans+=x[n];
		n-=lowbit(n);
	}
	return ans;
}

void add(int p,int a)//�޸�ֵ��pλ�ã�a���ϵ�ֵ
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
            add(b+1,-1);//ע�⣬��Ϊ�˵�Ҳ�㣬���Խ���ʱ���Ҷ˵���һλ��
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

