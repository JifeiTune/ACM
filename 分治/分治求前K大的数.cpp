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
���ǰk�����
ֱ��ȫ������Ч�ʵͣ���Ϊ��������Ҳ����

ģ����ŵĹ��̣�ʹ�����ἰ�ұ�Ԫ�ظ���Ϊk
�ٵ������ⲿ�����򼴿�
*/

int x[100001];

void Qs(int be,int ed,int k)//ʹ�����ἰ�ұ�Ԫ�ظ���Ϊk
{
    if(ed>be)
    {
        int i=be,j=ed,temp=x[be],num;
        while(j>i)//��������ʱi==j����Ϊ��ȱԪ��
        {
            while(j>i&&x[j]>=temp) j--;
            x[i]=x[j];
            while(j>i&&x[i]<=temp) i++;
            x[j]=x[i];
        }
        x[i]=temp;//��ʱi==j
        num=ed-i+1;
        if(num<k)//����
        {
            Qs(be,i-1,k-num);//�������������ȱʧ��
        }
        else if(num>k)//����
        {
            Qs(i+1,ed,k);//�������ұ߼�����
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int T,i,num,k;
    cin>>num;
    for(i=1;i<=num;i++)
    {
        cin>>x[i];
    }
    cin>>k;
    Qs(1,num,k);
    sort(x+1+num-k,x+1+num);
    for(i=num;i>=1+num-k;i--)
    {
        cout<<x[i]<<'\n';
    }
    return 0;
}

