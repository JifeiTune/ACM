#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

/*
һ����Ϊn���������У�ÿ������Ψһ
ÿ�ζ�λ����ǰ��������ȡ�������Լ���֮�ֱ��������ڵ�k�����������㣬ȫȡ����
ȡ������������һ������ʴ˹��̳�����ȥֱ������Ϊ�գ�ԭ������ÿ�����ֱ�ֵ�����һ������

ȥ���˵ľͲ�����ȡ����������ʽ�ṹ�����������Ը��Ӷ�
�ؼ��ǣ�ÿ��Ҫ������������ô��λ
ԭ������ÿ������Ψһ�����Կ�����multiset����ÿ����������ԭ�����е��±�
��Ҫ����ض�λ���±꣬��STL list��Ȼ�������� 
����дһ�����������е�����L[i]��R[i]�ֱ��ʾ�±�Ϊi��������ߡ��ұߵ������±꣬-1��ʾ������
ÿ��ɾ���󣬽�ʣ�µ�����������������ȻҲ���������Ƿ�Ϊ��
*/

struct Node
{
    int val;
    int pos;
    bool operator<(const Node &r) const
    {
        return val<r.val;
    }
    Node(){}
    Node(int _val,int _pos):val(_val),pos(_pos){}
};

multiset<Node> mt;
int L[200001];
int R[200001];
int val[200001];
int kind[200001];

int main()
{
    ios::sync_with_stdio(false);
    int n,k,i,num=0,now;
    Node nd;
    multiset<Node>::iterator it;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
        L[i]=i-1,R[i]=i+1;
        mt.insert(Node(val[i],i));
    }
    L[1]=-1;
    R[n]=-1;
    while(!mt.empty())
    {
        ++num;
        now=((num&1)?1:2);
        it=mt.end();
        --it;
        nd=(*it);
        mt.erase(it);
        kind[nd.pos]=now;
        int Lp=nd.pos,Rp=nd.pos,temp=k;
        while(temp--)//ɾ���ұߵ�k��
        {
            Rp=R[Rp];
            if(Rp==-1)
            {
                break;
            }
            else
            {
                kind[Rp]=now;
                mt.erase(mt.find(Node(val[Rp],0)));
            }
        }

        temp=k;
        while(temp--)//ɾ����ߵ�k��
        {
            Lp=L[Lp];
            if(Lp==-1)
            {
                break;
            }
            else
            {
                kind[Lp]=now;
                mt.erase(mt.find(Node(val[Lp],0)));
            }
        }
        //����ʣ�µĲ���
        Rp=(Rp==-1?-1:R[Rp]);
        Lp=(Lp==-1?-1:L[Lp]);
        if(Lp!=-1)
        {
            R[Lp]=Rp;
        }
        if(Rp!=-1)
        {
            L[Rp]=Lp;
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d",kind[i]);
    }
    return 0;
}
