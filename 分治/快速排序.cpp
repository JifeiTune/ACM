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

void Qs(int be,int ed)//be��ed���������±�Ϊbe
{
    //������Ԫ���ڵ������������ң�ÿ���ҵ��滻��ȱ��������ȱ
    if(ed>be)
    {
        int i=be,j=ed,temp=x[be];
        while(j>i)//��������ʱi==j����Ϊ��ȱԪ��
        {
            while(j>i&&x[j]>=temp) j--;
            x[i]=x[j];
            while(j>i&&x[i]<=temp) i++;
            x[j]=x[i];
        }
        x[i]=temp;//��ʱi==j
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

