#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<list>
#include<cmath>
#include<stack>

using namespace std;
/*
上台阶，每次只能走1或2或3步
问上n级台阶有几种上法
其实就是特殊的隔板 
*/ 
long long x[72];

int main()
{
    ios::sync_with_stdio(false);
    int n,num,i,j,temp,last;
    memset(x,0,sizeof(x));
    x[1]=x[2]=x[3]=1;
    for(i=1;i<=71;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(i+j<=71)
            {
                x[i+j]+=x[i];
            }
        }
    }

    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        cout<<x[n]<<'\n';
    }
    return 0;
}



