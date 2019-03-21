#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>

using namespace std;

/*
入栈顺序是1-n，先给出一个出栈序列，问是否合法
要注意以下几点：
某个元素出栈时，比之先入栈的元素，要么还在栈内，要么已经出栈
某个元素出栈时，已经入栈但比之靠近栈顶的也要跟着出栈
比如入栈1 2 3，出栈3 1 2就不合法，因为3出栈，代表1和2在栈内，1出栈，实际上1和2都出栈，最后2再出栈不可能，因为栈内已经没有2了

用2个栈模拟一下即可，help栈辅助存储入栈顺序，靠近栈顶为先入栈的，st就模拟出入栈过程
从左到右扫描出栈序列，当前元素若还未入栈，即help栈顶元素顺序小于它
就将help栈内顺序小于它的都移入st栈，删除该元素
若已入栈或出栈，即help内找不到它，则在st中不断寻找并pop，直到空都找不到说明不合法
*/

stack<int> st;
stack<int> help;

int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,k;
    bool flag;
    cin>>n;
    for(i=n;i>=1;i--)
    {
        help.push(i);//小的靠栈顶
    }
    while(n--)
    {
        cin>>k;
        if(!help.empty()&&help.top()<=k)//未入栈，将比之小的都入栈
        {
            while(!help.empty()&&help.top()<=k)
            {
                st.push(help.top());
                help.pop();
            }
        }
        else//还在栈内或已出栈
        {
            while(!st.empty()&&st.top()!=k)
            {
                st.pop();
            }
            if(st.empty())
            {
                printf("NO");
                return 0;
            }
            else
            {
                st.pop();
            }
        }
    }
    printf("YES");
    return 0;
}



