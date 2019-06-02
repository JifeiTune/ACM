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
#include<fstream>
#include<algorithm>
using namespace std;

/*
��һ�����޵�ƽ�����кܶ��ϰ���
���С������(0,0)������������
ÿ��Ҫ�����ϰ�����ϰ����ڵ�ǰ����ǰһ������ʱ����ת90��
���������ϰ�������꣬��С����ת���Σ������޴Σ����-1

ģ���⣬ÿ���൱�ڰ�һ�����߳��������������һ���ϰ����ͣ�²�ת��
����������ʱ����ǰ����Ϊ(x,y)�������ҵ�һ��������Ϊy�����������x���ϰ��㣨�Ҳ����ͱ�ʾ�߳�ȥ�ˣ�
���Կ��Զ��ֽ������¼ÿһ���������Ӧ�����������꣬��֮һ������ʵ���Ǽ�¼���к��ߡ����ߣ�
�������־Ϳ����ˣ��ұߵ��ǵ�һ�������������ģ���ߵľ��ǵ�һ�����������С��
�ж���ѭ������ʵ��С���ڶ��Σ�����ͬ�ķ�������ͬһ����ʱ���ͱ�Ȼ�����ѭ��
��set��¼һ�µ�ǰ�������ϰ�״̬��ÿ���ж�һ���Ƿ��ظ����� 
*/ 

struct Node
{
    int H,W;
};

map<int,vector<int> > Hs;//���ŵ�
map<int,vector<int> > Ws;//���ŵ�

struct obs
{
    int H,W,pos;
    obs(){}
    obs(int _H,int _W,int _pos):H(_H),W(_W),pos(_pos){}
    bool operator<(const obs &r) const
    {
        if(H==r.H)
        {
            if(W==r.W)
            {
                return pos<r.pos;
            }
            return W<r.W;
        }
        return H<r.H;
    }
};

set<obs> all;

int isOk(int &nowH,int &nowW,int nowPos)
{
    vector<int>::iterator it;
    if(nowPos==0)//��
    {
        vector<int> &w=Hs[nowH];
        it=upper_bound(w.begin(),w.end(),nowW);
        if(it!=w.end())
        {
            nowW=(*it)-1;
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if(nowPos==1)//��
    {
        vector<int> &h=Ws[nowW];
        it=lower_bound(h.begin(),h.end(),nowH);
        if(it!=h.begin())
        {
            --it;
            nowH=(*it)+1;
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if(nowPos==2)//��
    {
        vector<int> &w=Hs[nowH];
        it=lower_bound(w.begin(),w.end(),nowW);
        if(it!=w.begin())
        {
            --it;
            nowW=(*it)+1;
            return 1;
        }
        else
        {
            return -1;
        }

    }
    else if(nowPos==3)//��
    {
        vector<int> &h=Ws[nowW];
        it=upper_bound(h.begin(),h.end(),nowH);
        if(it!=h.end())
        {
            nowH=(*it)-1;
            return 1;
        }
        else
        {
            return -1;
        }
    }

}

int main()
{
    int n,i,j,temp,last,h,w;
    Node nd;
    while(~scanf("%d",&n))
    {
    	all.clear();
    	Hs.clear();
    	Ws.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&w,&h);
            Hs[h].push_back(w);
            Ws[w].push_back(h);
        }
        for(auto &it:Hs)
        {
            sort(it.second.begin(),it.second.end());
        }
        for(auto &it:Ws)
        {
            sort(it.second.begin(),it.second.end());
        }
        int nowPos=0;
        int nowH=0,nowW=0;
        int num=0;
        obs ob;
        while(1)
        {
            if(isOk(nowH,nowW,nowPos)==-1)//�ܳ�ȥ��
            {
                printf("%d\n",num);
                break;
            }
            else
            {
                ob=obs(nowH,nowW,nowPos);
                if(all.find(ob)!=all.end())
                {
                    printf("-1\n");
                    break;
                }
                else
                {
                    all.insert(ob);
                    nowPos=(nowPos+1)%4;
                    ++num;
                }

            }
        }
    }
	return 0;
}
