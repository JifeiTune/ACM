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
��n����Ϊ������ĺ͵���ʽ���������
�ͼ�������һ�����涨�û���ʱ������˳�򣬾Ͳ����ظ�
dfs�ݹ����
*/
int all;
vector<int> ans;

void dfs(int n,int MIN)//��n����С��MIN����
{
    int i;
    for(i=MIN;i<=n-i;i++)
    {
        ans.push_back(i);
        dfs(n-i,i);
        ans.pop_back();//�ָ�
    }
    //������
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


