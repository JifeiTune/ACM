#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<time.h> 
using namespace std;

/*
UVA - 1401
Remember the Word

给定一个长字符串Ls和许多短字符串
将长字符串分成短字符串（可以重复），问有几种分法
设Ls长为len，dp[i]表示第i位到len-1位的分法
将所有短字符串建立Trie树后，i从len-1到0
每次在Trie中遍历i-len-1的子串，每找到一个单词tem
dp[i]+=dp[i+strlen(tem)]，起初dp[len]=1 
*/ 
#define MAXLEN (int)(3e5+1)//单词最大长度 
#define KINDS 26//不同字母个数
#define MOD 20071027 


int Trie[MAXLEN*KINDS][KINDS];//编号为i的节点，第j号子节点编号为k
int val[MAXLEN*KINDS];
int Pnum;//节点数 

char word[300005]; 
char tem[105];
int dp[MAXLEN];
int Slen; 

void insert(char * S,int v)//插入单词S，权值为v，覆盖式插入，若不想覆盖可先判断单词是否已存在 
{
	int i,tem;
	int id=0;//顺着寻找下去的节点编号，起初为根
	for(i=0;S[i]!='\0';i++)
	{
		tem=S[i]-'a';//当前需插入单词的编号 
		if(Trie[id][tem]==0)//原来没有，需要新插入 
		{
			memset(Trie[Pnum],0,sizeof(Trie[Pnum]));
			val[Pnum]=0;//中间节点权值设为无效，这样以后寻找时可以区分是否代表单词末尾 
			Trie[id][tem]=Pnum++;//新增节点
		}
		id=Trie[id][tem];//无论是否新建节点，都应更新 
	}
	val[id]=v;
}

void find(int pos)//从pos往末尾找 
{
	int i,tem;
	int id=0;//顺着寻找下去的节点编号，起初为根
	for(i=pos;i<Slen;i++)
	{
		tem=word[i]-'a';//当前需查找单词的编号 
		if(Trie[id][tem]==0)//找不到 
		{
			return;
		}
		id=Trie[id][tem];
		if(val[id]!=0)//找到单词节点 
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
		Pnum=1;//起初只有根节点 
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


