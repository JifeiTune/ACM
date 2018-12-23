#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<list>

using namespace std;
/*
UVA 1665
����ʲô����ͨ�飬һ��ʼ��֪��ʲô��˼
���Ǿ�������������Ϊ��ͨ������ƽ��������

����һ�������ڸ���һϵ�е�������x[]
ÿ����������д��ڵ���x[i]���������ͨ���м���

�ò��鼯�������ˣ�������ô��һ������hash��һ�����أ�
�����ά�����һά��ʾ��֪����
*/

struct Node
{
    int i,j,len;
    Node(){}
    Node(int _i,int _j,int _len):i(_i),j(_j),len(_len){}
    bool operator<(const Node&r) const
    {
        return len>r.len;//�Ӵ�С����
    }
};

int shift[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int H,W;
int x[1002][1002];//ÿ�������Ȩֵ
vector<int> vec;//��������
vector<Node> nodes;
vector<int> all; 
int bcj[1100000];//hash���������ͨ���

#define INR(i,j) (j>=1&&j<=W&&i>=1&&i<=H)
#define hash(i,j) (j+(i-1)*W)

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        bcj[i]=i;
    }
}

int find(int n)
{
    return bcj[n]==n?n:(bcj[n]=find(bcj[n]));
}

int main()
{
    vec.reserve(100001);
    nodes.reserve(1100000);
    all.reserve(100001);
	int i,j,k,a,b,ans,T,len,tem,Nx,Ny,f1,f2,t1;
	scanf("%d",&T);
	while(T--)
    {
        scanf("%d%d",&H,&W);
        nodes.clear();
        for(i=1;i<=H;i++)
        {
            for(j=1;j<=W;j++)
            {
                scanf("%d",&x[i][j]);
                nodes.push_back(Node(i,j,x[i][j]));
            }
        }
        sort(nodes.begin(),nodes.end());//�ź���
        init(H*W);

        scanf("%d",&len);
        vec.clear();
        for(i=1;i<=len;i++)
        {
            scanf("%d",&tem);
            vec.push_back(tem);
        }
        j=0;
        ans=0;
        all.clear(); 
        for(i=len-1;i>=0;i--)
        {
            for(;j<nodes.size()&&nodes[j].len>vec[i];j++)//�ɱ������
            {
                tem=0;
                for(k=0;k<4;k++)//�ж���Χ4�����ͨ��
                {
                    Nx=nodes[j].i+shift[k][0];
                    Ny=nodes[j].j+shift[k][1];
                    if(INR(Nx,Ny))
                    {
                        if(x[Nx][Ny]>vec[i])
                        {
                            f1=find(hash(nodes[j].i,nodes[j].j));
                            f2=find(hash(Nx,Ny));
                            if(f2!=f1)
                            {
                                tem++;
                                bcj[f2]=f1;
                            }
                        }
                    }
                }
                ans-=tem-1;
            }
            all.push_back(ans);
        }
        //printf("%d",all[all.size()-1]);
        for(i=all.size()-1;i>=0;i--)
        {
        	printf("%d ",all[i]);
		}
		putchar('\n');
    }
}

