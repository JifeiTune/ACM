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
#include<queue>

using namespace std;

int x[100001];

void Qs(int be,int ed)//be到ed排序，枢轴下标为be
{
    //将枢轴元素挖掉，右左右左找，每次找到替换空缺，最后填补空缺
    if(ed>be)
    {
        int i=be,j=ed,temp=x[be];
        while(j>i)//这样结束时i==j，且为空缺元素
        {
            while(j>i&&x[j]>=temp) j--;
            x[i]=x[j];
            while(j>i&&x[i]<=temp) i++;
            x[j]=x[i];
        }
        x[i]=temp;//此时i==j
        Qs(be,i-1);
        Qs(i+1,ed);
    }
}

#define num 100

int main()
{
    ios::sync_with_stdio(false);
    int T,i;
    for(i=1;i<=num;i++)
    {
        x[i]=rand();
    }
    Qs(1,num);
    for(i=1;i<=num;i++)
    {
        cout<<x[i]<<'\n';
    }
    return 0;
}

