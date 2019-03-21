#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<stack>
#include<cstring>
using namespace std;
/*
��������׺���ʽ��ֵ
+ - *�Ѿ��¶����d��d�����ȼ�����* 
xdy��ʾ��[1,y]�����ȡx�β���ͣ���Ȼ��ΧΪ[x,xy]
�ʱ��ʽ����Сֵ�����ֵ
��ÿһ����������һ�����䣬ÿ�μ���Ҳ��Ϊ���伴��

ע����ֵ���̵Ĵ���ȽϾɣ���Щд�����ã��ɲο���׺���ʽ��ֵ�� 
*/ 
struct Node
{
	int L,R;
	Node(){}
	Node(int _L,int _R):L(_L),R(_R){}
};

char S[210];
int len;//���� 

stack<Node> nums;//������ 
stack<char> ops;//������ 
int MAX[4];

inline Node Cal()//����һ�β�ѹջ 
{
	Node t1,t2,ans;
	char c;
	t2=nums.top();
	nums.pop();
	t1=nums.top();
	nums.pop();
	c=ops.top();
	ops.pop();
	switch(c)
	{
		case '+':
		{
			ans.L=t1.L+t2.L;
			ans.R=t1.R+t2.R;
			break;
		}
		case '-':
		{
			ans.L=t1.L-t2.R;
			ans.R=t1.R-t2.L;
			break;
		}
		case '*':
		{
			MAX[0]=t1.L*t2.L;
			MAX[1]=t1.L*t2.R;
			MAX[2]=t1.R*t2.L;
			MAX[3]=t1.R*t2.R;
			sort(MAX,MAX+4);
			ans.L=MAX[0];
			ans.R=MAX[3];
			break;
		}
		case 'd':
		{
			ans.L=t1.L;
			ans.R=t1.R*t2.R;
			break;
		}
	}
	nums.push(ans);
}

inline void insert(int p)//��pλ�ü�0 
{
	len++;
	for(int i=len-1;i>p;i--)
	{
		S[i]=S[i-1];
	}
	S[p]='0';
}

inline int read(int p)//��pλ�ö�һ����������ջ 
{
	int ans=S[p]-'0';
	p++;
	while(S[p]>='0'&&S[p]<='9')
	{
		ans*=10;
		ans+=S[p]-'0';
		p++;
	}
	nums.push(Node(ans,ans));
	return p;
}

inline int jb(char c)
{
	switch(c)
	{
		case '(':
		{
			return 11;
		}
		case 'd':
		{
			return 10;
		}
		case '*':
		{
			return 9;
		}
		case '-':
		{
			return 7;
		}
		case '+':
		{
			return 7;
		}
		case '=':
		{
			return 1;
		}	
	}	
} 

int main()
{
	int T,i,j,k,ans,tem,num;
	while(~scanf("%s",S))
	{
		len=strlen(S);
		S[len]='=';
		len++;
		ops.push('=');//����
		if(S[0]=='-')
		{
			insert(0);
		}
		for(i=1;i<len;i++)
		{
			if(S[i]=='-'&&S[i-1]=='(')
			{
				insert(i);
				i++; 
			}
		}
		for(i=0;i<len;i++)
		{
			if(S[i]>='0'&&S[i]<='9')//����
			{
				i=read(i)-1;
			}
			else
			{
				if(S[i]=='=')//������� 
				{
					while(ops.top()!='=')
					{
						Cal();
					}
					break;
				}
				else if(S[i]==')')//������ջ��Ϊ�� 
				{
					while(ops.top()!='(')
					{
						Cal();
					}
					ops.pop();//��ȥ( 
				}
				else if(S[i]=='(')//����ջ 
				{
					ops.push('(');
				}
				else
				{
					if(jb(S[i])>jb(ops.top())||(S[i]=='d'&&ops.top()=='d'))
					{
						ops.push(S[i]);
					}
					else
					{
						while(ops.top()!='('&&jb(S[i])<=jb(ops.top()))
						{
							Cal();
						}
						ops.push(S[i]);
					}
				}
			}
		}
		printf("%d %d\n",nums.top().L,nums.top().R);		
	} 
	return 0; 
}


