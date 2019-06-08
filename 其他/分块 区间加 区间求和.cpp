#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<list>

using namespace std;

/*
�±��0��ʼ��BsizeΪ���С
���±�Ϊi�������ڵ�i/Bsize�飨Ҳ��0��ʼ��������ʱ��iΪ�ÿ����ʼ
ĩβ�����в�ȱ���֣��ǲ��ֱ���������Ҫ��sum��lazy�а��鿼��
*/

#define MAXN int(5e4+1)
#define BMAXN int(1e3+1)//����

typedef long long LL;

LL x[MAXN];//ԭ����
int len;//���鳤��
int Bsize;//���С
int belong[MAXN];
LL sum[BMAXN]={0};//ÿһ��������
LL lazy[BMAXN]={0};//ÿһ������ϵ���

void init()
{
    Bsize=sqrt(len);
    //��������ʱ�����sum��lazy
    int i;
    for(i=0;i<len;i++)
    {
    	belong[i]=i/Bsize;
        sum[belong[i]]+=x[i];
    }
}

void add(int L,int R,int val)//[L,R]����val
{
    int i;
    for(i=L;i<=R;)
    {
        if(i%Bsize==0&&i+Bsize-1<=R)//ֻ����ȫ��һ���ͳһ����
        {
            lazy[belong[i]]+=val;//�ӵ�lazy��
            i+=Bsize;
        }
        else//���Ⱪ������
        {
            x[i]+=val;
            sum[belong[i]]+=val;//���ڿ��ܺ�ҲҪ��
            ++i;
        }
    }
}

LL query(int L,int R)//��[L,R]֮��
{
    int i;
    LL ans=0;
    for(i=L;i<=R;)
    {
        if(i%Bsize==0&&i+Bsize-1<=R)//ֻ����ȫ��һ���ͳһ����
        {
            //�ÿ�Ľ�������ϸÿ�lazy�ϴ������
            ans+=sum[belong[i]]+lazy[belong[i]]*Bsize;
            i+=Bsize;
        }
        else//���Ⱪ������
        {
            ans+=x[i]+lazy[belong[i]];
            ++i;
        }
    }
    return ans;
}


int main()
{
    int T,i,q,L,R,val,op;
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        scanf("%lld",&x[i]);
    }
	init();
    for(i=1;i<=len;i++)
    {
        scanf("%d%d%d%d",&op,&L,&R,&val);
        if(op==0)//����
        {
            add(L-1,R-1,val);
        }
        else//ѯ��
        {
            printf("%lld\n",query(L-1,R-1));
        }
    }
    return 0;
}



