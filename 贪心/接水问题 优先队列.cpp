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
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;

/*
n���˽�ˮ��ֻ��m��ˮ��ͷ
n���˵�˳���ˮ˳��һ�������������m����ͬʱ��ʼ
ֻҪ��һ���˽�ˮ��ɣ�������˿���˲���ȥ��ˮ�����ܵĽ�ˮʱ��

��Ȼ��ÿ�ΰ��ź�����˵����Ƚ�����ˮ��������ˮ��ͷ
��ô�������Ƚ�����ˮ�أ�
��ÿ���˶���һ������ʱ�伴��
����ʱ�䣨��ǰʱ��+����ʱ�䣩������������ȶ���
ÿ��ȡ��ͷ�����������ʱ��Ϊ��ǰʱ��
����������������ֵ��Ϊ�� 
*/

int main()
{
    ios::sync_with_stdio(false);
    int T,n,m,i,MAX,temp,fr;
    cin>>n>>m;
    if(m>=n)
    {
        MAX=0;
        while(m--)
        {
            cin>>temp;
            MAX=max(MAX,temp);
        }
        cout<<MAX;
    }
    else
    {
        T=0;//��ǰʱ��
        for(i=1;i<=m;i++)
        {
            cin>>temp;
            pq.push(temp);//�������ʱ��
        }
        for(i=1;i<=n-m;i++)//��һ����һ��
        {
            cin>>temp;
            fr=pq.top();
            pq.pop();
            T=fr;//��ǰʱ��Ϊ����Ľ���ʱ��
            pq.push(T+temp);
        }
        while(!pq.empty())
        {
            T=pq.top();
            pq.pop();
        }
        cout<<T;
    }
    return 0;
}

