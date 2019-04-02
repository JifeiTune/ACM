#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

/*
给若干字符串，问每个字符串所有公共前后缀的长度，从小到大输出 

枚举公共前后缀长度，对前后缀采用同一套hash，即对应位的位权要一样
先对原串hash一次，并求出前缀和
枚举公共前后缀长度时，分别求前缀和，并看看位权相差多少倍，乘上使得相同，再比较是否相同即可 
*/

stack<int> all;

char x[1000001];

typedef unsigned int ui;

ui base=131;
ui pre[1000001];

int main()
{
    int len,i;
    ui temp;
    while(~scanf("%s",x))
    {
    	temp=base; 
        len=strlen(x);
        pre[0]=x[0];
        for(i=1;i<len;i++)
        {
            pre[i]=pre[i-1]+temp*x[i];
            temp*=base;
        }
        all.push(len);//自己在里面
        temp=base;
        for(i=1;i<len;i++)//枚举后缀起始位置
        {
            if(pre[len-i-1]*temp==(pre[len-1]-pre[i-1]))//乘上temp，调整每位位权相同
            {
                all.push(len-i);
            }
            temp*=base;
        }
        while(!all.empty())
        {
            printf("%d ",all.top());
            all.pop();
        }
        putchar('\n');
    }


    return 0;
}
