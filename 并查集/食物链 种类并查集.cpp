#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<ctime>
#include<list>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

/*
POJ - 1182 ʳ����

��һ����ٴ�������⣬ԭ�����й�ϵͨ����Ӻ�ȡ�����õ�����̫����⣬���ﻻ��ͨ�õĹ�ϵת������
��ͨ���鼯��ά�����ǵȼ۹�ϵ�������������ӵĹ�ϵ�������ٿ�һ����ϵ����
����ǰ�ڵ���ڴ���Ԫ�Ĺ�ϵ���ڵ���ڵ��Ĺ�ϵ����ͨ���ֱ����м�ڵ�Ĺ�ϵ���õ�
�ٿ�һ����ϵӳ�����鼴��
�������������ϵ��һ�ǡ��Ѿ�ȷ�����໥��ϵ������ͨ�������ܽ��
���Ǿ���Ĺ�ϵ���ԡ����ԡ�ͬ�ࡱ������0��1��2��ʾ
���г��뱻���ǻ����ģ��ı䷽��ʱ����һ�¼��ɣ�0��1ͨ�����1�ɱ䷴

ֵ��һ����ǣ�������cin���ر�ͬ������ʱ���� 
*/
int x[50001];//����Ԫ
int rel[50001];//ָ�����Ԫ�Ĺ�ϵ

int trans[3][3]={{1,2,0},{2,0,1},{0,1,2}};//A����B�Ĺ�ϵΪi��B����C�Ĺ�ϵΪjʱ��A����C�Ĺ�ϵΪtrans[i][j]

int rev(int r)//��ϵȡ��
{
    if(r==2)
    {
        return 2;
    }
    return r^1;
}

int Find(int n)
{
    if(x[n]==n)
    {
        return n;
    }
    else
    {
    	int fa=x[n];//�ȼ�¼���ڵ㣬����·��ѹ������
        x[n]=Find(x[n]);
        rel[n]=trans[rel[n]][rel[fa]];//�ýڵ������Ԫ��ϵ��ͨ�����ڵ�Ϊ�н�õ�
        return x[n];
    }
}

int main()
{
    int i,j,temp,len,ans=0,n,m,f1,f2,op,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        x[i]=i;
        rel[i]=2;//�Լ����Լ���ͬ��
    }
    while(m--)
    {
    	scanf("%d%d%d",&a,&b,&c);
        if(b>n||c>n)
        {
            ans++;
        }
        else
        {
            f1=Find(b);
            f2=Find(c);
            if(a==1)//ͬ��
            {
                if(f1!=f2)//֮ǰ��֪�����߹�ϵ�����Ժϲ�
                {
                    x[f2]=f1;
                    rel[f2]=trans[rev(rel[c])][rel[b]];
                }
                else
                {
                    if(rel[b]!=rel[c])//�Ѿ��й�ϵ���Ҳ���ͬ��
                    {
                        ans++;
                    }
                }
            }
            else//b��c
            {
                if(f1!=f2)//֮ǰ��֪�����߹�ϵ�����Ժϲ�
                {
                    x[f2]=f1;
                    temp=trans[rev(rel[c])][1];//f2��b�Ĺ�ϵ
                    rel[f2]=trans[temp][rel[b]];//f2��f1�Ĺ�ϵ
                }
                else
                {
                    if(trans[rel[b]][rev(rel[c])]!=0)//�Ѿ��й�ϵ���Ҳ���b��c
                    {
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
