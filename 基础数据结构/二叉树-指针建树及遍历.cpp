#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<list>
#include<cmath>
#include<stack>

using namespace std;

/*
����һ����չ����������ͨ�ڵ�Ϊ��ĸ���սڵ�Ϊ.����ǰ�����
���������ͺ������

ͨ�����������ǰ��������߱����߽������������������ 
*/ 

struct Node//�ڵ� 
{
    char n;
    Node *c1,*c2;//ָ��2���ӽڵ� 
};

char x[100001];
int len,p;

Node *build()//��һ���ڵ㣬���ؽڵ�ָ�� 
{
    if(x[p]=='.')
    {
        ++p;
        return NULL; 
    }
    Node * ans=new Node;
    ans->n=x[p];
    ++p;
    ans->c1=build();
    ans->c2=build();//ע����2����ֵ
    return ans;
}

void pre(Node *n)
{
    if(n!=NULL)
    {
        cout<<n->n;
        pre(n->c1);
        pre(n->c2);
    }
}

void mid(Node *n)
{
    if(n!=NULL)
    {
        mid(n->c1);
        cout<<(n->n);
        mid(n->c2);
    }
}

void beh(Node *n)
{
    if(n!=NULL)
    {
        beh(n->c1);
        beh(n->c2);
        cout<<(n->n);
    }
}

int main()
{
    cin>>x;
    Node *root;
    p=0;
    root=build();
    mid(root);
    cout<<'\n';
    beh(root);
    return 0;
}
