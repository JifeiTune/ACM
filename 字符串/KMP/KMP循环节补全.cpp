#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<cstdio>
using namespace std;
/*
��һ���ַ������������ں��油�����ַ��ܹ���ѭ��
��ѭ���ڳ���(lenx-Next[lenx])����Ȼǰ����lenx%(lenx-Next[lenx])==0
����ѭ��������Ϊ1��lenx��������Ҫ��
������ѭ��������Ե�����lenx�ټӶ��ٲ���������(lenx-Next[lenx])
��Ϊѭ���У�iÿ��1��NextҲ��1 
*/
int Next[100001];
char x[100001];//ģʽ��

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

int main()
{
	int lenx,i,T,tem;
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%s",x);
		lenx=strlen(x);
		Cal(lenx);
		if(lenx%(lenx-Next[lenx])==0)//�Ѿ�����ѭ��
		{
			printf("%d\n",lenx/(lenx-Next[lenx])==1?lenx:0);//��ֹѭ��Ϊ1����ʵ�ʷ�ѭ��
		}
		else//���ʹ������������ѭ��
		{
			printf("%d\n",(lenx-Next[lenx])-lenx%(lenx-Next[lenx]));
		}
	}
	return 0;
}





