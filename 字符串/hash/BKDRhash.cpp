#include<stdio.h>
#include<set>

using namespace std;

/*
BKDRhash，就是一种多项式hash
一个字符串本身就可以看做是个?进制数
现在可让其基数乘上一个质数k，位权就依次乘上
k^0、k^1、k^2…… 

*/ 

char x[201];
set<unsigned int> vis;
char op[10];

void BKDRhash(unsigned int *ans)
{
	char *p=x;
	*ans=0;
	while(*p)
	{
		(*ans)+=(*p);
		(*ans)*=11331;
		++p;
	}
}

int main()
{
    int len,i,n,cas=0;
	unsigned int hs;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s ",op);
        fgets(x,201,stdin);
        BKDRhash(&hs);
        if((*op)=='a')
        {
            vis.insert(hs);
        }
        else
        {

            if(vis.find(hs)!=vis.end())
            {
                puts("yes");
            }
            else
            {
                puts("no");
            }
        }
    }
	return 0;
}
