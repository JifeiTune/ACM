#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<deque>

using namespace std;

/*
这题……返回值本应void的函数忘删int，并且忘记return，竟然Killed: Segmentation fault……
调死我了这个错误……

一个字符串A，每次从中找第一个等于B的子串，将之删除
剩下的子串再合并为一个，重复此过程直到找不到，问最终串

用KMP匹配到一个完整的B串后，应及时将匹配到的删除，假设当时A串为XBY
但删除后下一步该从那开始匹配呢？当然不可能再从X的头开始匹配
实际上在之前的匹配过程中，X的后缀可能已经和B的前缀有了一部分匹配
所以记录下A串中，每个位置的字符，已经匹配到了B串的哪个位置
之后直接使用即可
*/

int Next[1000001];//若Next[i]+1=i，实际上公共长度为i
char x[1000001];//模式串
char y[1000001];//被匹配

struct Node
{
    char c;
    int num;
    Node(char _c,int _num):c(_c),num(_num){}
};

deque<Node> st;

void Cal(int lenx)//计算Next数组，lenx为x长度
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
        st.push_back(Node(y[i],j));//推入当前字符，以及当前字符位置匹配了多少字符
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
