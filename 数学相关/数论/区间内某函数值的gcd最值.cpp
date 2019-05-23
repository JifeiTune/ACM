#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<set>
#include<queue>

using namespace std;

/*
��ѵ���Ժ����������������۵��ⲻҪ����ס�����п���ֻ�Ƿ�Χ����Ĵ�������

����F(x)��ʾx�������Ӹ�����ÿ�θ���[L,R]��L��R������1e6������gcd(F(i),F(j))(L<=i<j<=R)�����ֵ
����������Ҫö��i��j����ʵ�ᷢ���ڸ�����Χ��F(x)����̫����Ϊ2*3*5*7*11*13*17*19ǡ�ô���1e6
����F(x)���ֵҲ��7���������ת��Ϊ�ж�[L,R]���Ƿ����ֵΪ1-7�ĵ㣨����˵�м�����
��ΪҲ�������¼��������1-7��ĳ�����ֳ�����2�λ����ϣ���gcd�����Ǹ�ֵ
�Լ�����2��4��2��6��3��6��������ֱ�Ϊ2��2��3
����Щֵ������󼴿ɣ���ֵ��СΪ1��

���ִ������Լ����ֶ��ٴε����⣬����ǰ׺�ͽ������ĳ��λ�ô��ڣ�����Ϊ1
���ǰ׺�ͣ�������ĸ���������������ͣ���Ϊ0��ʾ������
*/

#define MAX ((int)(1e6))//�˴�����ɸѡ��Χ

bool x[MAX+1];//���Ϊ1��ʾ�Ǻ�����0��ʾ����
int Num[MAX+1]={0};//�����Ӹ���
int pre[8][MAX]={{0}};//ǰ׺��
vector<int> Pri;

inline void getP()
{
	long long bs,i;
	long long range=(long long)(sqrt(MAX)+1);
	memset(x,0,sizeof(x));//��ȫ�����Ϊ����
	for(i=2;i<=range;i++)
	{
		if(!x[i])//δ��ǣ�˵��������
		{
			bs=i;//����һ��ʼ����Ϊi����ΪС��i����֮ǰ�Ѿ�ɸ��
			while(bs*i<=MAX)
			{
				x[bs*i]=1;
				bs++;
			}
		}
	}
}

int has[8];//has[i]��ʾΪi�ĸ���

int main()
{
    int i,j,bs=0,len,temp,ans,T,L,R;
    getP();
    Pri.reserve(100000);
    for(i=2;i<=MAX;i++)
    {
        if(!x[i])
        {
            Pri.push_back(i);
        }
    }
    len=Pri.size();
    for(i=0;i<len;i++)
    {
        //printf("%d\n",Pri[i]);
        temp=Pri[i];
        while(temp<=MAX)
        {
            ++Num[temp];
            temp+=Pri[i];
        }
    }
    for(i=1;i<=MAX;i++)
    {
        pre[Num[i]][i]=1;
    }
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=MAX;j++)
        {
            pre[i][j]+=pre[i][j-1];
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        ans=1;
        scanf("%d%d",&L,&R);
        for(i=1;i<=7;i++)
        {
            has[i]=pre[i][R]-pre[i][L-1];
            if(has[i]>1)
            {
                ans=i;//��ĸ���С��
            }
        }
        if(has[2]&&has[4]||has[2]&&has[6])
        {
            ans=max(ans,2);
        }
        if(has[3]&&has[6])
        {
            ans=max(ans,3);
        }
        printf("%d\n",ans);
    }
	return 0;
}
