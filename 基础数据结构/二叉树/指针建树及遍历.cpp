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
输入一棵扩展二叉树（普通节点为字母，空节点为.）的前序遍历
输出其中序和后序遍历

通过对输入进行前序遍历，边遍历边建树，最后遍历输出即可 
*/ 

struct Node//节点 
{
    char n;
    Node *c1,*c2;//指向2个子节点 
};

char x[100001];
int len,p;

Node *build()//建一个节点，返回节点指针 
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
    ans->c2=build();//注意这2个赋值
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
