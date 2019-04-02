#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#include<set>
using namespace std;

/*
����һ���ַ��������Ƿ���ɾ������һ���ַ���ʹ��ʣ�µĲ���ΪSS����ʽ����һ���ַ������Ƴ�2��
���S������ʹ��S��Ψһ�����˵��

�ȶ�ԭ��hash�����ǰ׺��
Ȼ��ö��ɾ��λ������ʣ�µ��ַ�����2�ݣ�ÿ�ݲ�ȡ��ͬ��hash
Ҳ������ԭhash�ϵ�����ʹ�ö�ӦλλȨ��ȣ������hash���ж��Ƿ����
�����ж�S��Ψһ�ԣ����������hash��ʽ��ͬ��ÿ�εõ�һ���⣬��hashֵ����set
��setԪ�ظ�������1ʱ��ʾ��Ψһ
*/

char x[2000005];

typedef unsigned int ui;

ui base=131;
ui pre[2000005];
ui pow[2000005];//base^i
set<ui> all;

int main()
{
    int len,i,mid,p=-1;
    ui temp,L,R;
    pow[0]=1;
    scanf("%d%s",&len,x+1);
    if((len&1)==0||len==1)
    {
        puts("NOT POSSIBLE");
        return 0;
    }
    for(i=1;i<=len;i++)
    {
        pow[i]=pow[i-1]*base;
    }
    temp=base;
    pre[0]=x[0];
    for(i=1;i<=len;i++)//����hashλȨС�������
    {
        pre[i]=pre[i-1]+pow[i]*x[i];
    }
    mid=len/2+1;
    for(i=1;i<mid;i++)//��ɾ��λ����벿��
    {
        L=(pre[mid]-pre[i])*pow[mid-1]+pre[i-1]*pow[mid];
        R=pre[len]-pre[mid];
        if(L==R)
        {
            all.insert(R);
            p=i;
            if(all.size()>1)
            {
                puts("NOT UNIQUE");
                return 0;
            }
        }
    }
    L=pre[mid-1]*pow[mid];
    R=pre[len]-pre[mid];
    if(L==R)
    {
        all.insert(R);
        p=mid;
        if(all.size()>1)
        {
            puts("NOT UNIQUE");
            return 0;
        }
    }
    for(i=mid+1;i<=len;i++)
    {
        L=pre[mid-1]*pow[mid];
        R=(pre[i-1]-pre[mid-1])*base+(pre[len]-pre[i]);
        if(L==R)
        {
            all.insert(R);
            p=i;
            if(all.size()>1)
            {
                puts("NOT UNIQUE");
                return 0;
            }
        }
    }
    if(p==-1)
    {
        printf("NOT POSSIBLE");
        return 0;
    }
    --mid;
    for(i=1;i<=len&&mid!=0;i++)
    {
        if(i!=p)
        {
            putchar(x[i]);
            --mid;
        }
    }
    return 0;
}
