#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<set> 
/*
mutiset�����ظ�Ԫ�أ�ɾ��ʱʹ��M.erase(M.find(x))����ʽ�������x��Ԫ��ȫ����ɾ�� 
set������ 
���߶�֧�ָ�Ч����ɾ�飨�������������������ƣ�

����ͼ�ͻᷢ�� 
���佻�����ҵ���˵�L��������Ҷ˵�R������Ϊ[L,R]��L>R��ʾ����Ϊ�ռ�
���ν������µ��ϱ�������TT�����ϵ��±�������BB�����ҵ���ߺ�����LL��������ұߺ�����RR
ֻ�е�TT>=BB&&RR>=LLʱ�н���
����������һ�㣬�õ���n-1�����εĽ����ڣ�ö��ɾ�����Σ��ҵ�һ������ļ��� 
*/
using namespace std;

struct Node
{
	int X1,Y1,X2,Y2;
}x[132675];

int main()
{
	int n,i,ans,X1,Y1,X2,Y2,TT,BB,LL,RR;
	multiset<int> T,B,L,R;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x[i].X1,&x[i].Y1,&x[i].X2,&x[i].Y2);
		T.insert(x[i].Y2);
		B.insert(x[i].Y1);
		L.insert(x[i].X1);
		R.insert(x[i].X2);
		T.size();
	}
	for(i=1;i<=n;i++)//ö��ɾ���� 
	{
		T.erase(T.find(x[i].Y2));
		B.erase(B.find(x[i].Y1));
		L.erase(L.find(x[i].X1));
		R.erase(R.find(x[i].X2));
		TT=*(T.begin());
		T.size();
		BB=*(B.rbegin());
		LL=*(L.rbegin());
		RR=*(R.begin());
		if(TT>=BB&&RR>=LL)
		{
			printf("%d %d",LL,TT);//���Ͻ�
			//printf("%d %d %d %d\n",TT,BB,LL,RR);
			break; 
		}
		T.insert(x[i].Y2);
		B.insert(x[i].Y1);
		L.insert(x[i].X1);
		R.insert(x[i].X2);
	}
	return 0; 
}


