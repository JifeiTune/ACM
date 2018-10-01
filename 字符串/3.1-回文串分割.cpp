#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
一个字符串，由26个字母组成，每个字母有一个权值
现在将它分成2个子串（不能是空串），为回文串的子串，可以获得其权值和
问最大权值和
Manacher算法，枚举分割点 
*/
using namespace std;

const int MAXN=500010; 

char Ma[MAXN*2]; 
int Mp[MAXN*2];

void Manacher(char s[],int len){ 
     int l=0; 
     Ma[l++]='$'; 
     Ma[l++]='#'; 
     for(int i=0;i<len;i++){ 
          Ma[l++]=s[i]; 
          Ma[l++]='#'; 
     } 
     Ma[l]=0; 
     int mx=0,id=0; 
     for(int i=0;i<l;i++){ 
          Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1; 
          while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++; 
          if(i+Mp[i]>mx){ 
              mx=i+Mp[i]; 
              id=i; 
          } 
     } 
} 

int val[26];
char S[MAXN];
int pre[MAXN];//val前缀和 

int main()
{
	int T,i,j,n,k,ans,tem,len;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		for(i=0;i<26;i++)
		{
			scanf("%d",&val[i]);	
		}
		scanf("%s",S);
		len=strlen(S);
		//特判长度为1
		if(len==1)
		{
			printf("0\n");
			continue;	
		} 
		Manacher(S,len);
		pre[0]=val[S[0]-'a']; 
		for(i=1;i<len;i++)
		{
			pre[i]=pre[i-1]+val[S[i]-'a'];
		}
		for(i=0;i<len-1;i++)
		{
			tem=0;
			if( Mp[(2+2*(i+1))/2]-1 ==i+1 )//左边OK 
			{
				tem+=pre[i];
			}
			if( Mp[(2*(i+2)+2*len)/2]-1 ==len-i-1 )//右边OK 
			{
				tem+=pre[len-1]-pre[i];
			}
			ans=max(ans,tem);
		}
		printf("%d\n",ans);
	} 
	return 0; 
}
