#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

/*
x������һ������ΪL�Ĺ�·�������д�ׯ��Ҫ�ڹ�·�Ͻ����ٵĵ�������
ʹ��ÿһ����ׯ������ĳ��ھ��벻����D
������������ѡ�����⣬Ҳ����������ѡ���ٵĵ㣬ʹ��ÿһ��������������һ����
���������䰴�Ҷ˵��С���������Ҷ˵���ͬʱ��˵�Ӵ�С����
����Է��֣����������ױ�������串�ǵĵ������ǰ����Ҷ˵�
ÿ�μ�¼�Ҷ˵㣬ɨ�赽����ʱ����ǰ���¼�ĵ��Ƿ��ڸ�������
���ڲ������ӣ���������Ҷ˵�

��Ϊx������ĳ����ׯ����С��D�ĵ����һ�����䣬���Կ���ת��Ϊ������
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
            p=sqrt(D*D-cy*cy);//ƫ��
            tem.L=cx-p;
            tem.R=cx+p;
            x.push_back(tem);
        }
        sort(x.begin(),x.end());
        last=-1e200;//һ�����Բ����ܱ������ĵ�
        num=x.size();
        ans=0;
        for(i=0;i<num;i++)
        {
            if(x[i].L>last)//��Ҫ����µ�
            {
                ans++;
                last=x[i].R;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

