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
��ż����3��Nλ���м�����
һλһλ���ƣ�ÿ����λ�������ұ�
ż�������������໥ת��
*/

int Odd[1001];//Odd[i]��ʾiλ���к�ż����3��������
int Even[1001];

#define MOD 12345

int main()
{
    int i,n;
    cin>>n;
    Odd[1]=1;//������3����ô�������3
    Even[1]=8;//��ȥ0��3
    for(i=2;i<=n;i++)
    {
        Even[i]=(Odd[i-1]+Even[i-1]*9)%MOD;//ԭ��������3������ĩλ��3������ԭ��ż����3����ĩλ����3
        Odd[i]=(Even[i-1]+Odd[i-1]*9)%MOD;//ԭ��ż����3����ĩλ��3������ԭ��������3����ĩλ����3
    }
    cout<<Even[n];
    return 0;
}




