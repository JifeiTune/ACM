#include<iostream>
#include<algorithm>

using namespace std;

/*
R*R的正方形（左下角为(0,0)，右上角为(R,R)）内，有N个矩形岛
每个矩形给定左上角坐标(x,y)，和高H，宽W
所有数都是整数，现在需要求一条竖线，使得其将所有岛分成左右两部分
左边岛的面积和不小于右边，且两边面积和的差尽量小
满足此条件时，要让线尽可能靠右，问线的横坐标

所有岛的面积和是知道的
给定一条竖线，左边岛的面积和也可以求，即扫描一边所有岛
每个岛可能在线左边、右边、跨越左右，分情况处理
所以就可以二分线的位置了
先找第一个使得左边面积和大于等于右边面积和的位置
再找最后一个使得左边面积和不变化的位置
*/
typedef long long LL;
struct Node
{
    LL x,y,H,W;
};

Node all[10001];
int MAX;//R的最大值，即右端点
int num;//岛的个数
LL allArea;//总面积

LL getLeftArea(int mid)//求位于x=mid左边的面积和
{
    int i;
    LL ans=0;
    for(i=1;i<=num;i++)
    {
        if(all[i].x+all[i].W<=mid)//完全在左边
        {
            ans+=all[i].W*all[i].H;
        }
        else if(all[i].x<mid)//跨越左右两部分
        {
            ans+=all[i].H*(mid-all[i].x);
        }
    }
    return ans;
}



int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&MAX,&num);
        allArea=0;
        for(i=1;i<=num;i++)
        {
            scanf("%lld%lld%lld%lld",&all[i].x,&all[i].y,&all[i].W,&all[i].H);
            allArea+=all[i].W*all[i].H;
        }
        int L=0,R=MAX,mid,last,temp,ans;
        while(L<=R)//找第一个使得左边面积和大于等于右边面积和的位置
        {
            mid=(L+R)/2;
            if(2*getLeftArea(mid)>=allArea)
            {
                last=mid;
                if(mid-1>=L&&2*getLeftArea(mid-1)>=allArea)
                {
                    R=mid-1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                L=mid+1;
            }
        }
        temp=getLeftArea(last);
        L=ans+1,R=MAX;
        while(L<=R)//找最后一个左边面积和等于temp的位置
        {
            mid=(L+R)/2;
            if(getLeftArea(mid)==temp)
            {
                last=mid;
                if(mid+1<=R&&getLeftArea(mid+1)==temp)
                {
                    L=mid+1;
                }
                else
                {
                    break;
                }
            }
            else if(getLeftArea(mid)>temp)
            {
                R=mid-1;
            }
            else
            {
                L=mid+1;
            }
        }
        printf("%d\n",last);
    }
    return 0;
}



