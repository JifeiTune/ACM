#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
Manacher算法将原串进行改造成Ma，在每两个字符间插入一个'#'
这样偶数长度的回文串也有了中心字符 
计算后，原串中下标i映射到Ma中2*(i+1)
Mp[j]-1即为原串中以j为中心的最长回文串长度 
如 
abaaba 
i:     0 1 2 3 4 5 6 7 8 9 10 11 12 13 
Ma[i]: $ # a # b # a # a # b  #  a  # 
Mp[i]: 1 1 2 1 4 1 2 7 2 1 4  1  2  1 
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

int main()
{
	
	return 0; 
}
