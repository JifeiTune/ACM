#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/*
���̳����ΪN
Ϊ'#'��λ�òſɷ�������
�����������Ӳ���ͬ�л�ͬ��
��M(M<=N)�����ӣ��ʷŷ���

�ⷨ����N�ʺ󣬲�֮ͬ������M����С��N
���Զ���ÿ�У��ַ��벻������
*/
char x[101][101];
int H,W,ans;
bool vis[101];//ĳһ���Ƿ񱻷���

void dfs(int c,int num)//��ǰ����c�У���ڷ�num������
{
    if(num==0)//�ɹ����һ�ַ���
    {
        ++ans;
        return;
    }
    if(c>H)
    {
        return;
    }
    int i;
    for(i=1;i<=W;i++)//������òſ�����һ��
    {
        if(x[c][i]=='#'&&(!vis[i]))//i�пɷ���
        {
            vis[i]=1;
            dfs(c+1,num-1);
            vis[i]=0;//�ָ�
        }
    }
    dfs(c+1,num);//���Ա���
}

int main()
{
    int T,i,j,num;
    while(scanf("%d%d",&H,&num))
    {
        if(H==-1)
        {
            break;
        }
        W=H;
        for(i=1;i<=H;i++)
        {
            for(j=1;j<=W;j++)
            {
                scanf(" %c",&x[i][j]);
            }
        }
        memset(vis,0,sizeof(vis));
        ans=0;
        dfs(1,num);
        printf("%d\n",ans);
    }
    return 0;
}
