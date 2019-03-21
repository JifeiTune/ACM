#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<queue>
#include<vector>

using namespace std;

/*
已知集合第一个元素为base
若x在集合里，则2x+1、3x+1都在集合里
将这个集合中元素从小到大排列，问第N（达1e6）个值为多少，注意是集合，元素去重 

每一个新生成的元素，都能再生成2x+1、3x+1两个元素，如此反复……
想要维护一个序列并使之升序，将2x+1、3x+1混在一起是做不到的，因为较小值的3x+1可能比较大值的2x+1大 
注意到，2x+1和3x+1是递增的，如果分开放，就能实现单调增长 
于是可用设置2个队列，一个存2x+1生成的值，一个存3x+1生成的值
每次都从2者队头取较小值，若相等则都取但只算一个，然后将2x+1和3x+1计算的值分别放至队尾
这样就能动态更新两个单调的队列，并用之生成另一个单调序列，类似归并排序的合并操作
取到第N个，其值即为答案 
*/ 

typedef long long LL;

queue<LL> two;
queue<LL> three;

int main()
{
    ios::sync_with_stdio(false);
    LL n,i,j,k,ans,base,last;
    while(cin>>base>>n)
    {
        while(!two.empty())
        {
            two.pop();
        }
        while(!three.empty())
        {
            three.pop();
        }
        two.push(2*base+1);
        three.push(3*base+1);
        n--;
        last=base;
        while(n--)
        {
            if(two.front()<three.front())
            {
                last=two.front();
                two.pop();
            }
            else if(two.front()>three.front())
            {
                last=three.front();
                three.pop();
            }
            else
            {
                 last=two.front();
                 two.pop();
                 three.pop();
            }
            two.push(2*last+1);
            three.push(3*last+1);
        }
        cout<<last<<'\n';
    }
    return 0;
}



