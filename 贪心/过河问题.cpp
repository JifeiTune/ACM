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

/*
过河问题，N个人过河，一艘船（故需考虑撑回），最多载2人
过河时间由速度慢的人决定，问总的最短时间

当N<=3时，答案是固定的，考虑>3时
每次考虑将速度最慢的两人送到对岸
这样考虑是因为我们可以想到，两个最慢的人一起过河，再由别人撑回，可能能节省大量时间
所以有2种方案：
1、最快的人分2次带最慢的2人过去
2、最快的人带次快的过去，回来后，最慢的2人一起过去，再由次快的人撑回
不断再二者中选取最优即可
*/

vector<int> all;

int sum(int n)
{
    int i,ans=0;
    if(n==1||n==2)
    {
        return all[n-1];
    }
    else if(n==3)
    {
        return (all[0]+all[1]+all[2]);
    }
    else
    {
        while(n>=4)
        {
            ans+=min(all[n-1]+all[n-2]+2*all[0],all[n-1]+2*all[1]+all[0]);//2种方案取最优
            n-=2;
        }
        ans+=sum(n);
        return ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int T,n,i,j,k,ans,temp;
    cin>>T;
    while(T--)
    {
        all.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            all.push_back(temp);
        }
        sort(all.begin(),all.end());
        cout<<sum(n)<<'\n';
    }
    return 0;
}

