#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<queue> 
/*
HDU - 1728
�����Թ�
*/
using namespace std;

int Sx,Sy,Ex,Ey;
char x[101][101];
int step[101][101][4];//ĳ������ĳ����ʱ��ǰ��С���� 
int m,n,num;//m��n�� 

int shift[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

#define InR(x,y) (x>=1&&x<=m&&y>=1&&y<=n)

bool DFS(int X,int Y,int D,int DIS)//(X,Y)������D���򣬵�ǰ����DIS 
{	
	if(!InR(X,Y))
	{
		return 0;
	}
	if(DIS>num||x[X][Y]=='*')
	{
		return 0;
	}
	if(X==Ex&&Y==Ey)//�ҵ� 
	{
		return 1;
	}
	if(step[X][Y][D]!=-1&&DIS>=step[X][Y][D])
	{
		return 0;//����·û��Ҫ�� 
	}
	
	step[X][Y][D]=DIS;
	
	x[X][Y]='*';
	
	int Nx,Ny,i;
	if(D==0||D==1)//�ϻ��� 
	{
		for(i=2;i<=3;i++)
		{
			if(DFS(X+shift[i][0],Y+shift[i][1],i,DIS+1))
			{
				return 1;
			}
		}
	}
	if(D==2||D==3)//����� 
	{
		for(i=0;i<=1;i++)
		{
			if(DFS(X+shift[i][0],Y+shift[i][1],i,DIS+1))
			{
				return 1;
			}
		}
	} 
	if(DFS(X+shift[D][0],Y+shift[D][1],D,DIS))//���ַ��� 
	{
		return 1;
	}
	x[X][Y]='.';//�ָ�״̬
	return 0;
}
int main()
{
	//freopen("test.txt","r",stdin);  
	//freopen("my.txt","w",stdout);
	int T,i,j,k,ans;
	bool flag;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf(" %c",&x[i][j]);
			}
		}
		scanf("%d%d%d%d%d",&num,&Sy,&Sx,&Ey,&Ex);
		flag=1;
		if(Sx==Ex&&Sy==Ey)
		{
			printf("yes\n");
			continue;
		}
		for(i=0;i<4;i++)
		{
			memset(step,-1,sizeof(step)); 
			if(DFS(Sx+shift[i][0],Sy+shift[i][1],i,0))
			{
				printf("yes\n");
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("no\n");
		}
	}
	return 0; 
}


