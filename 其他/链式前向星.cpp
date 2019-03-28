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

using namespace std;

/*
��ʽǰ���Ǿ����ڽӱ��һ��ʵ��
��ͼ���ڽӾ�������ˣ�vectorʵ���ڽӱ���Ȼ�ܷ��㣬����Ϊ���Ȳ�֪��ĳ������ߵ�����
�ڹ����п��ܻ᲻�����������ڴ渴�����ݣ����������ʵ��ʹ�ô�

��û��ʲô����û�пռ��ʱ���˷ѵ����ݽṹ����ͼ�أ�
���������뵽�ñ߼����飬������Ŀ���ݷ�Χ�����Ͳ�����ʱ��Ϳռ���˷�
���Ǳ߼������У������ҵģ�������ʹ�õ�ʱ�򾭳�����Ҫ������ĳ��Ϊ�������б�
���������֪��ĳ������ĵ�һ���ߣ�ͨ������������֪����һ���ߡ���������ĳ������ıߵ���ʽ��ϵ�����ܷܺ���ر�����
��head[n]Ϊ��nΪ���ģ���һ���ߵ��±꣨���ޣ���Ϊ-1��
ÿ������һ��next������ָ��ͬ�������һ���ߵ��±꣨���ޣ���Ϊ-1��
����ͼ����ô����֪���ˣ�����ν�ͼ�أ�
����head��Ԫ�ص�ȻҪ��Ϊ-1����Ϊ���ڻ�û�б�
�����һ����ʱ�������ߵ�nextָ����һ���ߵ��±꣬�������head�ͻ����µ������ߵ��±�
����ͼʱʱ����ģ�����ӵĿ�����ͷ���ȱ���

��ʵhead���൱�������ͷָ�룬nextҲ����˼�壬-1�൱��NULL
*/

struct Edge
{
    int to,dis;
    //�������ͨ�ߣ������һ������next����ʾͬ�����һ���ߵ��±꣬����Ϊ-1
    int next;
};

#define MAXN 10000//������ 
#define MAXM 100000//������
int Enum;//�ߵ���Ŀ
Edge G[MAXM+1];//��������
int head[MAXN+1];//�������� 

inline void addE(int from,int to,int dis)
{
    ++Enum;
    G[Enum].to=to;
    G[Enum].dis=dis;

    G[Enum].next=head[from];//ָ����һ����ӵı�
    head[from]=Enum;//������ʼ��
}

int main()
{
    //��ʼ��
    Enum=0;
    memset(head,-1,sizeof(head));
    int i,j;

    addE(1,2,10);
    addE(1,3,20);
    addE(2,5,30);
    addE(3,10,40);
    addE(10,10,100);
    for(i=1;i<=10;i++)
    {
        for(j=head[i];j!=-1;j=G[j].next)//����ʵ�߿�ʼ��������һ���ߣ�ֱ��-1���ޱ�
        {
            cout<<i<<' '<<G[j].to<<' '<<G[j].dis<<'\n';
        }
    }
    return 0;
}
