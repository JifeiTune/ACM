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
在一个无限的平面上有很多障碍点
起初小明处于(0,0)，并且向右走
每当要碰到障碍物，即障碍物在当前方向前一个格子时，右转90度
给出所有障碍物的坐标，问小明会转几次，若无限次，输出-1

模拟题，每次相当于按一条射线出发，到达最近的一个障碍点后停下并转向
例如向右走时，当前坐标为(x,y)，就是找第一个纵坐标为y，横坐标大于x的障碍点（找不到就表示走出去了）
所以可以二分解决，记录每一个横坐标对应的所有纵坐标，反之一样（其实就是记录所有横线、竖线）
排序后二分就可以了，右边的是第一个横坐标比它大的，左边的就是第一个横坐标比它小的
判断死循环，其实当小明第二次，以相同的方向碰到同一个点时，就必然会产生循环
用set记录一下当前经过的障碍状态，每次判断一下是否重复即可 
*/ 

struct Node
{
    int H,W;
};

map<int,vector<int> > Hs;//竖着的
map<int,vector<int> > Ws;//横着的

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
    if(nowPos==0)//右
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
    else if(nowPos==1)//下
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
    else if(nowPos==2)//左
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
    else if(nowPos==3)//上
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
            if(isOk(nowH,nowW,nowPos)==-1)//跑出去了
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
