#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
using namespace std;

/*
根据二叉树的前序遍历序列和中序遍历序列建树，并输出其后序序列
中序遍历先输出左子树，再输出根，然后输出右子树
所以中序遍历序列中，根将左右子树分成了2部分
而前序遍历先遍历根，所以根据前序遍历序列可以找出当前遍历到的根
于是可以递归建树
*/

struct Node
{
    char name;
    Node *L,*R;
};

char pre[100001];//前序遍历序列
char mid[100001];//中序遍历序列
int p,len;
Node *root;

Node *build(int L,int R)
{
    if(L>R)
    {
        return NULL;
    }
    int i,part;
    Node *ans=new Node;
    for(i=L;i<=R;i++)
    {
        if(mid[i]==pre[p])//找到分割点
        {
            part=i;
            break;
        }
    }
    ans->name=pre[p];
    ++p;//找到这个根后，下标指向下一个根
    ans->L=build(L,part-1);
    ans->R=build(part+1,R);
    return ans;
}

void beh(Node *n)//后序遍历输出
{
    if(n!=NULL)
    {
        beh(n->L);
        beh(n->R);
        putchar(n->name);
    }
}

int main()
{
    int i,j,k;
    scanf("%s%s",pre,mid);
    len=strlen(pre);
    p=0;//当前前序序列位置，即根的下标
    root=build(0,len-1);
    beh(root);
    return 0;
}
