#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<time.h> 
using namespace std;
#define MAXLEN (int)(1e5+1)//单词最大长度 
#define KINDS 26//不同字母个数

int Trie[MAXLEN*KINDS][KINDS];//编号为i的节点，第j号子节点编号为k
int val[MAXLEN*KINDS];
int Pnum;//节点数 

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

int find(char * S)//查找S，找到则返回节点编号，否则返回-1 
{
	int i,tem;
	int id=0;//顺着寻找下去的节点编号，起初为根
	for(i=0;S[i]!='\0';i++)
	{
		tem=S[i]-'a';//当前需查找单词的编号 
		if(Trie[id][tem]==0)//找不到 
		{
			return -1;
		}
		id=Trie[id][tem];//放心，Trie[id][tem]一定不会是垃圾数据因为id之前插入时memset过，非零数据必然有效 
	}
	if(val[id]!=0)
	{
		return id;//确保是单词节点而不是中间节点 
	}
	else
	{
		return -1;
	}
}

int main()
{
	Pnum=1;//起初只有根节点 
	memset(Trie[0],0,sizeof(Trie[0]));
	
	
	return 0; 
}


