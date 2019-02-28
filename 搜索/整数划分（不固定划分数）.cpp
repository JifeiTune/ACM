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
将n划分为多个数的和的形式，输出所有
和计数问题一样，规定好划分时的升降顺序，就不会重复
dfs递归求解
*/
int all;
vector<int> ans;

void dfs(int n,int MIN)//将n按不小于MIN划分
{
    int i;
    for(i=MIN;i<=n-i;i++)
    {
        ans.push_back(i);
        dfs(n-i,i);
        ans.pop_back();//恢复
    }
    //不划分
    ans.push_back(n);
    printf("%d=%d",all,ans[0]);
    for(i=1;i<ans.size();i++)
    {
        printf("+%d",ans[i]);
    }
    putchar('\n');
    ans.pop_back();
}

int main()
{
    scanf("%d",&all);
    dfs(all,1);
    return 0;
}


