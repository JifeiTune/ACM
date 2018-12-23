#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
/*
有6种正方形，边长从1到6，要将它们装入正方形盒子中（边长为6）
问最少用几个盒子
找规律：
边长为4、5、6的正方形必然需要单独的盒子，然后剩余的空间可以放边长为1或2的
边长为3的正方形，每4个就需要一个盒子，如果有余，还需要一个盒子，此时空闲空间又可以装边长为1或2的
边长为2的正方形可以装4个边长为1的，优先化为边长为2的考虑
*/

int num[7];//每种边长有几个

int main(void)
{
    bool flag;
    int i,ans,temp,j;
    int one,two;//还能放边长为1和2的各多少
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
        two+=5*num[4];//优先作为边长为2的空位
        //处理边长为3的
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
        //处理边长为2的
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
        //处理边长为1的
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

