#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<list>
#include<cmath>
#include<stack>
#include<queue>

using namespace std;

/*
有四种括号<>,(),[],{}，括号可以嵌套，但是嵌套时左边的只能在右边的里面
输入一个字符串，问其中的括号是否匹配

要解决两个问题，一是括号匹配问题，而是嵌套问题
括号匹配时，有一个就近原则，即右括号应当和未被匹配的最近的左括号匹配（反之一样）
怎么才能处理这个“最近”以及标记已经匹配的问题呢？正好可以用栈
遇到左括号时就push，遇到右括号时，栈顶就是距之最近的左括号，如果匹配，pop掉，就相当消除了已经匹配的括号

嵌套问题，可以给每个括号设一个优先级，优先级高的可以嵌套在优先级低的里面
也就是push左括号时，与栈顶左括号比较优先级，比之更高才可以push
*/

char x[1001];
stack<char> st;
map<char,char> mat;//右括号对应左括号
map<char,int> pr;//左括号优先级

bool isLeft(char c)
{
    if(c=='<'||c=='('||c=='['||c=='{')
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n,m,i,j,k,ans,len;
    mat['>']='<',mat[')']='(',mat[']']='[',mat['}']='{';
    pr['<']=4,pr['(']=3,pr['[']=2,pr['{']=1;
    bool flag;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",x);
        while(!st.empty())
        {
            st.pop();
        }
        flag=0;
        len=strlen(x);
        for(i=0;i<len;i++)
        {
            if(isLeft(x[i]))
            {
                if(!st.empty()&&pr[st.top()]>pr[x[i]])//优先级不可比栈顶（若有）元素低
                {
                    flag=1;
                    break;
                }
                else
                {
                    st.push(x[i]);
                }
            }
            else
            {
                if(!st.empty()&&st.top()==mat[x[i]])//栈顶必须要有元素与之匹配
                {
                    st.pop();
                }
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(st.empty()&&(!flag))//最后栈内不能有多余左括号
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}




