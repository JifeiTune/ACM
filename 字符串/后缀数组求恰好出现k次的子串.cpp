#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
/*
height数组范围为2-len，使用时，特判输入串为1的情况

每个子串必然为原串某个后缀的前缀
相同的子串，必然在height数组对应后缀中相邻
*/
const int MAXN=100001;//字符串最长长度
const int LOG=((int)log2(MAXN))+1;//RMQ数组二维
int t1[MAXN],t2[MAXN],c[MAXN];//求sa数组需要的中间变量，不需要赋值
int len;//字符串实际长度

//计B[i]为str以下标i开始的后缀
char str[MAXN];//原字符串
int sa[MAXN];//sa[i]表示字典序第i小的为B[i]，1<=i<=len
int Rank[MAXN];//Rank[i]表示B[i]是第Rank[i]小的，为sa的逆，0<=i<=len-1
int height[MAXN];//height[i]表示sa[i]对应的后缀与sa[i-1]对应的后缀，最长公共前缀为height[i]，2<=i<=len
int RMQ[MAXN][LOG];//height数组的RMQ

bool cmp(int *r,int a,int b,int l){
     return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(char str[],int sa[],int Rank[],int height[],int n,int m){//基数排序，m需大于最大字符
     n++;
     int i, j, p, *x = t1, *y = t2;
     //第一轮基数排序，如果 s 的最大值很大，可改为快速排序
     for(i = 0;i < m;i++)c[i] = 0;
     for(i = 0;i < n;i++)c[x[i] = str[i]]++;
     for(i = 1;i < m;i++)c[i] += c[i-1];
     for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
     for(j = 1;j <= n; j <<= 1){
          p = 0;
          //直接利用 sa 数组排序第二关键字
          for(i = n-j; i < n; i++)y[p++] = i;//后面的 j 个数第二关键字为空的最小
          for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] -  j;
          //这样数组 y 保存的就是按照第二关键字排序的结果
          //基数排序第一关键字
          for(i = 0; i < m; i++)c[i] = 0;
          for(i = 0; i < n; i++)c[x[y[i]]]++;
          for(i = 1; i < m;i++)c[i] += c[i-1];
          for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
          //根据 sa 和 x 数组计算新的 x 数组
          swap(x,y);
          p = 1; x[sa[0]] = 0;
          for(i = 1;i < n;i++)
              x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
          if(p >= n)break;
          m = p;//下次基数排序的最大值
     }
     int k = 0;
     n--;
     for(i = 0;i <= n;i++)Rank[sa[i]] = i;
     for(i = 0;i < n;i++){
          if(k)k--;
          j = sa[Rank[i]-1];
          while(str[i+k] == str[j+k])k++;
          height[Rank[i]] = k;
     }
}

void initRMQ()
{
    int f=(int)log2(len)+1,i,j;
	for(i=2;i<=len;i++)
	{
		RMQ[i][0]=height[i];//以i开头长度为2^0的最值当然是自己
	}
	for(j=1;j<=f;j++)
	{
		for(i=2;i+(1<<j)-1<=len;i++)//注意范围，右坐标未超出数组下标才有计算的意义
		{
			RMQ[i][j]=min(RMQ[i][j-1],RMQ[i+(1<<(j-1))][j-1]);//划分成长度相等的两个子区间
		}
	}
}

int askRMQ(int i,int j)//求height数组[i,j]中最值，注意2<=i<=j<=len
{
    int k=(int)log2(j-i+1);
	return min(RMQ[i][k],RMQ[j-(1<<k)+1][k]);
}

int lcp(int a,int b){//求B[a]和B[b]的最长公共前缀长度，下标范围0到len-1
	if(a==b)
	{
		return len-a;
	}
    a=Rank[a];b=Rank[b];
    if(a>b) swap(a,b);
    return askRMQ(a+1,b);
}

/*
求长度恰为k的子串个数
维护height数组中长为k-1的区间最小值MIN（即区间lcp）
说明有长度为MIN的子串出现了至少k次
此时再向两边扩展，设两边的height值的较大值为MAX
若MAX>=MIN，说明长度小于等于MIN的子串还能再出现，也就是个数超过了k次
若MAX<MIN说明有MIN-MAX种子串，只能在当前区间出现，即出现次数恰为k
需特判k==1的情况
*/
int getNum(int k)
{
    int i,ans=0,MIN,MAX;
    if(k==1)
    {
        for(i=1;i<=len;i++)//一个一个后缀来看
        {
            MIN=len-sa[i];//字典序第i小的后缀长度
            MAX=max(i==1?0:height[i],i==len?0:height[i+1]);
            if(MIN>MAX)
            {
                ans+=MIN-MAX;
            }
        }
        return ans;
    }
    k--;
    for(i=2;i<=len-k+1;i++)
    {
        MIN=askRMQ(i,i+k-1);
        MAX=max(i==2?0:height[i-1],i+k-1==len?0:height[i+k]);
        if(MIN>MAX)
        {
            ans+=MIN-MAX;
        }
    }
    return ans;
}

int main()
{
    /*
    len = strlen(str);
    da(str,sa,Rank,height,len,128);
    initRMQ();
    */
    int T,k,L,R,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s",&k,str);
        len = strlen(str);
        if(len==1)
        {
            if(k==1)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
            continue;
        }
        da(str,sa,Rank,height,len,128);
        initRMQ();
        printf("%d\n",getNum(k));
    }
	return 0;
}

