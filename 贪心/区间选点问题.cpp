#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

/*
x轴上有一条长度为L的公路，两端有村庄，要在公路上建最少的地铁出口
使得每一个村庄离最近的出口距离不超过D
本质上是区间选点问题，也就是在轴上选最少的点，使得每一个区间内至少有一个点
将所有区间按右端点从小到大排序，右端点相同时左端点从大到小排序
则可以发现，这样最容易被别的区间覆盖的点就是最前面的右端点
每次记录右端点，扫描到区间时看看前面记录的点是否在该区间内
若在不必增加，否则添加右端点

因为x轴上离某个村庄距离小于D的点组成一个区间，所以可以转换为此问题
*/

struct Node
{
    double L,R;
    bool operator<(const Node&r) const
    {
        if(r.R==R)
        {
            return L>r.L;
        }
        return R<r.R;
    }
};

vector<Node> x;

int main(void)
{
    int L,D,n,i,j,k,ans,num;
    double cx,cy,p,last;
    Node tem;
    while(~scanf("%d",&L))
    {
        x.clear();
        scanf("%d%d",&D,&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf",&cx,&cy);
            p=sqrt(D*D-cy*cy);//偏移
            tem.L=cx-p;
            tem.R=cx+p;
            x.push_back(tem);
        }
        sort(x.begin(),x.end());
        last=-1e200;//一个绝对不可能被包含的点
        num=x.size();
        ans=0;
        for(i=0;i<num;i++)
        {
            if(x[i].L>last)//需要添加新的
            {
                ans++;
                last=x[i].R;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

