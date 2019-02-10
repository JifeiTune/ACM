#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<list>
#include<cmath>
#include<stack>

using namespace std;

/*
含偶数个3的N位数有几个？
一位一位递推，每次新位加在最右边
偶数个与奇数个相互转化
*/

int Odd[1001];//Odd[i]表示i位数中含偶数个3的数个数
int Even[1001];

#define MOD 12345

int main()
{
    int i,n;
    cin>>n;
    Odd[1]=1;//奇数个3，那么本身就是3
    Even[1]=8;//除去0和3
    for(i=2;i<=n;i++)
    {
        Even[i]=(Odd[i-1]+Even[i-1]*9)%MOD;//原先奇数个3，现在末位补3，或者原先偶数个3，现末位补非3
        Odd[i]=(Even[i-1]+Odd[i-1]*9)%MOD;//原先偶数个3，现末位补3，后者原先奇数个3，现末位补非3
    }
    cout<<Even[n];
    return 0;
}




