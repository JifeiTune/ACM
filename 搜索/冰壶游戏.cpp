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
从起始到当前坐标已走ans步
本函数目的是从当前点出发寻找道路
当前点在调用本函数之前就已经确定是合法的了 
ac标记是运动还是静止.1表运动 
p标记若为运动，运动方向如何（作为shift数组下标 
*/
bool dfs(int Sx,int Sy,int ans,bool ac,int p)
{
	//dfs，各种坐标特判放在开头统一进行比较方便
	if(!inR(Sx,Sy))
	{
		return 0;
	} 
	int i;
	bool isOk=0;
	if(x[Sx][Sy]==1)
	{
		//静止态走向石头，错 
		return 0;	
	}
	if(x[Sx][Sy]==3)//终点 
	{
		MIN=MIN<=ans?MIN:ans;//更新最小值 
		return 1;
	}
	if(ac)//运动态 
	{
		//下一步会有石头，将停下并改变道路状态
		//不管行不行，最后都应恢复状态，因为题目要求最小，各种情况都应遍历（回溯）
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
	else//静止态 
	{
		//当前已走了10步，无论下一步是否到达终点都超出范围了
		if(ans==10)
		{
			return 0;
		}
		for(i=0;i<4;i++)
		{
			//四种情况有一种可行就OK
			bool t=dfs(Sx+shift[i][0],Sy+shift[i][1],ans+1,1,i);
			isOk=isOk||t;
			//小心，不要写成以下形式，如果isOk已经是1了，dfs就不会执行了！ 
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
			printf("%d\n",MIN);//ans是一个比11小的数 
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0; 
}
