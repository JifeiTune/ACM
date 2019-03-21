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
����������<>,(),[],{}�����ſ���Ƕ�ף�����Ƕ��ʱ��ߵ�ֻ�����ұߵ�����
����һ���ַ����������е������Ƿ�ƥ��

Ҫ����������⣬һ������ƥ�����⣬����Ƕ������
����ƥ��ʱ����һ���ͽ�ԭ�򣬼�������Ӧ����δ��ƥ��������������ƥ�䣨��֮һ����
��ô���ܴ��������������Լ�����Ѿ�ƥ��������أ����ÿ�����ջ
����������ʱ��push������������ʱ��ջ�����Ǿ�֮����������ţ����ƥ�䣬pop�������൱�������Ѿ�ƥ�������

Ƕ�����⣬���Ը�ÿ��������һ�����ȼ������ȼ��ߵĿ���Ƕ�������ȼ��͵�����
Ҳ����push������ʱ����ջ�������űȽ����ȼ�����֮���߲ſ���push
*/

char x[1001];
stack<char> st;
map<char,char> mat;//�����Ŷ�Ӧ������
map<char,int> pr;//���������ȼ�

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
                if(!st.empty()&&pr[st.top()]>pr[x[i]])//���ȼ����ɱ�ջ�������У�Ԫ�ص�
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
                if(!st.empty()&&st.top()==mat[x[i]])//ջ������Ҫ��Ԫ����֮ƥ��
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
        if(st.empty()&&(!flag))//���ջ�ڲ����ж���������
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




