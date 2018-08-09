#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<vector> 
using namespace std;

long long x[110005];//ÿ�����˺� 
long long dam[110005];//ÿ�����ߵ��յ��˺� 
/*
UVA - 10825
Anagram and Multiplication

mλ��n�����������Ƿ����һ����
����2-m�ĵ���������ԭ����һ������
���������

ö��ĩλ��1��n-1����ĩλ��1-m��˵õ����������ǵ����п����Ǵ�
�ٽ�����ö��һ��������鼴��
��֤�� 
*/ 
int m,n;
int P[7];//��������
int F[7];//�������
int Cal[7];//������ 

inline bool same()//�ж���������������ͬ��ʼ��� 
{
	sort(Cal+1,Cal+1+m);//��ʼ��������
	for(int i=1;i<=m;i++)
	{
		if(Cal[i]!=F[i])
		{
			return 0;//��һ�����ȾͲ��� 
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
		for(i=1;i<n;i++)//ö��ĩλ
		{
			for(j=1;j<=m;j++)
			{
				P[j]=(i*j)%n;	
			}
			sort(P+1,P+1+m);//��ʼ��������
			memcpy(F,P,sizeof(int)*7);
			con=1;//��ǵ�ǰ�����Ƿ���� 
			do
			{
				num=0;
				//��ʼ���㣬��Խ�磬���Ժ�Ķ�����
				for(k1=2;k1<=m;k1++)
				{
					jw=0;
					for(k2=m;k2>=1;k2--)
					{
						ys=(P[k2]*k1+jw)%n;//����
						Cal[k2]=ys;
						jw=(P[k2]*k1+jw)/n;//��λ
					}
					if(jw>0)
					{
						con=0;//�Ժ�����ж�û��Ҫ����
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
					goto sign;//��������ѭ����ʡ�¡��� )	
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


