#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>

using namespace std;

/*
����һ��ð���������
����������У�ĳ��Ԫ��λ�û�仯
��һ���������ô˴�������������������У�ÿ��Ԫ��λ�����������

�����Ĵ��룬��ÿ�δ�������ð����С��������
ð������ʱ��ÿ�ζ������ڵ�Ԫ�رȽϣ������ܽ���˳��
���ԣ�һ��Ԫ���������Ƽ��Σ�ȡ�������ұ߱���С��Ԫ�ظ�����ͳ�������ͨ����״������ 
���λ��֪��������Ϊ��������������λ��Ҳ֪��
��Ԫ������ߵ�λ�ã������ܱ�����λ�û�������Ϊ�����ߵ�ǰ��������б������Ԫ��
ͳ�Ƴ�ʼλ�á�����λ�úͿ������ҵ�λ���е����ֵ����Сֵ��������� 
*/

#define lowbit(x) (x&-x)

int MAX;//��״���������岿������±�
int last[100005];//ԭ
int x[100005];
int ans[100005];//��ĳ�����ұ߲��ұȸ���С��Ԫ�ظ���

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
	int T,n,i,j,k,tem,L,R,cas=1;
	cin>>T;
	while(T--)
    {
        cin>>n;
        MAX=n;
        memset(x,0,sizeof(int)*(n+1));
        for(i=1;i<=n;i++)
        {
            cin>>last[i];
        }
        for(i=1;i<=n;i++)
        {
            add(last[n-i+1],1);//��һ
            L=R=n-i+1;//���ڵ�λ��
            R+=sum(last[n-i+1]-1);//���ܸ��ҵ�λ��
            R=max(R,last[n-i+1]);
            L=min(L,last[n-i+1]);
            ans[last[n-i+1]]=abs(R-L);
        }
        printf("Case #%d: ",cas++);
        printf("%d",ans[1]);
        for(i=2;i<=n;i++)
        {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
	return 0;
}

