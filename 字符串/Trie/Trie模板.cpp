#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<time.h> 
using namespace std;
/*
字典树，莫慌，很简单的
假设字典中单词只由26个小写字母构成
每个节点的子节点最多只可能有26个
为了方便，这棵树就由数组存储，大小开字符串最大长度*26+1 
每个节点都有编号，编号即数组下标
编号为0是根节点，单词信息是存在边上的
用Trie[i][j]=k表示编号为i的节点，第j号子节点编号为k
节点编号是随机的，根据读入顺序 
这个第j号就对应一个字母（将字母按字典序从0开始编号）
如j=0，表示有字母a，也就是i->j这条边字母为a
当然，若不存在某个编号的子节点，设Trie[i][x]=0即可，因为没有任何一个节点的子节点会是根节点
从根节点开始往下找即可查询单词
有时对每个单词需要有一个权值，使用val[i]记录从根节点到i节点这个单词的权值即可
对于无效的节点统一设为一个不可能的权值即可 

数组会很大，所以程序中只有在用上了某个节点时才memset
垃圾数据没关系的，因为每当首次用到一个节点就会先将其子节点置为0（根节点必然用到） 
插入时反正都是当为0时断定无子节点
而查找时，从根节点开始，找到的节点之前必然已经插入过，也就是清空过垃圾数据了 
只要Trie中找到了，val值才视为有效，其他垃圾数据也忽略

虽说各教程都说边代表字母，实际上将点看做字母更好理解（边的远离根的那个端点） 
*/ 

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


