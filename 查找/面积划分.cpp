#include<iostream>
#include<algorithm>

using namespace std;

/*
R*R�������Σ����½�Ϊ(0,0)�����Ͻ�Ϊ(R,R)���ڣ���N�����ε�
ÿ�����θ������Ͻ�����(x,y)���͸�H����W
����������������������Ҫ��һ�����ߣ�ʹ���佫���е��ֳ�����������
��ߵ�������Ͳ�С���ұߣ�����������͵Ĳ��С
���������ʱ��Ҫ���߾����ܿ��ң����ߵĺ�����

���е����������֪����
����һ�����ߣ���ߵ��������Ҳ�����󣬼�ɨ��һ�����е�
ÿ��������������ߡ��ұߡ���Խ���ң����������
���ԾͿ��Զ����ߵ�λ����
���ҵ�һ��ʹ���������ʹ��ڵ����ұ�����͵�λ��
�������һ��ʹ���������Ͳ��仯��λ��
*/
typedef long long LL;
struct Node
{
    LL x,y,H,W;
};

Node all[10001];
int MAX;//R�����ֵ�����Ҷ˵�
int num;//���ĸ���
LL allArea;//�����

LL getLeftArea(int mid)//��λ��x=mid��ߵ������
{
    int i;
    LL ans=0;
    for(i=1;i<=num;i++)
    {
        if(all[i].x+all[i].W<=mid)//��ȫ�����
        {
            ans+=all[i].W*all[i].H;
        }
        else if(all[i].x<mid)//��Խ����������
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
        while(L<=R)//�ҵ�һ��ʹ���������ʹ��ڵ����ұ�����͵�λ��
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
        while(L<=R)//�����һ���������͵���temp��λ��
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



