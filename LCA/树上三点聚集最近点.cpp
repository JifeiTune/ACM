#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

/*
�����ϸ���3��
���ҳ�1�㣬ʹ��3�㵽�õ����֮����С
����õ�;����

�����������֣���Ҫ�ҵĵ��ǣ�������LCA����������Ǹ�LCA����
�����ÿ�ʱ�䣬��������������ҲŹ�����
*/

#define MAXN 500001
#define EXP 21//��С��log2(MAXN)

vector<int> Tree[MAXN];
int dep[MAXN];//������
int up[MAXN][EXP];//up[i][j]��ʾi�������������2^j�����ĵ㣬0�ͱ�ʾû��
int D=0;

void dfs(int n,int fa)//��ǰ�ڵ㣬��ǰ�ڵ㸸�ڵ�
{
    int len=Tree[n].size(),i,j,to;
    //�������˵�ǰ�ڵ㣬�ͱ�ʾ�Ѿ��������˸����õ�·���ϵĵ㣬���Կ���ֱ�Ӹ��µ�ǰ���up
    for(j=1;(1<<j)<=dep[n];j++)//��������ȡ���������
    {
        //��ǰ����2^j��������2^(j-1)������2^(j-1)
        up[n][j]=up[up[n][j-1]][j-1];
    }

    for(i=0;i<len;i++)
    {
        to=Tree[n][i];
        if(to!=fa)//���ѻ�ȥ��
        {
            dep[to]=dep[n]+1;
            D=D>dep[to]?D:dep[to];
			up[to][0]=n;//�ȸ�����Ⱥ;��룬�Լ�up�߽�
            dfs(to,n);
        }
    }
}

int LCA(int a,int b)//��a��b�������������
{
    int h,i,j;
    h=dep[a]-dep[b];//Ϊ����a��b����ͬһ�����Ҫ��Ծ�ĵ�
    if(dep[a]<dep[b])
    {
        swap(a,b);//��aΪ��ȸ���ĵ�
        h=-h;
    }
    i=0;
    while(h>0)//h�Ķ�������Ϊ1��λȨ����Ҫ��Ծ��
    {
        if(h&1)
        {
            a=up[a][i];//��ǰλȨΪ2^i
        }
		++i;
		h>>=1;//����1λ
    }
    if(a==b)
    {
        return a;//�Ѿ�Ϊͬһ���ˣ�˵��2��ԭ����ͬһ����������·����
    }
    /*
    ��ʱ˵��ԭ��2���ڲ�ͬ�ĸ�������·���ϣ�һ������������������ͬһ�㼴ΪLCA
    ���ǲ�֪����Ҫ���������٣�����ֻ��̰�ĵع������������Ķ�������
    �Ӹ�λ��ʼ���ԣ��������λȨ���ò��������ͬ������
    */
    for(j=D;j>=0;j--)
    {
        if(up[a][j]!=up[b][j])//���Ⱦ���
        {
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];//����һ��
}

inline void in(int &ret)
{
	char c;
	int sgn;
	c=getchar();
	while((c<'0'||c>'9')) c=getchar();
	ret=c-'0';
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
}

inline void out(int x)
{
	if(x>9) out(x/10);
	putchar(x%10+'0');
}

int main()
{

    int n,q,a,b,c,i,j,temp,ans,MAX=0,ab,ac,bc;
    scanf("%d%d",&n,&q);
    for(i=1;i<n;i++)
    {
        in(a),in(b);
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    dep[1]=0;
    dfs(1,-1);//������1Ϊ��
    D=log2(D)+1;
    while(q--)
    {
        in(a),in(b),in(c);
        ab=LCA(a,b);
        ac=LCA(a,c);
        bc=LCA(b,c);
        temp=ab;
        MAX=dep[ab];
        if(dep[ab]<dep[ac])
        {
            temp=ac;
            MAX=dep[ac];
        }
        if(dep[bc]>MAX)
        {
            temp=bc;
        }
        out(temp),putchar(' ');
        out(dep[a]+dep[b]+dep[c]-dep[ab]-dep[ac]-dep[bc]);
        putchar('\n');
    }
    return 0;
}
