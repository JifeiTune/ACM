#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<random>
#include<functional>
using namespace std;

/*
����һ���������У����䳤�Ȳ�С��Len���ӶΣ�ʹ���Ӷεľ�ֵ������������ֵ

����ֵ����ʱ���ж��Ƿ���ڲ�С��Len���Ӷ��ǿ�����O(N)����ɵ�
��Ϊ����ԭ����ÿ������ȥ��ֵ����ת������һ����С��Len���ӶΣ�ʹ���Ӷκ�>=0
�Ӷκ͵�Ȼ������ǰ׺��O(1)��⣬��������Ӷ���ô���أ�����ҪO(N^2)ö���Ҷ˵�
��ʵ���ã��Ӷκ���ǰ׺�ͱ�ʾΪpre[R]-pre[L-1]��Ҫ����>=0����Ȼϣ��pre[L-1]ԽСԽ��
����ֻ��ö��R������¼��߾�R����Len��preֵ�У���С���Ǹ���ÿ��pre[R]��ȥ������
���־�ֵ���Ϳ���O(NlogN)��� 
*/

int x[100001];
int n,MAX;
#define INF 0x3f3f3f3f
long long pre[100001];//ǰ׺��

inline bool isOk(int ave)//���ܷ��ҵ�һ���ӶΣ�ʹ���ֵ��С��ave
{
    long long MIN=0x3f3f3f3f3f3f3f3f;
    int i,p;
    for(i=1;i<=n;i++)
    {
    	pre[i]=pre[i-1]+x[i]-ave;//��ȥ��ֵ����ǰ׺��
	}
    for(i=MAX;i<=n;i++)
    {
        if(pre[i-MAX]<MIN)//ȡ��С��
		{
			MIN=pre[i-MAX];
		}
		if(pre[i]-MIN>=0)
		{
			return 1;
		}
    }
    return 0;
}

int main(int argc, char* argv[])
{
	int i,last,L=INF,R=-INF,mid;
	scanf("%d%d",&n,&MAX);
	pre[0]=0;
	for(i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        x[i]*=1000;//���վ�������1000��
        L=min(L,x[i]);
        R=max(R,x[i]);
    }
    pre[0]=0;
    while(L<=R)
    {
        mid=(L+R)/2;//���־�ֵ
        if(isOk(mid))
        {
            last=mid;
            L=mid+1;
        }
        else
        {
            R=mid-1;
        }
    }
    printf("%d",last);
	return 0;
}
