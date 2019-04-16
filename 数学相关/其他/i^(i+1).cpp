#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

/*
����F(i)��ʾi���(i+1)�Ķ����Ʊ�ʾ�У�1�ĸ��� 
��i��[L,R]��Χ�ڣ�F(i)�ĺ�Ϊ����
����֣���n��ʼ��Ϊ2^(n-1)-1��ÿ��2^n����һ��
ÿ�θ����Ҷ˵��������n���ٴ�1��n�ֱ��󼴿� 
*/ 

inline int getNum(int n,int R)//[0,R]��Χ�ڣ�n���ִ���
{
    if(R<0)
    {
        return 0;
    }
    int ans=0,be=(1<<(n-1))-1,d=(1<<n);
    if(be<=R)
    {
        ans=(R-be)/d+1;//�Ȳ�����ͨ�ʽת�� 
    }
    return ans;
}

int main()
{
	int i,j,k,T,Time,L,R,MAX;
	long long ans=0;
    scanf("%d",&T);
    while(T--)
    {
    	ans=0;
        scanf("%d%d",&L,&R);
        MAX=1;
        while(((1<<(MAX-1))-1)<=R)
        {
            ++MAX;
        }
        --MAX;
        for(i=1;i<=MAX;i++)
        {
            ans+=(getNum(i,R)-getNum(i,L-1))*(long long)i;
        }
        printf("%d\n",ans);
    }
	return 0;
}
