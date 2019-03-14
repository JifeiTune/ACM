#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

/*
�鲢����������Զ���
����Ӧ֪������[L1,R1]��[L2,R2]����L2>R1
[L1,R1]������˳��ı䣬������ı�һ����[L1,R1]��
��һ�����������������Զ�������Ϊ�������λ�ã�˭��˭�Ҳ�û�б䣩
���Թ鲢ʱ��ÿ��������ͷԪ�ش���������ͷԪ�أ����������
����Ϊ�����䵱ǰʣ�µ�Ԫ�ظ��� 
*/
#define MAXN 100001
int x[MAXN+1];
int y[MAXN+1];//�������� 
long long Rnum;//����Զ��� 

void Merge(int L,int R,int M)
{
	//��x��L��M��M+1��R�����֣��ϲ���y�е�L��R��
	int i,j,k,tem;
	i=L,j=M+1,k=L;
	while(i<=M&&j<=R)//�����ֶ�����ȡʱ 
	{
		//ȡ��С�ķ�ǰ��
		if(x[i]<=x[j])
		{
			y[k++]=x[i++];
		}
		else//����������ͷԪ�ظ���ʱ������ԣ�ע�����ϸ���ڣ������Ǵ��ڵ��ڣ��� 
		{
			Rnum+=M-i+1;//������ʣ�µĶ���������ͷԪ�ش� 
			y[k++]=x[j++];
		}
	}
	//����Ҫô���߶�ȡ�꣬Ҫôֻʣһ����δȡ�� 
	while(i<=M)
	{
		y[k++]=x[i++];
	}
	while(j<=R)
	{
		y[k++]=x[j++];
	}
	for(i=L;i<=R;i++)
	{
		x[i]=y[i];//���ƻ�ȥ 
	}
}

void Part(int L,int R)//��� 
{
	int M;
	if(R>L)//���ȴ���1����Ҫ��� 
	{
		M=(L+R)/2;
		Part(L,M);
		Part(M+1,R);
		Merge(L,R,M);//�Ȳ�ֳ�2���֣��ֱ������ٺϲ� 
	}
}

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	Rnum=0;
	Part(1,n);
	printf("%lld",Rnum);
    return 0;
}
