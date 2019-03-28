#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
/*
height���鷶ΧΪ2-len��ʹ��ʱ���������봮Ϊ1�����

ÿ���Ӵ���ȻΪԭ��ĳ����׺��ǰ׺
��ͬ���Ӵ�����Ȼ��height�����Ӧ��׺������
*/
const int MAXN=100001;//�ַ��������
const int LOG=((int)log2(MAXN))+1;//RMQ�����ά
int t1[MAXN],t2[MAXN],c[MAXN];//��sa������Ҫ���м����������Ҫ��ֵ
int len;//�ַ���ʵ�ʳ���

//��B[i]Ϊstr���±�i��ʼ�ĺ�׺
char str[MAXN];//ԭ�ַ���
int sa[MAXN];//sa[i]��ʾ�ֵ����iС��ΪB[i]��1<=i<=len
int Rank[MAXN];//Rank[i]��ʾB[i]�ǵ�Rank[i]С�ģ�Ϊsa���棬0<=i<=len-1
int height[MAXN];//height[i]��ʾsa[i]��Ӧ�ĺ�׺��sa[i-1]��Ӧ�ĺ�׺�������ǰ׺Ϊheight[i]��2<=i<=len
int RMQ[MAXN][LOG];//height�����RMQ

bool cmp(int *r,int a,int b,int l){
     return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(char str[],int sa[],int Rank[],int height[],int n,int m){//��������m���������ַ�
     n++;
     int i, j, p, *x = t1, *y = t2;
     //��һ�ֻ���������� s �����ֵ�ܴ󣬿ɸ�Ϊ��������
     for(i = 0;i < m;i++)c[i] = 0;
     for(i = 0;i < n;i++)c[x[i] = str[i]]++;
     for(i = 1;i < m;i++)c[i] += c[i-1];
     for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
     for(j = 1;j <= n; j <<= 1){
          p = 0;
          //ֱ������ sa ��������ڶ��ؼ���
          for(i = n-j; i < n; i++)y[p++] = i;//����� j �����ڶ��ؼ���Ϊ�յ���С
          for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] -  j;
          //�������� y ����ľ��ǰ��յڶ��ؼ�������Ľ��
          //���������һ�ؼ���
          for(i = 0; i < m; i++)c[i] = 0;
          for(i = 0; i < n; i++)c[x[y[i]]]++;
          for(i = 1; i < m;i++)c[i] += c[i-1];
          for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
          //���� sa �� x ��������µ� x ����
          swap(x,y);
          p = 1; x[sa[0]] = 0;
          for(i = 1;i < n;i++)
              x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
          if(p >= n)break;
          m = p;//�´λ�����������ֵ
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
		RMQ[i][0]=height[i];//��i��ͷ����Ϊ2^0����ֵ��Ȼ���Լ�
	}
	for(j=1;j<=f;j++)
	{
		for(i=2;i+(1<<j)-1<=len;i++)//ע�ⷶΧ��������δ���������±���м��������
		{
			RMQ[i][j]=min(RMQ[i][j-1],RMQ[i+(1<<(j-1))][j-1]);//���ֳɳ�����ȵ�����������
		}
	}
}

int askRMQ(int i,int j)//��height����[i,j]����ֵ��ע��2<=i<=j<=len
{
    int k=(int)log2(j-i+1);
	return min(RMQ[i][k],RMQ[j-(1<<k)+1][k]);
}

int lcp(int a,int b){//��B[a]��B[b]�������ǰ׺���ȣ��±귶Χ0��len-1
	if(a==b)
	{
		return len-a;
	}
    a=Rank[a];b=Rank[b];
    if(a>b) swap(a,b);
    return askRMQ(a+1,b);
}

/*
�󳤶�ǡΪk���Ӵ�����
ά��height�����г�Ϊk-1��������СֵMIN��������lcp��
˵���г���ΪMIN���Ӵ�����������k��
��ʱ����������չ�������ߵ�heightֵ�Ľϴ�ֵΪMAX
��MAX>=MIN��˵������С�ڵ���MIN���Ӵ������ٳ��֣�Ҳ���Ǹ���������k��
��MAX<MIN˵����MIN-MAX���Ӵ���ֻ���ڵ�ǰ������֣������ִ���ǡΪk
������k==1�����
*/
int getNum(int k)
{
    int i,ans=0,MIN,MAX;
    if(k==1)
    {
        for(i=1;i<=len;i++)//һ��һ����׺����
        {
            MIN=len-sa[i];//�ֵ����iС�ĺ�׺����
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

