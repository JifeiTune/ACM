#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

/*
将x分解因子，有几种分法
递归求解，假设后分的因子总是不大于前面的
*/

int ans=0;

void Div(int MIN,int n)
{
    int i;
    for(i=MIN;i<=n&&i<=n/i;i++)//从MIN开始，保证因子不小于之前的，且保证剩下的存在不小于i的因子
    {
        if(n%i==0)
        {
            ans++;
            Div(i,n/i);
        }
    }
}

int main()
{
    int n,temp;
    cin>>n;
    while(n--)
    {
        cin>>temp;
        ans=0;
        Div(2,temp);
        cout<<ans+1<<'\n';//加上无法再分的最后一个
    }

    return 0;
}



