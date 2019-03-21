#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>

using namespace std;

/*
本题只需实现+、-、*、/、^

带括号中缀表达式求值，本质上就是要解决，哪部分先算，哪部分后算的问题，
另外要注意求值有一个“就近原则”，即运算符计算时，总是取与之最近的操作数
我们在扫描一个表达式是从左到右的，但是求解时，却不一定是先出现的运算符就先算，还需考虑优先级问题
即，后出现的运算符可能要先参与运算，所以读到一个运算符时，不一定要立即参与运算，可能要暂时保留，后面再算
想要暂时保留前面未解决的，还要解决就近的问题，正好可以用栈来实现，就近就是取栈顶
因为最后栈内还剩下元素，是每次从栈顶取的，也就是从右往左算，所以这个栈其实是个单调栈，栈内运算符优先级递增
括号内部当然是要先算的，如果不考虑括号，简单来说就是：
当前运算符优先级低于栈顶，计算至栈顶优先级更小，然后压入栈
高于栈顶则直接压入，括号的问题需特殊处理，见下方实际实现

同样的运算符要考虑结合性问题，左结合只同运算符连续时，先算左边的，右结合反之
结合性给相同运算符内部又定义了一个优先级，即连续时先出现或者后出现的优先级更高

实际实现：
为了统一过程，即扫描完后就能计算完，在字符串首位添加括号，即用()括起来
如果数可以有负数，可以先在前面添加0方便处理
一次计算Cal()表示从操作数栈退出2个数（注意顺序，后出的在左）
再从操作符栈退出一个操作符，计算后值压入操作数栈
从左到右读字符串

优先级和结合性体现在入栈上，只有当前读到操作符优先级大于操作符栈顶，才入栈
但如果是右结合的，相等时也要入栈！！！！！！！！！！！！！
如果小于，则不断计算直到操作符栈顶优先级比读到的更小
为了统一过程，'('的优先级可设为极小，但读到必入栈
*/

int Pow(int x,int n)
{
    if(n==0||x==1)
    {
        return 1;
    }
    int ans=1;
    while(n--)
    {
        ans*=x;
    }
    return ans;
}

#define isD(c) (c>='0'&&c<='9')

stack<char> opt;//运算符
stack<int> opd;//操作数
map<char,int> pr;//优先级

void Cal()//取栈顶计算，并入栈
{
    int a,b;
    char op;
    op=opt.top(),opt.pop();
    b=opd.top(),opd.pop();
    a=opd.top(),opd.pop();
    if(op=='+') opd.push(a+b);
    else if(op=='-') opd.push(a-b);
    else if(op=='*') opd.push(a*b);
    else if(op=='/') opd.push(a/b);
    else if(op=='^') opd.push(Pow(a,b));
}

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
            opd.push(num);
            i=j-1;
        }
        else//运算符
        {
            if(x[i]=='(')//左括号必入栈
            {
                opt.push('(');
            }
            else if(x[i]==')')//右括号需要计算至匹配的左括号
            {
                while(opt.top()!='(')
                {
                    Cal();
                }
                opt.pop();
            }
            else//操作符
            {
                while(pr[x[i]]<=pr[opt.top()])//计算至栈顶优先级更小再加入
                {
                    Cal();
                }
                opt.push(x[i]);
            }
        }
    }
    cout<<opd.top();
    return 0;
}




