#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
/*
��6�������Σ��߳���1��6��Ҫ������װ�������κ����У��߳�Ϊ6��
�������ü�������
�ҹ��ɣ�
�߳�Ϊ4��5��6�������α�Ȼ��Ҫ�����ĺ��ӣ�Ȼ��ʣ��Ŀռ���Էű߳�Ϊ1��2��
�߳�Ϊ3�������Σ�ÿ4������Ҫһ�����ӣ�������࣬����Ҫһ�����ӣ���ʱ���пռ��ֿ���װ�߳�Ϊ1��2��
�߳�Ϊ2�������ο���װ4���߳�Ϊ1�ģ����Ȼ�Ϊ�߳�Ϊ2�Ŀ���
*/

int num[7];//ÿ�ֱ߳��м���

int main(void)
{
    bool flag;
    int i,ans,temp,j;
    int one,two;//���ܷű߳�Ϊ1��2�ĸ�����
    while(true)
    {
        ans=0;
        one=0,two=0;
        memset(num,0,sizeof(num));
        flag=1;
        for(i=1;i<=6;i++)
        {
            scanf("%d",&num[i]);
            if(num[i]!=0)
            {
                flag=0;
            }
        }
        if(flag)
        {
            break;
        }
        ans+=num[6]+num[5]+num[4];
        one+=11*num[5];
        two+=5*num[4];//������Ϊ�߳�Ϊ2�Ŀ�λ
        //����߳�Ϊ3��
        ans+=num[3]/4;
        if((temp=num[3]%4)!=0)
        {
            ans++;
            if(temp==3)
            {
                two++;
                one+=5;
            }
            else if(temp==1)
            {
                two+=5;
                one+=7;
            }
            else
            {
                two+=3;
                one+=6;
            }
        }
        //����߳�Ϊ2��
        if(two>=num[2])
        {
            one+=4*(two-num[2]);
        }
        else
        {
            num[2]-=two;
            ans+=num[2]/9;
            if(num[2]%9!=0)
            {
                ans++;
                one+=4*(9-num[2]%9);
            }
        }
        //����߳�Ϊ1��
        if(one<num[1])
        {
            num[1]-=one;
            ans+=num[1]/36;
            if(num[1]%36!=0)
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

