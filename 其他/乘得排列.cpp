#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<vector> 
using namespace std;

long long x[110005];//每个点伤害 
long long dam[110005];//每个点走到终点伤害 
/*
UVA - 10825
Anagram and Multiplication

m位的n进制数，问是否存在一个数
乘上2-m的到的数都是原数的一个排列
存在则输出

枚举末位（1到n-1），末位与1-m相乘得到的数，它们的排列可能是答案
再将排列枚举一个挨个检查即可
待证明 
*/ 
int m,n;
int P[7];//所有排列
int F[7];//起初排列
int Cal[7];//计算用 

inline bool same()//判断两个排列是由相同起始组成 
{
	sort(Cal+1,Cal+1+m);//开始生成排列
	for(int i=1;i<=m;i++)
	{
		if(Cal[i]!=F[i])
		{
			return 0;//有一个不等就不行 
		}
	}
	return 1;
} 

int main()
{
	int i,j,k1,k2,k3,tem,jw,ys,num;
	bool flag,con;
	while(scanf("%d%d",&m,&n)&&(m!=0||n!=0))
	{
		flag=0;
		for(i=1;i<n;i++)//枚举末位
		{
			for(j=1;j<=m;j++)
			{
				P[j]=(i*j)%n;	
			}
			sort(P+1,P+1+m);//开始生成排列
			memcpy(F,P,sizeof(int)*7);
			con=1;//标记当前排列是否过大 
			do
			{
				num=0;
				//开始计算，若越界，则以后的都不行
				for(k1=2;k1<=m;k1++)
				{
					jw=0;
					for(k2=m;k2>=1;k2--)
					{
						ys=(P[k2]*k1+jw)%n;//余数
						Cal[k2]=ys;
						jw=(P[k2]*k1+jw)/n;//进位
					}
					if(jw>0)
					{
						con=0;//以后的排列都没必要再算
						break;
					}
					else if(same())
					{
						num++;
					}
				}
				if(num==m-1)
				{
					flag=1;
					goto sign;//跳出多重循环，省事…… )	
				}		
			}while(next_permutation(P+1,P+1+m)&&con);	 
		}
		if(flag)
		{
			sign:for(i=1;i<=m;i++)
			{
				printf("%d",P[i]);
				if(i!=m)
				{
					putchar(' ');
				}
			}
			putchar('\n');
		}
		else
		{
			printf("Not found.\n");
		}
	}
	return 0; 
}


