#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<time.h> 
using namespace std;

/*
UVA - 1401
Remember the Word

����һ�����ַ���Ls�������ַ���
�����ַ����ֳɶ��ַ����������ظ��������м��ַַ�
��Ls��Ϊlen��dp[i]��ʾ��iλ��len-1λ�ķַ�
�����ж��ַ�������Trie����i��len-1��0
ÿ����Trie�б���i-len-1���Ӵ���ÿ�ҵ�һ������tem
dp[i]+=dp[i+strlen(tem)]�����dp[len]=1 
*/ 
#define MAXLEN (int)(3e5+1)//������󳤶� 
#define KINDS 26//��ͬ��ĸ����
#define MOD 20071027 


int Trie[MAXLEN*KINDS][KINDS];//���Ϊi�Ľڵ㣬��j���ӽڵ���Ϊk
int val[MAXLEN*KINDS];
int Pnum;//�ڵ��� 

char word[300005]; 
char tem[105];
int dp[MAXLEN];
int Slen; 

void insert(char * S,int v)//���뵥��S��ȨֵΪv������ʽ���룬�����븲�ǿ����жϵ����Ƿ��Ѵ��� 
{
	int i,tem;
	int id=0;//˳��Ѱ����ȥ�Ľڵ��ţ����Ϊ��
	for(i=0;S[i]!='\0';i++)
	{
		tem=S[i]-'a';//��ǰ����뵥�ʵı�� 
		if(Trie[id][tem]==0)//ԭ��û�У���Ҫ�²��� 
		{
			memset(Trie[Pnum],0,sizeof(Trie[Pnum]));
			val[Pnum]=0;//�м�ڵ�Ȩֵ��Ϊ��Ч�������Ժ�Ѱ��ʱ���������Ƿ������ĩβ 
			Trie[id][tem]=Pnum++;//�����ڵ�
		}
		id=Trie[id][tem];//�����Ƿ��½��ڵ㣬��Ӧ���� 
	}
	val[id]=v;
}

void find(int pos)//��pos��ĩβ�� 
{
	int i,tem;
	int id=0;//˳��Ѱ����ȥ�Ľڵ��ţ����Ϊ��
	for(i=pos;i<Slen;i++)
	{
		tem=word[i]-'a';//��ǰ����ҵ��ʵı�� 
		if(Trie[id][tem]==0)//�Ҳ��� 
		{
			return;
		}
		id=Trie[id][tem];
		if(val[id]!=0)//�ҵ����ʽڵ� 
		{
			dp[pos]=(dp[pos]+dp[i+1])%MOD;
		}
	}
}

int main()
{	
	int i,j,num,cas=1;
	while(~scanf("%s",word))
	{
		Pnum=1;//���ֻ�и��ڵ� 
		memset(Trie[0],0,sizeof(Trie[0]));
		Slen=strlen(word);
		memset(dp,0,sizeof(dp));
		dp[Slen]=1;
		scanf("%d",&num);
		while(num--)
		{
			scanf("%s",tem);
			insert(tem,1);
		}
		for(i=Slen-1;i>=0;i--)
		{
			find(i);
		}
		printf("Case %d: %d\n",cas++,dp[0]);
	}
	return 0; 
}


