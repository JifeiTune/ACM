#include<cstdio>
#include<cstring>
/*
问串x中，串y出现了几次，出现的不同位置可重叠
当然可以用KMP，但这次用hash来做 
hash快，是因为字符串本身就可以看做一个?进制数
如果直接比较，是“按位的”，但hash成一个数后，直接按值比较，一次就行
所以对原串和匹配串取同一个hash方法，即每一位分别乘上相同的位权，最后比较是否相等
当然原串不可能每次重新求，用个前缀和保存，每次相减，得到xk*(h^k)+x(k+1)*(h^(k+1))……
而模式串，一开始是y0*(h^0)+y1*(h^1)+y2*(h^2)……，每次比较后再乘上h，就能得到同一套hash 

一切都可自然溢出，即使是求前缀和时的减
*/

char x[1000001];//被匹配
char y[1000001];
unsigned int pre[1000001]={0};//x0*(h^0)+x1*(h^1)+x2*(h^2)……的前缀和
unsigned int hs;
int lenx,leny;

int Cal()
{
    int ans=0,i,base=131;
    unsigned int temp=base,sum=0;
    pre[0]=x[0];
    for(i=1;i<lenx;i++)
    {
        pre[i]=pre[i-1]+x[i]*temp;
        temp*=base;
    }
    temp=1;
    for(i=0;i<leny;i++)
    {
        sum+=y[i]*temp;
        temp*=base;
    }
    for(i=leny-1;i<lenx;i++)//开始分段匹配
    {
        if(sum==(pre[i]-pre[i-leny]))
        {
            ++ans;
        }
        sum*=base;
    }
    return ans;
}

int main()
{
    gets(x),gets(y);
    lenx=strlen(x);
    leny=strlen(y);
    printf("%d",Cal());
    return 0;
}
