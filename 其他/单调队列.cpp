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
��֪���ϵ�һ��Ԫ��Ϊbase
��x�ڼ������2x+1��3x+1���ڼ�����
�����������Ԫ�ش�С�������У��ʵ�N����1e6����ֵΪ���٣�ע���Ǽ��ϣ�Ԫ��ȥ�� 

ÿһ�������ɵ�Ԫ�أ�����������2x+1��3x+1����Ԫ�أ���˷�������
��Ҫά��һ�����в�ʹ֮���򣬽�2x+1��3x+1����һ�����������ģ���Ϊ��Сֵ��3x+1���ܱȽϴ�ֵ��2x+1�� 
ע�⵽��2x+1��3x+1�ǵ����ģ�����ֿ��ţ�����ʵ�ֵ������� 
���ǿ�������2�����У�һ����2x+1���ɵ�ֵ��һ����3x+1���ɵ�ֵ
ÿ�ζ���2�߶�ͷȡ��Сֵ���������ȡ��ֻ��һ����Ȼ��2x+1��3x+1�����ֵ�ֱ������β
�������ܶ�̬�������������Ķ��У�����֮������һ���������У����ƹ鲢����ĺϲ�����
ȡ����N������ֵ��Ϊ�� 
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



