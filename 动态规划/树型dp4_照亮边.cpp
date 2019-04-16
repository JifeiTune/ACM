#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

/*
һ�ýڵ�Ϊn��������������ĳ���ڵ㲼��һ��ʿ��������õ������ı߶��ܱ�����
��ϣ�����б߶��ܱ������������ٲ��ü���ʿ��

���ýֵƵļ򻯰�
dp[i][2]��ʾ��iΪ������������ѡ�Ͳ�ѡiʱ�����ϵı߶��ܿ���ʱ����Сѡ����
��ô��ѡi�����ӽڵ�ѡ�Ͳ�ѡ������Ӱ��i���ӽڵ�ı�
����ѡi���������ӽڵ㶼����ѡ���ܿ�������i���ӽڵ�ı�
*/

int dp[1501][2];
vector<int> Tree[1501];
int n;

void dfs(int now,int fa)
{
    int len,to,i,t0=0,t1=0;
    len=Tree[now].size();
    for(i=0;i<len;i++)
    {
        to=Tree[now][i];
        if(to!=fa)//��ֹ�ѻ�ȥ
        {
            dfs(to,now);
            t0+=dp[to][1];//���ڵ㲻�ţ���ô�����ӽڵ㶼�����
            t1+=min(dp[to][0],dp[to][1]);//���ڵ�ţ���ô�ӽڵ���벻�Ŷ�OK
        }
    }
    dp[now][0]=t0;
    dp[now][1]=t1+1;//���ϱ��ڵ�ŵ�
}

int main()
{
    ios::sync_with_stdio(false);
    memset(dp,0x3f,sizeof(dp));//�����Ϊ����ֵ
    int i,j,fa,MAX=0,p,to,len,from,ans,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&from,&num);
        while(num--)
        {
            scanf("%d",&to);
            Tree[from].push_back(to);
            Tree[to].push_back(from);
        }
    }
    dfs(0,-1);//��0Ϊ��
    printf("%d",min(dp[0][0],dp[0][1]));
    return 0;
}
