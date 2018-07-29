#include<stdio.h>

int x[21][21],MIN;
int w,h,Sx,Sy;

int shift[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

#define inR(i,j) (i>=1&&i<=h&&j>=1&&j<=w)
/*
POJ 3009
Curling 2.0
*/ 
/*
����ʼ����ǰ��������ans��
������Ŀ���Ǵӵ�ǰ�����Ѱ�ҵ�·
��ǰ���ڵ��ñ�����֮ǰ���Ѿ�ȷ���ǺϷ����� 
ac������˶����Ǿ�ֹ.1���˶� 
p�����Ϊ�˶����˶�������Σ���Ϊshift�����±� 
*/
bool dfs(int Sx,int Sy,int ans,bool ac,int p)
{
	//dfs�������������з��ڿ�ͷͳһ���бȽϷ���
	if(!inR(Sx,Sy))
	{
		return 0;
	} 
	int i;
	bool isOk=0;
	if(x[Sx][Sy]==1)
	{
		//��ֹ̬����ʯͷ���� 
		return 0;	
	}
	if(x[Sx][Sy]==3)//�յ� 
	{
		MIN=MIN<=ans?MIN:ans;//������Сֵ 
		return 1;
	}
	if(ac)//�˶�̬ 
	{
		//��һ������ʯͷ����ͣ�²��ı��·״̬
		//�����в��У����Ӧ�ָ�״̬����Ϊ��ĿҪ����С�����������Ӧ���������ݣ�
		if(!inR(Sx+shift[p][0],Sy+shift[p][1]))
		{
			return 0;
		}
		if( x[ Sx+shift[p][0] ][ Sy+shift[p][1] ]==1 )
		{
			x[ Sx+shift[p][0] ][ Sy+shift[p][1] ]=0;
			isOk=dfs(Sx,Sy,ans,0,-1);
			x[ Sx+shift[p][0] ][ Sy+shift[p][1] ]=1;
			return isOk;
		}
		else
		{
			return dfs(Sx+shift[p][0],Sy+shift[p][1],ans,1,p); 
		}
	}
	else//��ֹ̬ 
	{
		//��ǰ������10����������һ���Ƿ񵽴��յ㶼������Χ��
		if(ans==10)
		{
			return 0;
		}
		for(i=0;i<4;i++)
		{
			//���������һ�ֿ��о�OK
			bool t=dfs(Sx+shift[i][0],Sy+shift[i][1],ans+1,1,i);
			isOk=isOk||t;
			//С�ģ���Ҫд��������ʽ�����isOk�Ѿ���1�ˣ�dfs�Ͳ���ִ���ˣ� 
			//isOk=isOk||dfs(Sx+shift[i][0],Sy+shift[i][1],ans+1,1,i);
		}
		return isOk;
	}
}

int main()
{
	int i,j,tem,k;
	while(scanf("%d%d",&w,&h)&&(w!=0||h!=0))
	{
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				scanf("%d",&tem);
				x[i][j]=tem;
				if(tem==2)
				{
					Sx=i;
					Sy=j;
				}
			}
		}
		MIN=11;
		if(dfs(Sx,Sy,0,0,-1))
		{
			printf("%d\n",MIN);//ans��һ����11С���� 
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0; 
}
