#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>

using namespace std;

/*
����׺���ʽתΪ������ʽ

��׺���ʽ������������Ϥ�ģ���֮��һ�ñ��ʽ����ǰ/��/��׺���ʽ�ͷֱ��Ƕ�֮����ǰ/��/��������Ľ��
��׺���ʽ�������ţ���������ɨ��������������������㼴��
��ô����׺���ʽתΪ������ʽ�أ������Ͼ��ǽ��Ȳ�������������
�����ջ����ʵ���������׺���ʽ���Ĺ��̣�����������ջ��������������˳�������
*/

#define isD(c) (c>='0'&&c<='9')

stack<char> opt;//������
map<char,int> pr;//���ȼ�

void init()
{
    //������Ϊ����
    pr['(']=0,pr['+']=1,pr['-']=1,pr['*']=2,pr['/']=2,pr['^']=3;
}

char x[10001];

int main()
{
	init();
    int n,m,i,j,k,ans,len,num;
    x[0]='(';
    scanf("%s",x+1);
    len=strlen(x+1)+1;
    x[len]=')';//ǰ������Ÿ���
    for(i=0;i<=len;i++)
    {
        if(isD(x[i]))//����
        {
            num=x[i]-'0';
            for(j=i+1;j<=len&&isD(x[j]);j++)//������
            {
                num*=10;
                num+=x[j]-'0';
            }
            printf("%d ",num);//����ջ����ӡ����
            i=j-1;
        }
        else//�����
        {
            if(x[i]=='(')//�����ű���ջ
            {
				opt.push('(');
            }
            else if(x[i]==')')//��������Ҫ������ƥ���������
            {
                while(opt.top()!='(')
                {
                    printf("%c ",opt.top());
                    opt.pop();
                }
                opt.pop();
            }
            else//������
            {
                while(pr[x[i]]<=pr[opt.top()])//������ջ�����ȼ���С�ټ���
                {
                    printf("%c ",opt.top());
                    opt.pop();
                }
                opt.push(x[i]);
            }
        }
    }
    return 0;
}




