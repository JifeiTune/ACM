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
给定一个大数，要求删去给定个数的数，使得剩下的数最小
被坑了，剩下的数可以不是标准格式如000、001，自己化为标准型
类比递归求组合，每次在能选的范围内选第一个最小的那个，剩余的递归处理
*/
char x[240];
int len;
vector<char> ans;

void com(int be,int num)//从be位置选num个
{
    int ed=len-num,p,i,out=0;
    char MIN='9'+1;
    bool fir=1;
    if(num==0)//结束条件
    {
        for(i=0;i<ans.size();i++)
        {
            if(ans[i]!='0'||(!fir))
            {
                putchar(ans[i]);
                fir=0;
                out++;
            }
        }
        if(out==0)
        {
            putchar('0');
        }
        return;
    }
    for(i=be;i<=ed;i++)
    {
        if(x[i]<MIN)//防止首位为0
        {
            MIN=x[i];
            p=i;
        }
    }
    ans.push_back(MIN);
    com(p+1,num-1);
}

int main()
{
    int num,i;
    char MIN='9'+1;
    scanf("%s%d",x,&num);
    len=strlen(x);
    num=len-num;
    com(0,num);
    return 0;
}


