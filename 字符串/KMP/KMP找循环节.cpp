#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<cstdio>
using namespace std;

int Next[1000001];
char x[1000001];//ģʽ��

/*
�ʸ������ַ����ɼ���ѭ���ڹ���
����ĳ�ַ���ѭ�ڳ���Ϊi������Next[i+1]*2==i
֮��iÿ��1����ӦNextҲ��1 
�������Ƶ�i��β���ַ���ѭ���ڸ���Ϊ(i+1)/( (i+1)-Next[i+1] )��ǰ����������������������Ϊ1�� 
�����ĳ��ȳ��ԣ����ĳ��ȼ�ȥ�����ǰ׺��׺�������ȣ�Ҳ����ѭ���ڳ��ȣ� 
*/ 

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
	int lenx,i,T;
	while(scanf("%s",x))
	{
		if(x[0]=='.')
        {
            break;
        }
		lenx=strlen(x);
		Cal(lenx);
        printf("%d\n",lenx%(lenx-Next[lenx])==0?lenx/(lenx-Next[lenx]):1);
	}
	return 0;
} 





