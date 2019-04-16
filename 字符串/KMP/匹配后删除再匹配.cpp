#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<deque>

using namespace std;

/*
���⡭������ֵ��Ӧvoid�ĺ�����ɾint����������return����ȻKilled: Segmentation fault����
��������������󡭡�

һ���ַ���A��ÿ�δ����ҵ�һ������B���Ӵ�����֮ɾ��
ʣ�µ��Ӵ��ٺϲ�Ϊһ�����ظ��˹���ֱ���Ҳ����������մ�

��KMPƥ�䵽һ��������B����Ӧ��ʱ��ƥ�䵽��ɾ�������赱ʱA��ΪXBY
��ɾ������һ���ô��ǿ�ʼƥ���أ���Ȼ�������ٴ�X��ͷ��ʼƥ��
ʵ������֮ǰ��ƥ������У�X�ĺ�׺�����Ѿ���B��ǰ׺����һ����ƥ��
���Լ�¼��A���У�ÿ��λ�õ��ַ����Ѿ�ƥ�䵽��B�����ĸ�λ��
֮��ֱ��ʹ�ü���
*/

int Next[1000001];//��Next[i]+1=i��ʵ���Ϲ�������Ϊi
char x[1000001];//ģʽ��
char y[1000001];//��ƥ��

struct Node
{
    char c;
    int num;
    Node(char _c,int _num):c(_c),num(_num){}
};

deque<Node> st;

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

void Solve(int lenx,int leny)
{
	Cal(lenx);
	int i,j=0;
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
        st.push_back(Node(y[i],j));//���뵱ǰ�ַ����Լ���ǰ�ַ�λ��ƥ���˶����ַ�
		if(j==lenx)
		{
			int num=lenx;
			while(num--)
            {
                st.pop_back();
            }
            if(!st.empty())
			{
				j=st.back().num;
			}
            else
            {
                j=0;
            }
		}
	}
}

int main()
{
	int lenx,leny,i;
	scanf("%s%s",y,x);
	lenx=strlen(x);
	leny=strlen(y);
	Solve(lenx,leny);
    while(!st.empty())
    {
        printf("%c",st.front().c);
        st.pop_front();
    }
	return 0;
}
