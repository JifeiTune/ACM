#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<map>
/*
n��������������ӶΣ�����˵㣩���Ӷ��ڲ�ͬ���ָ���������k
����㿪ʼ��Ȼ��ÿ���������䣬������������������ʱ����˵��������������� 
ԭ����ͽг�ȡ������������ 

����map����ʵ��hash�������� 
*/
using namespace std;

int x[500001];
map<int,int> mp;//ĳ�����ֵ�ǰȡ������ 

int main()
{
	int n,k,L,R,i,j,num,ansL,ansR;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	ansL=1,ansR=1;
	L=1;
	num=0;//��ǰ��ͬԪ�ظ��� 
	for(i=1;i<=n;i++)//�Ҷ˵��ƶ� 
	{
		if(mp.find(x[i])==mp.end())//û�ҵ�������� 
		{
			if(num==k)//��ǰ�Ѿ�װ�����ˣ���Ҫ���� 
			{
				if(R-L>ansR-ansL)//��������� 
				{
					ansL=L,ansR=R;
				}
				R=i;
				for(j=L;j<R;j++)
				{
					mp[x[j]]--;
					if(mp[x[j]]==0)//�ɹ�ɾ��һ�� 
					{
						mp.erase(x[j]);
						L=j+1;
						break;
					}
				}
				mp[x[i]]=1;//�����µ�
				
			}
			else//װ���� 
			{
				mp[x[i]]=1;
				num++;
				R=i; 
			}
		}
		else
		{
			mp[x[i]]++;//������1
			R=i; 
		}
	}
	if(R-L>ansR-ansL)
	{
		ansL=L,ansR=R;
	}
	printf("%d %d\n",ansL,ansR); 
	return 0; 
}









