#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<queue>
using namespace std;

/*
有一棵满二叉树，每个节点有一个方向标志，起初为左
从根节点不断落下小球，若当前节点为左，则都左子树，并将标志改为右
反之走右子树，并将标志改为左
现在给定数的深度，和下落的小球编号，问最终下落至的叶节点编号

对每个节点而言，若当前下落的小球是第奇数个，则走左，否则走右
所以根据小球编号模拟一遍即可，记录当前节点，当前小球是第几个到达的
*/

int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,len,n,dep,num,last;
    cin>>dep>>num;//num表示当前是第几次走到当前节点的
    last=1;//当前节点
    for(i=1;i<dep;i++)
    {
        if(num%2)//奇数次，往左走
        {
            last=2*last;//走左子树
            num=(num+1)/2;
        }
        else
        {
            last=2*last+1;//偶数次，往右走
            num/=2;
        }
    }
    cout<<last;
    return 0;
}
