#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<map> 
#include<queue> 
/*
AOJ 0121
Seven Puzzle 
*/
using namespace std;

#define isOk(x) (x>=0&&x<=7)

map<string,int> dp;

int shift[4]={-4,4,-1,1};//��������ƫ�� 

void bfs()
{
	dp["01234567"]=0;
	queue< pair<string,int> > q;//״̬��0��λ�� 
	string oldS,newS;
	int oldP,newP,i;
	q.push(make_pair("01234567",0));
	while(!q.empty())
	{
		oldS=q.front().first;
		oldP=q.front().second;
		q.pop();
		for(i=0;i<4;i++)
		{
			newP=oldP+shift[i];
			if(isOk(newP) && !(oldP==3&&newP==4) && !(oldP==4&&newP==3))//�˴�ǧ�������紦�ǲ���ת�Ƶ� 
			{
				newS=oldS;
				swap(newS[oldP],newS[newP]);//״̬ת��
				if(dp.find(newS)==dp.end())//��δ����map 
				{
					dp[newS]=dp[oldS]+1;
					//cout<<newS<<' '<<dp[newS]<<' '<<newP<<endl;
					q.push(make_pair(newS,newP)); 
				} 
			}
		}
	} 
} 

int main()
{
	//freopen("out.txt","w",stdout); 
	bfs();
	string s="01234567";
	int i;
	char c;
	while(~scanf(" %c",&c))
	{
		s[0]=c;
		for(i=1;i<=7;i++)
		{
			scanf(" %c",&s[i]);
		}
		cout<<dp[s]<<'\n';
	}
	return 0; 
}


