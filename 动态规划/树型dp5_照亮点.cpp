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
һ�ýڵ�Ϊn��������������ĳ���ڵ㲼��һ��ʿ��������õ������ĵ㶼�ܱ������������Լ���
ÿ���㲼��ʿ�����Ѳ�һ��
��ϣ�����е㶼�ܱ������������ٻ���
���Ʒ��ýֵƣ��߸ĳ��˵㣬����ͬ���ǣ����ǵ���iΪ��������ʱ
��ʹi���ӽڵ㶼���ţ�iҲ��һ��Ҫ�ţ���Ϊ������i�ĸ��ڵ��
���Կɷ�Ϊ���¼��ࣺ
1.i���ţ���������������������
2.i���ţ�����i����������������i�ܷ񿴵����ܣ�
3.i�ţ���������������������
����ת�ƿ�����
*/

int dp[1501][3];//��iΪ�����������е㶼��������iȡ�벻ȡʱ����С����
int val[1501];
vector<int> Tree[1501];
int n;

void dfs(int now,int fa)
{
    int len,n1,n2,to,i,j,t0=0x3f3f3f3f,t1=0,t2=0,temp;
    bool leaf=1;
    len=Tree[now].size();
    for(i=0;i<len;i++)
    {
        to=Tree[now][i];
        if(to!=fa)//��ֹ�ѻ�ȥ
        {
			leaf=0;
            dfs(to,now);
        }
    }

    for(i=0;i<len;i++)//ö�ٱ���Ҫ�ŵ��ӽڵ�
    {
        n1=Tree[now][i];
        temp=0;
        if(n1!=fa)
		{
			for(j=0;j<len;j++)
	        {
	            n2=Tree[now][j];
	            if(n2!=fa)
	            {
	                if(n2!=n1)//�ɷſɲ��ŵ��ӽڵ�
	                {
	                    temp+=min(dp[n2][0],dp[n2][2]);
	                }
	                else
	                {
	                    temp+=dp[n2][2];
	                }

	            }
	        }
			t0=min(t0,temp);
		}
    }
    for(i=0;i<len;i++)
    {
        n1=Tree[now][i];
        if(n1!=fa)
        {
            t1+=min(dp[n1][0],dp[n1][2]);
            t2+=min(dp[n1][0],min(dp[n1][1],dp[n1][2]));
        }
    }
    if(leaf)
    {
        dp[now][0]=dp[now][2]=val[now];
        dp[now][1]=0;
    }
    else
    {
        t2+=val[now];//���ڵ��
        dp[now][0]=t0,dp[now][1]=t1,dp[now][2]=t2;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    memset(dp,0x3f,sizeof(dp));//�����Ϊ����ֵ
    int i,j,fa,MAX=0,p,to,len,from,ans,num,root;
    bool fir=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&from);
        scanf("%d%d",&val[from],&num);
        if(fir)
        {
            fir=0;
            root=from;
        }
        while(num--)
        {
            scanf("%d",&to);
            Tree[from].push_back(to);
            Tree[to].push_back(from);
        }
    }
    dfs(root,-1);
    ans=min(dp[root][0],dp[root][2]);
    printf("%d",ans);
    return 0;
}
