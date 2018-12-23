#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/*
给定一个n位的数，欲删去其中的m位，问剩下的数最大是多少
相当于从n位中选n-m位，使得选出的数字组成的数最大（需按序）
每次要新加一个数时，从末尾起向前遍历，把小于它的都删去（注意这个过程要留下足够多可选的）
*/

char x[100010];

int main(void)
{
    int m,n,i,j,num;
    char last;
    deque<char> ans;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
        {
            break;
        }
        ans.clear();
        m=n-m;//欲选的个数
        num=m-1;//还要选的个数
        scanf("%s",x);
        ans.push_back(x[0]);//预放一个进去
        for(i=1;i<n;i++)
        {
            if(num==n-i)//没得选择了，都存入
            {
                for(;i<n;i++)
                {
                    ans.push_back(x[i]);
                }
                break;
            }
            if(ans.back()<x[i])//从末尾
            {
                while(!ans.empty()&&ans.back()<x[i]&&num<n-i)//把小于的都删除
                {
                    ans.pop_back();
                    num++;
                }

            }
			ans.push_back(x[i]);//存入
        	num--;
        }
        while(m--)//输出前m位
        {
            putchar(ans.front());
            ans.pop_front();
        }
        putchar('\n');
    }
    return 0;
}

