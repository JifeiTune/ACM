#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<list>
#include<set>

using namespace std;
/*
2018�ٶ�֮�ǳ���A 1002
�������У���Ҫ֧��˫�˲��룬˫�˷��ʺ�����
list���Դ����Ӻ���splice�����Խ�b����a������λ�ã�����b���
*/ 
list<int> ls[150001];

int main()
{
	int N,Q,i,j,k,ans,op,a,b,c;
	while(~scanf("%d%d",&N,&Q))
	{
		while(Q--)
		{
			scanf("%d",&op);
			if(op==1)//��Ԫ�� 
			{
				scanf("%d%d%d",&a,&b,&c);
				if(b==0)//��ǰ�� 
				{
					ls[a].push_front(c);
				}
				else//�Ӻ��� 
				{
					ls[a].push_back(c);
				}
			}
			else if(op==2)//ѯ��Ԫ�ز�ɾ�� 
			{
				scanf("%d%d",&a,&b);
				if(ls[a].empty())
				{
					printf("-1\n");
				}
				else
				{
					if(b==0)//��ǰ�� 
					{
						printf("%d\n",ls[a].front());
						ls[a].pop_front();
					}
					else//�ʺ��� 
					{
						printf("%d\n",ls[a].back());
						ls[a].pop_back();
					}
				}
			}
			else//���Ӳ���� 
			{
				scanf("%d%d%d",&a,&b,&c);
				if(c==1)//����� 
				{
					ls[b].reverse();
				}
				ls[a].splice(ls[a].end(),ls[b],ls[b].begin(),ls[b].end());
			}
		}
		for(i=1;i<=N;i++)
		{
			ls[i].clear();
		}
	}
	return 0; 
}


