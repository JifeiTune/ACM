#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>

using namespace std;

/*
ÿ�λ��ڸ���������һ�������������֮ǰ�ֵ����඼��ͬ
ÿ��ѯ��ĳ������������������

����ʱ������㵽�յ���һ���ߣ������ת��Ϊ�������������ߵĸ�����ֻ�ж˵�Ҳ�㣩
�Ǿ��������ߣ��˵㶼�������ڵģ���ֻ���Ҷ˵������˵��������ڵ�
�˵㶼�������ڵĲ������֣����Է��������ǣ���������ȥ���������ڵ�
���������ڵľͺܺ����ˣ�ͳ��������ߣ��Ҷ˵�ĸ������������ұߣ���˵�ĸ���
����״���鼴��
*/

#define lowbit(x) (x&-x)

int MAX;//��״���������岿������±�
int L[50001]={0};
int R[50001]={0};

int sum(int *x,int n)//��ǰ׺��
{
	int ans=0;
	while(n>0)
	{
		ans+=x[n];
		n-=lowbit(n);
	}
	return ans;
}

void add(int *x,int p,int a)//�޸�ֵ��pλ�ã�a���ϵ�ֵ
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
        cin>>op>>a>>b;
        if(op==1)
        {
            ++kind;
            add(R,b,1);
            add(L,a,1);
        }
        else
        {
            cout<<kind-sum(R,a-1)-(sum(L,MAX)-sum(L,b))<<'\n';
        }
    }
	return 0;
}

