#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

/*
�и�����������������̾��룬���Ǹ��Ե����ߵ�����������Ⱦ���֮��
����Ƕ��������������������������¼ʱ����
��Ȼ��������������й������ȵ�ʱ���򶼼�������֮��
������Ƕ������أ�ÿ�εݹ���һ������������ʱ���ټ�¼һ�ε�ǰ�ڵ㼴��
��һ�α�����һ���ڵ�ʱҲҪ��¼
����ܼ�¼���ٸ����أ�ÿ���ȶ���ʹ��һ���㱻��¼һ�Σ����ڵ���һ����������
���Լ�¼�����鿪������2�����㹻
��Ȼ�����м�Ĳ��Ƕ��ǹ������ȣ����������С�ģ���������ľ��������������
*/
#define MAXN 100001

vector<int> G[MAXN];
int dep[MAXN];//�����ȣ�������Ϊ0
int ord[MAXN];//�������ʱÿ�����һ�γ��ֵ�ʱ����
int MIN[2*MAXN][20];//RMQʹ�ã�MIN[i][0]��ʾʱ����Ϊi�ĵ�����
int Time;

void init(int len)//��ʼ������������init��
{
	int i,j;
	for(j=1;(1<<j)<=len;j++)
	{
		for(i=1;i+(1<<j)-1<=len;i++)//ע�ⷶΧ��������δ���������±���м��������
		{
			MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);//���ֳɳ�����ȵ�����������
		}
	}
}

int answer(int i,int j)
{
	if(i>j)
	{
		swap(i,j);
	}
	int dis=j-i+1,k=0;
	while((1<<(++k))<=dis);
    --k;
	return min(MIN[i][k],MIN[j-(1<<k)+1][k]);
}

void dfs(int n,int d,int fa)//��ǰ�ڵ㡢��ǰ��ȡ���ǰ�ڵ�ĸ��ڵ�
{
    int len=G[n].size(),i,to;
    ++Time;
    ord[n]=Time;//��¼��һ�α���ʱ��ʱ����
    dep[n]=d;//��¼���
    MIN[Time][0]=d;
    for(i=0;i<len;i++)
    {
        to=G[n][i];
        if(to!=fa)//���ѻ�ȥ��
        {
            dfs(to,d+1,n);
            ++Time;
            MIN[Time][0]=d;//ÿ�λ���ʱ���ټ�¼һ�α��ڵ�
        }
    }
}

int main()
{
    int n,q,i,j,a,b,temp;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    Time=0;
    dfs(1,0,-1);
    init(Time);

    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        temp=answer(ord[a],ord[b]);
        printf("%d\n",dep[a]+dep[b]-2*temp);
    }
	return 0;
}
