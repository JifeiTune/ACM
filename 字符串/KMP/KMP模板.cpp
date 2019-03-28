#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
�±��0��ʼ 
�˴�ǰ��׺�������Լ��� 
�ַ���ƥ��ʱ�����赽��ģʽ��iλ�ò�ƥ�䣬��iλ����ǰ��˫������ȵ�
��������ģʽ����λ������ʼ�Ƶ�i֮ǰʱ�����൱���Լ���ƥ���Լ�
���Լ�ƥ���Լ���ÿ�����Ͻ������һ���ģ�����Ԥ�����¼��������ƥ��
����������ƥ�� 
ababdefg
ababc
��ǰ��cλ�ò�ƥ�䣬��ô��һ��Ӧ��ֱ��
ababdefg
  ababc
����ģʽ���±�2λ������ַ��Ƚϣ�δ�Ż�KMP�汾����ƥ���ַ����ܻ���֮ǰƥ���ַ���ȣ�
Next[i]��ʾ��iλ��ʧ��ʱ����һ�α�ƥ�䴮��λ��Ӧ����ģʽ���ĸ�λ�õ��ַ��Ƚ�
ʵ������Ϊģʽ����ͷ��i-1λ�õ��Ӵ���ǰ׺���׺��ͬʱ����󳤶�
��ģ��Next[0]=1������-1 
*/
using namespace std; 

int Next[10001];//��Next[i]+1=i��ʵ���Ϲ�������Ϊi 
int x[10001];//ģʽ�� 
int y[1000001];//��ƥ�� 

void Cal(int lenx)//����Next���飬lenxΪx���� 
{ 
    int i,j; 
    Next[0]=0,Next[1]=0;
	for(i=1;i<lenx;i++)
	{
		j=Next[i];
		while(j&&x[i]!=x[j])
		{
			j=Next[j];	
		}
		Next[i+1]=x[i]==x[j]?j+1:0;
	} 
}

int KMP(int lenx,int leny)
{
	Cal(lenx);
	int i,j=0;
	bool flag=1;
	for(i=0;i<leny;i++)
	{
		while(j!=0&&x[j]!=y[i])
		{
			j=Next[j];
		}
		if(x[j]==y[i])
		{
			j++;
		}
		if(j==lenx)
		{
			flag=0;
			return i-lenx+1;//�����ʼλ�� 
		}
	}
	if(flag)
	{
		return -2;
	}
}

int main()
{
	int lenx,leny,i,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&leny,&lenx);
		for(i=0;i<leny;i++)
		{
			scanf("%d",&y[i]);
		}
		for(i=0;i<lenx;i++)
		{
			scanf("%d",&x[i]);
		}
		printf("%d\n",KMP(lenx,leny)+1);
	}
	return 0; 
}

