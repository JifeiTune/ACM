#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<time.h> 
using namespace std;
#define MAXLEN (int)(1e5+1)//������󳤶� 
#define KINDS 26//��ͬ��ĸ����

int Trie[MAXLEN*KINDS][KINDS];//���Ϊi�Ľڵ㣬��j���ӽڵ���Ϊk
int val[MAXLEN*KINDS];
int Pnum;//�ڵ��� 

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

int find(char * S)//����S���ҵ��򷵻ؽڵ��ţ����򷵻�-1 
{
	int i,tem;
	int id=0;//˳��Ѱ����ȥ�Ľڵ��ţ����Ϊ��
	for(i=0;S[i]!='\0';i++)
	{
		tem=S[i]-'a';//��ǰ����ҵ��ʵı�� 
		if(Trie[id][tem]==0)//�Ҳ��� 
		{
			return -1;
		}
		id=Trie[id][tem];//���ģ�Trie[id][tem]һ������������������Ϊid֮ǰ����ʱmemset�����������ݱ�Ȼ��Ч 
	}
	if(val[id]!=0)
	{
		return id;//ȷ���ǵ��ʽڵ�������м�ڵ� 
	}
	else
	{
		return -1;
	}
}

int main()
{
	Pnum=1;//���ֻ�и��ڵ� 
	memset(Trie[0],0,sizeof(Trie[0]));
	
	
	return 0; 
}


