#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>

using namespace std;

/*
将中缀表达式转为后序表达式

中缀表达式就是我们所熟悉的，用之建一棵表达式树，前/中/后缀表达式就分别是对之进行前/中/后序遍历的结果
后缀表达式无需括号，从左向右扫，先遇到的运算符就先算即可
怎么将中缀表达式转为后序表达式呢？本质上就是将先参与的运算先输出
如果用栈，其实就是类比中缀表达式求解的过程，将操作数入栈，和运算符计算的顺序表达出来
*/

#define isD(c) (c>='0'&&c<='9')

stack<char> opt;//操作符
map<char,int> pr;//优先级

void init()
{
    //都考虑为左结合
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
    x[len]=')';//前后加括号辅助
    for(i=0;i<=len;i++)
    {
        if(isD(x[i]))//数字
        {
            num=x[i]-'0';
            for(j=i+1;j<=len&&isD(x[j]);j++)//向后读完
            {
                num*=10;
                num+=x[j]-'0';
            }
            printf("%d ",num);//需入栈，打印出来
            i=j-1;
        }
        else//运算符
        {
            if(x[i]=='(')//左括号比入栈
            {
				opt.push('(');
            }
            else if(x[i]==')')//右括号需要计算至匹配的左括号
            {
                while(opt.top()!='(')
                {
                    printf("%c ",opt.top());
                    opt.pop();
                }
                opt.pop();
            }
            else//操作符
            {
                while(pr[x[i]]<=pr[opt.top()])//计算至栈顶优先级更小再加入
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




