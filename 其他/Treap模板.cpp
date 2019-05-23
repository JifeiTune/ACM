#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<list>
#include<cstdlib>
using namespace std;

/*
֧���ظ����� 
֧�ֲ��롢ɾ������ĳ����Ϊ�ڼ�����ڼ����Ϊ�Ǹ�������ÿ������ǰ�����
�����������Ϊ���������� 
��ĳ����Ϊ�ڼ���ʱ�����ǵ�������һ�γ��ֵ�λ�� 
*/

#define MAXN 100005
#define INF 1e9

struct Node
{
	Node* ch[2];
	int key,fix,size,cnt;
	void maintain()
	{
		size=ch[0]->size + ch[1]->size + cnt;
	}
};

typedef Node* P_node;

int Max(int x,int y)
{
	return x>y?x:y;
}

int Min(int x,int y)
{
	return x<y?x:y;
}

struct Treap
{
	Node base[MAXN],nil;
	P_node root,null,len;
	int num;//��ǰ�ڵ���
	int Kind;//��ǰ�ڵ�ֵ����������ȥ�غ�ĸ��� 
	Treap()
	{
		root=null=&nil;
		null->key=null->fix=INF;
		null->size=null->cnt=0;
		null->ch[0]=null->ch[1]=null;
		len=base;
		num=0,Kind=0;
	}

	P_node newnode(int tkey)
	{
		len->key=tkey;
		len->fix=rand();
		len->ch[0]=len->ch[1]=null;
		len->size=len->cnt=1;
		return len++;
	}

	void rot(P_node &p,int d)
	{
		P_node k=p->ch[d^1];
		p->ch[d^1]=k->ch[d];
		k->ch[d]=p;
		p->maintain();
		k->maintain();
		p=k;
	}

	void _Insert(P_node &p,int tkey)
	{
		if(p==null)
		{
			p=newnode(tkey);
			++Kind;
		} 
		else if(p->key==tkey) p->cnt++;
		else
		{
			int d=tkey>p->key;
			_Insert(p->ch[d],tkey);
			if(p->ch[d]->fix > p->fix) rot(p,d^1);
		}
		p->maintain();
	}

	void _Erase(P_node &p,int tkey)
	{
		if(p->key==tkey)
		{
			if(p->cnt>1) p->cnt--;
			else if(p->ch[0]==null) p=p->ch[1],--Kind;
			else if(p->ch[1]==null) p=p->ch[0],--Kind;
			else
			{
				int d=p->ch[0]->fix > p->ch[1]->fix;
				rot(p,d);
				_Erase(p->ch[d],tkey);
			}
		}
		else _Erase(p->ch[tkey>p->key],tkey);
		p->maintain();
	}

	int _Kth(P_node p,int k)
	{
		if(p==null||k<1||k>p->size) return INF;
		if(k<p->ch[0]->size+1) return _Kth(p->ch[0],k);
		if(k>p->ch[0]->size+p->cnt) return _Kth(p->ch[1],k-p->ch[0]->size-p->cnt);
		return p->key;
	}

	int _Rank(P_node p,int tkey,int res)
	{
		if(p->key==tkey) return p->ch[0]->size+res+1;
		if(tkey<p->key) return _Rank(p->ch[0],tkey,res);
		return _Rank(p->ch[1],tkey,res+ p->ch[0]->size + p->cnt);
	}

	int _Pred(P_node p,int tkey)
	{
		if(p==null) return -INF;
		if(tkey<=p->key) return _Pred(p->ch[0],tkey);
		return Max(p->key,_Pred(p->ch[1],tkey));
	}

	int _Succ(P_node p,int tkey)
	{
		if(p==null) return INF;
		if(tkey>=p->key) return _Succ(p->ch[1],tkey);
		return Min(p->key,_Succ(p->ch[0],tkey));
	}

	void _Print(P_node p)
	{
		if(p==null) return;
		_Print(p->ch[0]);
		for(int i=1; i<=p->cnt; i++) printf("%d ",p->key);
		_Print(p->ch[1]);
	}

	int Count(int tkey)//��ѯĳ�����ĳ��ִ������������ж��Ƿ���� 
	{
	    P_node now=root;
        while(now!=null)
        {
            if(tkey==now->key)
            {
                return now->cnt;
            }
            else if(tkey<now->key)
            {
                now=now->ch[0];
            }
            else
            {
                now=now->ch[1];
            }
        }
        return 0;
	}

	void Insert(int tkey)
	{
	    ++num;
		_Insert(root,tkey);
	}

	void Erase(int tkey)
	{
	    --num;
		_Erase(root,tkey);
	}

	int Kth(int k)//���K�󣬲������򷵻�INF 
	{
		return _Kth(root,k);
	}

	int Rank(int tkey)//��ĳ�����ڼ���
	{
		return _Rank(root,tkey,0);
	}

	int Pred(int tkey)//��ǰ���������ڷ���-INF
	{
		return _Pred(root,tkey);
	}

	int Succ(int tkey)//���̣������ڷ���INF
	{
		return _Succ(root,tkey);
	}

	void Print()
	{
		_Print(root);
		printf("\n");
	}
} Tree;

int main()
{
    int num,op,n;
	scanf("%d",&num);
	while(num--)
    {
        scanf("%d%d",&op,&n);
        switch(op)
        {
        case 1:
            {
                Tree.Insert(n);
                break;
            }
        case 2:
            {
                Tree.Erase(n);
                break;
            }
        case 3:
            {
                printf("%d\n",Tree.Rank(n));
                break;
            }
        case 4:
            {
                printf("%d\n",Tree.Kth(n));
                break;
            }
        case 5:
            {
                printf("%d\n",Tree.Pred(n));
                break;
            }
        case 6:
            {
                printf("%d\n",Tree.Succ(n));
                break;
            }
        case 7:
            {
                printf("%d\n",Tree.Count(n));
                break;
            }
        case 8:
            {
                printf("%d\n",Tree.Kind);
                break;
            }
        }
    }
	return 0;
}

